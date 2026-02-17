cmake_minimum_required(VERSION 3.20)
project(pocket_log VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ── Output dirs ──────────────────────────────────────────────────────────────
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ── Find packages ────────────────────────────────────────────────────────────
find_package(PkgConfig REQUIRED)

# Crow (header-only; installed via vcpkg or system)
find_package(Crow CONFIG QUIET)
if(NOT Crow_FOUND)
    find_path(CROW_INCLUDE_DIR crow.h PATHS /usr/local/include /usr/include)
    if(CROW_INCLUDE_DIR)
        add_library(Crow::Crow INTERFACE IMPORTED)
        target_include_directories(Crow::Crow INTERFACE ${CROW_INCLUDE_DIR})
    else()
        message(FATAL_ERROR "Crow not found. Install with: vcpkg install crow")
    endif()
endif()

# libpqxx
find_package(libpqxx CONFIG QUIET)
if(NOT libpqxx_FOUND)
    pkg_check_modules(PQXX REQUIRED libpqxx)
endif()

# nlohmann/json
find_package(nlohmann_json CONFIG REQUIRED)

# OpenSSL (for JWT & TLS)
find_package(OpenSSL REQUIRED)

# jwt-cpp (header-only)
find_path(JWT_CPP_INCLUDE_DIR jwt-cpp/jwt.h PATHS /usr/local/include /usr/include)
if(NOT JWT_CPP_INCLUDE_DIR)
    message(FATAL_ERROR "jwt-cpp not found. Install with: vcpkg install jwt-cpp")
endif()

# Boost (uuid, asio used by Crow)
find_package(Boost REQUIRED COMPONENTS system)

# spdlog (fast logging)
find_package(spdlog CONFIG REQUIRED)

# ── Source files ──────────────────────────────────────────────────────────────
file(GLOB_RECURSE SOURCES
        src/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${JWT_CPP_INCLUDE_DIR}
        ${PQXX_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Crow::Crow
        nlohmann_json::nlohmann_json
        OpenSSL::SSL
        OpenSSL::Crypto
        Boost::system
        spdlog::spdlog
        pthread
)

if(libpqxx_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE libpqxx::pqxx)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE ${PQXX_LIBRARIES})
    target_include_directories(${PROJECT_NAME} PRIVATE ${PQXX_INCLUDE_DIRS})
endif()

# ── Compiler flags ─────────────────────────────────────────────────────────
target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:-g -O0 -Wall -Wextra -Wpedantic -fsanitize=address>
        $<$<CONFIG:Release>:-O3 -DNDEBUG>
        $<$<CONFIG:RelWithDebInfo>:-O2 -g>
        $<$<CONFIG:MinSizeRel>:-Os -DNDEBUG>
)

target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:-fsanitize=address>
)

# ── Tests ─────────────────────────────────────────────────────────────────
option(BUILD_TESTS "Build test suite" OFF)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# ── Install ───────────────────────────────────────────────────────────────
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(DIRECTORY config/ DESTINATION etc/pocket_log)
install(DIRECTORY migrations/ DESTINATION share/pocket_log/migrations)
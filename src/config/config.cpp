#include "../../include/config/config.h"

#include <fstream>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;
using json   = nlohmann::json;

// ─────────────────────────────────────────────
//  Singleton
// ─────────────────────────────────────────────

Config& Config::instance() {
    static Config inst;
    return inst;
}

// ─────────────────────────────────────────────
//  Public: load
// ─────────────────────────────────────────────

void Config::load(const std::string& config_dir) {
    const fs::path dir{config_dir};

    if (!fs::is_directory(dir))
        throw std::runtime_error("Config directory not found: " + config_dir);

    // ── app.json ──────────────────────────────
    auto app_json = load_json_file((dir / "app.json").string());
    parse_app(app_json);
    raw_.merge_patch(app_json);

    // ── database.json ─────────────────────────
    auto db_json = load_json_file((dir / "database.json").string());
    parse_database(db_json);
    raw_.merge_patch(db_json);

    // ── jwt.json ──────────────────────────────
    auto jwt_json = load_json_file((dir / "jwt.json").string());
    parse_jwt(jwt_json);
    raw_.merge_patch(jwt_json);

    // ── config.json (optional overrides) ──────
    const fs::path override_path = dir / "config.json";
    if (fs::exists(override_path)) {
        auto overrides = load_json_file(override_path.string());
        raw_.merge_patch(overrides);

        // Re-parse sections that may have been overridden
        if (overrides.contains("app"))      parse_app(overrides["app"]);
        if (overrides.contains("database")) parse_database(overrides["database"]);
        if (overrides.contains("jwt"))      parse_jwt(overrides["jwt"]);
    }

    loaded_ = true;
}

// ─────────────────────────────────────────────
//  Private helpers
// ─────────────────────────────────────────────

json Config::load_json_file(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("Cannot open config file: " + path);

    try {
        return json::parse(file, /*cb=*/nullptr, /*allow_exceptions=*/true,
                           /*ignore_comments=*/true);
    } catch (const json::parse_error& e) {
        throw std::runtime_error("JSON parse error in " + path + ": " + e.what());
    }
}

// ── parse_app ─────────────────────────────────

void Config::parse_app(const json& j) {
    // Support flat  {"name": ...}  and nested  {"app": {"name": ...}}
    const json& a = j.contains("app") ? j["app"] : j;

    if (a.contains("name"))      app_.name      = a["name"].get<std::string>();
    if (a.contains("version"))   app_.version   = a["version"].get<std::string>();
    if (a.contains("host"))      app_.host      = a["host"].get<std::string>();
    if (a.contains("port"))      app_.port      = a["port"].get<int>();
    if (a.contains("debug"))     app_.debug     = a["debug"].get<bool>();
    if (a.contains("log_level")) app_.log_level = a["log_level"].get<std::string>();
    if (a.contains("tls_cert"))  app_.tls_cert  = a["tls_cert"].get<std::string>();
    if (a.contains("tls_key"))   app_.tls_key   = a["tls_key"].get<std::string>();
}

// ── parse_database ────────────────────────────

void Config::parse_database(const json& j) {
    const json& d = j.contains("database") ? j["database"] : j;

    if (d.contains("host"))                db_.host                = d["host"].get<std::string>();
    if (d.contains("port"))                db_.port                = d["port"].get<int>();
    if (d.contains("name"))                db_.name                = d["name"].get<std::string>();
    if (d.contains("user"))                db_.user                = d["user"].get<std::string>();
    if (d.contains("password"))            db_.password            = d["password"].get<std::string>();
    if (d.contains("pool_size"))           db_.pool_size           = d["pool_size"].get<int>();
    if (d.contains("connect_timeout_sec")) db_.connect_timeout_sec = d["connect_timeout_sec"].get<int>();
    if (d.contains("ssl"))                 db_.ssl                 = d["ssl"].get<bool>();
}

// ── parse_jwt ─────────────────────────────────

void Config::parse_jwt(const json& j) {
    const json& t = j.contains("jwt") ? j["jwt"] : j;

    if (t.contains("secret"))                   jwt_.secret                   = t["secret"].get<std::string>();
    if (t.contains("algorithm"))                jwt_.algorithm                = t["algorithm"].get<std::string>();
    if (t.contains("access_token_expiry_sec"))  jwt_.access_token_expiry_sec  = t["access_token_expiry_sec"].get<int>();
    if (t.contains("refresh_token_expiry_sec")) jwt_.refresh_token_expiry_sec = t["refresh_token_expiry_sec"].get<int>();
    if (t.contains("issuer"))                   jwt_.issuer                   = t["issuer"].get<std::string>();
    if (t.contains("audience"))                 jwt_.audience                 = t["audience"].get<std::string>();
}
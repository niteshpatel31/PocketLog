# Expense Manager Backend (C++ + Crow)
## 📁 Project Structure

```text
expense-manager-backend/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── .env.example
│
├── config/                       # Runtime configuration (NOT compiled)
│   ├── app.json                  # server port, env, logging
│   ├── database.json             # DB credentials
│   └── jwt.json                  # JWT secret, expiry
│
├── include/
│   ├── app/                      # App bootstrap & routing
│   │   ├── Application.h
│   │   └── Router.h
│
│   ├── controllers/              # HTTP layer (Crow routes)
│   │   ├── AuthController.h
│   │   ├── ExpenseController.h
│   │   ├── CategoryController.h
│   │   ├── UserController.h
│   │   └── ReportController.h
│
│   ├── services/                 # Business logic layer
│   │   ├── AuthService.h
│   │   ├── ExpenseService.h
│   │   ├── CategoryService.h
│   │   ├── UserService.h
│   │   └── ReportService.h
│
│   ├── repositories/             # Database access layer
│   │   ├── UserRepository.h
│   │   ├── ExpenseRepository.h
│   │   ├── CategoryRepository.h
│   │   └── ReportRepository.h
│
│   ├── models/                   # Domain models
│   │   ├── BaseModel.h
│   │   ├── User.h
│   │   ├── Expense.h
│   │   └── Category.h
│
│   ├── dto/                      # API request / response contracts
│   │   ├── AuthDTO.h
│   │   ├── ExpenseDTO.h
│   │   ├── CategoryDTO.h
│   │   ├── UserDTO.h
│   │   └── ReportDTO.h
│
│   ├── middleware/               # Crow middlewares
│   │   ├── AuthMiddleware.h      # JWT validation
│   │   ├── CorsMiddleware.h
│   │   ├── RateLimitMiddleware.h
│   │   └── ValidationMiddleware.h
│
│   ├── database/
│   │   ├── Database.h            # DB connection wrapper
│   │   ├── ConnectionPool.h
│   │   └── MigrationRunner.h
│
│   ├── security/
│   │   ├── JWTHelper.h
│   │   └── PasswordHasher.h
│
│   ├── utils/
│   │   ├── Logger.h
│   │   ├── TimeUtils.h
│   │   ├── Validator.h
│   │   ├── ResponseBuilder.h
│   │   └── UUID.h
│
│   └── common/
│       ├── Constants.h
│       └── ErrorCodes.h
│
├── src/
│   ├── main.cpp                  # Entry point
│
│   ├── app/
│   │   ├── Application.cpp
│   │   └── Router.cpp
│
│   ├── controllers/
│   ├── services/
│   ├── repositories/
│   ├── models/
│   ├── dto/
│   ├── middleware/
│   ├── database/
│   ├── security/
│   └── utils/
│
├── migrations/                   # SQL migrations
│   ├── 001_users.sql
│   ├── 002_categories.sql
│   ├── 003_expenses.sql
│   └── 004_indexes.sql
│
├── tests/
│   ├── unit/
│   │   ├── services/
│   │   ├── repositories/
│   │   └── utils/
│   ├── integration/
│   │   ├── api/
│   │   └── database/
│   └── CMakeLists.txt
│
├── scripts/
│   ├── build.sh
│   ├── run_dev.sh
│   ├── migrate.sh
│   └── deploy.sh
│
├── docker/
│   ├── Dockerfile
│   ├── docker-compose.yml
│   └── nginx/
│       └── nginx.conf
│
└── logs/
    └── app.log

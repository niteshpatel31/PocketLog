#pragma once

#include <string>
#include <stdexcept>
#include <nlohmann/json.hpp>

// ─────────────────────────────────────────────
//  Sub-config structs
// ─────────────────────────────────────────────

struct AppConfig {
    std::string name;
    std::string version;
    std::string host;
    int         port{8080};
    bool        debug{false};
    std::string log_level{"info"};
    std::string tls_cert;   // path to cert (.pem)
    std::string tls_key;    // path to key  (.pem)
};

struct DatabaseConfig {
    std::string host{"localhost"};
    int         port{5432};
    std::string name;
    std::string user;
    std::string password;
    int         pool_size{10};
    int         connect_timeout_sec{30};
    bool        ssl{false};
};

struct JwtConfig {
    std::string secret;
    std::string algorithm{"HS256"};
    int         access_token_expiry_sec{3600};   // 1 h
    int         refresh_token_expiry_sec{604800}; // 7 d
    std::string issuer;
    std::string audience;
};

// ─────────────────────────────────────────────
//  Config – singleton loader
// ─────────────────────────────────────────────

class Config {
public:
    /// Returns the singleton instance.
    static Config& instance();

    /// Load all JSON config files from `config_dir` (default: "config/").
    /// Throws std::runtime_error on missing required fields or bad JSON.
    void load(const std::string& config_dir = "config");

    // ── Accessors ──────────────────────────────
    const AppConfig&      app()      const { return app_; }
    const DatabaseConfig& database() const { return db_; }
    const JwtConfig&      jwt()      const { return jwt_; }

    /// Raw access to the merged config tree (all files merged).
    const nlohmann::json& raw() const { return raw_; }

    bool is_loaded() const { return loaded_; }

private:
    Config() = default;
    Config(const Config&)            = delete;
    Config& operator=(const Config&) = delete;

    static nlohmann::json load_json_file(const std::string& path);

    void parse_app(const nlohmann::json& j);
    void parse_database(const nlohmann::json& j);
    void parse_jwt(const nlohmann::json& j);

    AppConfig      app_;
    DatabaseConfig db_;
    JwtConfig      jwt_;
    nlohmann::json raw_;
    bool           loaded_{false};
};
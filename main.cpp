#define CROW_ENABLE_SSL

#include<iostream>
#include<crow.h>
#include"util/date_time.h"
#include"dao/transaction.cpp"

constexpr char SSL_CERT_FILE[] = "../secret/localhost+3.pem";
constexpr char SSL_CERT_KEY[] = "../secret/localhost+3-key.pem";
constexpr char endl = '\n';

static auto l = crow::logger(crow::LogLevel::INFO);

std::string transactionSimul(bool det);

std::string readFile(std::string const &fileName);

void run_server() {
    crow::App<> app;
    CROW_ROUTE(app, "/")([]() {
        return R"(<h1>Pocket Log </h1>
                    <a href="/trct">transaction details</a>
                    <br/>
                    <a href="/trctf">full transaction details</a>
                    <br/>
                    <a href="/login">Login</a>)";
    });

    CROW_ROUTE(app, "/priyesh")([]() {
        return "<h1> Priyesh Vishwakarma </h1>";
    });

    CROW_ROUTE(app, "/trct")([]() {
        return transactionSimul(false);
    });
    CROW_ROUTE(app, "/trctf")([]() {
        return transactionSimul(true);
    });

    CROW_ROUTE(app, "/login")([]() {
        return readFile("../static/login.html");
    });

    app.port(5100)
            .bindaddr("192.168.1.9")
            .multithreaded()
            .ssl_file(SSL_CERT_FILE, SSL_CERT_KEY)
            .run_async();
    return;
}

static Transaction t(current_time_and_date().c_str(),
                     24.45,
                     Category{FOOD},
                     Account("Central Bank Of India", AccountType{DEBIT_CARD}, 789.89, "9340220138"),
                     TransactionType{EXPENSE}
);

std::string readFile(std::string const &fileName) {
    std::ifstream file(fileName);
    std::stringstream ss;
    ss << file.rdbuf();
    std::system("clear");
    return ss.str();
}

std::string transactionSimul(bool det = false) {
    return (det) ? t.getTransactionFullDetails() : t.getTransactionDetails();
}

int main(int argc, const char *argv[]) {
    run_server();
    return EXIT_SUCCESS;
}

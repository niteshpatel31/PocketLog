#include<iostream>
#include<crow.h>
#include"util/date_time.h"
#include"dao/transaction.cpp"

constexpr char endl = '\n';

std::string transactionSimul(bool det);

void run_server() {
    crow::App<> app;
    CROW_ROUTE(app, "/")([]() {
        return R"(<h1>Pocket Log </h1>
                    <a href="/trct">transaction details</a>
                    <br/>
                    <a href="/trctf">full transaction details</a>
                    <br/>
                    <a href="/date">Date</a>)";
    });

    CROW_ROUTE(app, "/priyesh")([]() {
        return "<h1> Priyesh Vishwakarma </h1>";
    });

    CROW_ROUTE(app, "/date")([]() {
        return "<h1>" + current_time_and_date() + "</h1>";
    });

    CROW_ROUTE(app, "/trct")([]() {
        return transactionSimul(false);
    });
    CROW_ROUTE(app, "/trctf")([]() {
        return transactionSimul(true);
    });

    app.port(5100)
            .multithreaded()
            .ssl_file("../localhost+3.pem", "../localhost+3-key.pem")
            .run();
    return;
}

static Transaction t(current_time_and_date().c_str(),
                     24.45,
                     Category{FOOD},
                     Account("Central Bank Of India", AccountType{DEBIT_CARD}, 789.89, "9340220138"),
                     TransactionType{EXPENSE}
);

std::string transactionSimul(bool det = false) {
    return "<h1>" + ((det) ? t.getTransactionFullDetails() : t.getTransactionDetails()) + "</h1>";
}

int main(int argc, const char *argv[]) {
    run_server();
    return EXIT_SUCCESS;
}

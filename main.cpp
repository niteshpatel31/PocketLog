#include<iostream>
#include<crow.h>
#include"util/date_time.h"
#include"dao/transaction.cpp"
constexpr char endl = '\n';

std::string transactionSimul();

void run_server() {
    crow::App<> app;
    CROW_ROUTE(app, "/")([]() {
        return R"(<h1> Prashant Tripathi </h1>
                    <a href="/priyesh">Priyesh</a>
                    <br>
                    <a href="/trct">transaction</a>
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
        return transactionSimul();
    });

    app.port(5100).multithreaded().run();
    return;
}

std::string transactionSimul() {
    Transaction t(current_time_and_date(),
                  24.45,
                  Category{FOOD},
                  Account("Central Bank Of India", AccountType{UPI}, 789.89, "9340220138"),
                  TransactionType{EXPENSE}
    );
    return t.getTranscationDetails();
}

int main(int argc, const char *argv[]) {
    run_server();
    return EXIT_SUCCESS;
}

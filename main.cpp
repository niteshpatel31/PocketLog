#include<iostream>
#include<crow.h>
#include"util/date_time.h"
constexpr char endl = '\n';

void run_server() {
    crow::App<> app;
    CROW_ROUTE(app, "/")([]() {
        return R"(<h1> Prashant Tripathi </h1>
                    <a href="/priyesh">Priyesh</a>
                    <br>
                    <a href="/date">Date</a>)";
    });

    CROW_ROUTE(app, "/priyesh")([]() {
        return "<h1> Priyesh Vishwakarma </h1>";
    });

    CROW_ROUTE(app, "/date")([]() {
        return "<h1>" + current_time_and_date() + "</h1>";
    });

    app.port(5100).multithreaded().run();
    return;
}

int main(int argc, const char *argv[]) {
    run_server();
    return EXIT_SUCCESS;
}

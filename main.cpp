#include<iostream>
#include<crow.h>
constexpr char endl = '\n';

void run_server() {
    crow::App<> app;
    CROW_ROUTE(app, "/")([]() {
        return "<h1> Prashant Tripathi </h1> <a href=\"/priyesh\"> priyesh</a>";
    });

    CROW_ROUTE(app, "/priyesh")([]() {
        return "<h1> Priyesh Vishwakarma </h1>";
    });

    app.port(5100).multithreaded().run();
    return;
}

int main(int argc, const char *argv[]) {
    run_server();
    return EXIT_SUCCESS;
}

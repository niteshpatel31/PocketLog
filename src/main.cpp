#define CROW_ENABLE_SSL
#include <crow.h>
#include "../include/models/transaction.h"
#include "../include/utils/time_util.h"

constexpr char SSL_CERT_FILE[]{"../secret/localhost+3.pem"};
constexpr char SSL_CERT_KEY[]{"../secret/localhost+3-key.pem"};
constexpr char addr[]{"0.0.0.0"};
constexpr uint64_t port{5100};
constexpr char endl[] = "\n";

int main(int argc, char *argv[]) {
    crow::App<> app;

    Account account("93402201238", AccountType{UPI}, "Airtel Payments Bank", 678.89);
    CROW_ROUTE(app, "/")([]() {
        return R"(<h1>Pocket Log</h1>
                <a href="/account">account</a> <br/>
                <a href="transaction">transaction</a> <br/>
)";
    });

    CROW_ROUTE(app, "/account")([account]() {
        return account.getAccountName() + endl +
               account.getAccountNumber() + endl +
               account.getAccountType() + endl;
    });

    app
            .bindaddr(addr)
            .port(port)
            .ssl_file(SSL_CERT_FILE, SSL_CERT_KEY)
            .multithreaded()
            .run_async();
    return EXIT_SUCCESS;
}

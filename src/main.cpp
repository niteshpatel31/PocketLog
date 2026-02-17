#define CROW_ENABLE_SSL
#include <crow.h>
#include "../include/models/transaction.h"
#include "../include/utils/time_util.h"

constexpr char SSL_CERT_FILE[]{"../secret/localhost+3.pem"};
constexpr char SSL_CERT_KEY[]{"../secret/localhost+3-key.pem"};
constexpr char addr[]{"0.0.0.0"};
constexpr uint64_t port{5100};
constexpr char endl[] = "\n";

Account account("93402201238", AccountType{UPI}, "Airtel Payments Bank", 678.89);
Transaction transaction(TransactionType{EXPENSE}, Category{STATIONARY}, "Bought Pen & Pencils for exam",
                        "1 pack of 12 pencils & 1 pack of 13 Houser XO pens", 156.97, account);
template<typename T>
auto anyToStr = [](T t) {
    std::stringstream ss;
    ss << t;
    return ss.str();
};

int main(int argc, char *argv[]) {
    crow::App<> app;

    CROW_ROUTE(app, "/")([]() {
        return R"(<h1>Pocket Log</h1>
                <a href="/account">account</a> <br/>
                <a href="transaction">transaction</a> <br/>
)";
    });

    CROW_ROUTE(app, "/account")([]() {
        return account.getAccountName() + endl +
               account.getAccountNumber() + endl +
               "Rs." + anyToStr<float>(account.getAccountBalance()) + endl +
               account.getAccountType() + endl;
    });

    CROW_ROUTE(app, "/transaction")([]() {
        const Account account = transaction.getTransactionAccount();
        const auto accountDetails =
                account.getAccountName() + endl +
                account.getAccountNumber() + endl +
                anyToStr<std::string>(account.getAccountName()) + endl +
                account.getAccountType() + endl;
        return
                anyToStr<uint64_t>(transaction.getId()) + endl +
                BaseModel::timeToStr(transaction.getCreatedAt()) + endl +
                transaction.getTransactionNote() + endl +
                "Rs." + anyToStr<float>(transaction.getTransactionAmount()) + endl +
                static_cast<char>(transaction.getTransactionCategory() + 48) + endl +
                static_cast<char>(transaction.getTransactionType() + 48) + endl +
                transaction.getTransactionDescription() + endl +
                account.getAccountName();
    });

    CROW_ROUTE(app, "/<string>")([](auto a) { return "<h1>" + a + "</h1>";});

    app
            .bindaddr(addr)
            .port(port)
            .ssl_file(SSL_CERT_FILE, SSL_CERT_KEY)
            .multithreaded()
            .run_async();
    return EXIT_SUCCESS;
}

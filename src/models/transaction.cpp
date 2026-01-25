//
// Created by sloth on 1/24/26.
//

#include "../include/transaction.h"

#include "../utils/date_time.h"


struct Account {
public:
    std::string name;
    std::string account_no;
    AccountType accountType;
    float balance;

    Account(std::string _name, AccountType _accountType, float _balance, const std::string _account_no) : name(_name),
        accountType(_accountType), balance(_balance), account_no(_account_no) {
    }

    std::string accountDetails() {
        std::stringstream amt;
        amt << std::setprecision(2) << std::fixed << this->balance;
        return name + "\n" + account_no + "\n" + getAccountType() + "\n" + amt.str();
    }

    std::string getAccountType() {
        switch (accountType) {
            case AccountType{DEBIT_CARD}:
                return "Debit Card";
            case AccountType{CREDIT_CARD}:
                return "Credit Card";
            case AccountType{CASH}:
                return "Cash";
            case AccountType{WALLET}:
                return "Wallet";
            case AccountType{UPI}:
                return "UPI";
            default:
                return "Invalid";
        }
    }
};

class Transaction {
private:
    std::string dateTime;
    float amount;
    Category category;
    Account account;
    TransactionType type;
    std::string note;
    std::string description;
    // FIXME : Image binary member

public:
    Transaction(std::string _dateTime, float _amount, Category _category, Account _account,
                TransactionType _type) : dateTime(_dateTime), amount(_amount), category(_category),
                                         account(_account), type(_type) {
    }

    // FIXME : PARSE JSON
    std::string getTransactionFullDetails() {
        std::stringstream ss;
        ss << std::setprecision(2) << std::fixed << this->amount;
        return dateTime + "\n" + ss.str() + "\n" + char(category + 48) + "\n" + account.accountDetails() + "\n" +
               char(this->type + 48) + "\n" +
               this->note + "\n" +
               this->description;
    }

    // std::string getTransactionCategory() const {
    //     switch (category) {
    //         case Category{FOOD}:
    //             return "Food";
    //         case Category{FOOD}:
    //             return "Food";
    //         case Category{FOOD}:
    //             return "Food";
    //         case Category{FOOD}:
    //             return "Food";
    //     }
    // }

    std::string getTransactionDetails() {
        std::stringstream ss;
        ss << std::setprecision(2) << std::fixed << amount;
        return dateTime + "\n" + ss.str() + "\n" + "\n" + account.getAccountType();
    }

    float getAmount() const {
        return this->amount;
    }
};

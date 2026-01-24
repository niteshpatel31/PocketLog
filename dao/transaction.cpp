//
// Created by sloth on 1/24/26.
//

#include "transaction.h"

#include "../util/date_time.h"


struct Account {
public:
    std::string name;
    std::string account_no;
    AccountType accountType;
    float balance;

    Account(std::string _name, AccountType _accountType, float _balance, const std::string _account_no) : name(_name),
        accountType(_accountType), balance(_balance), account_no(_account_no) {
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
                TransactionType _type) : dateTime(_dateTime), amount(_amount), category(_category), account(_account), type(_type) {
    }

    // FIXME : PARSE JSON
    std::string getTranscationDetails() const {
        std::stringstream ss;
        ss << std::setprecision(2) << this->amount;
        return dateTime + "\n" + ss.str() + "\n" + char(category) + "\n" + account.name + "\n" + this->note + "\n" +
               this->description;
    }

    float getAmount() const {
        return this->amount;
    }
};

//
// Created by sloth on 1/24/26.
//

#include "../../include/models/transaction.h"

Account::Account(std::string _accountNumber, AccountType _accountType, std::string _accountName,
                 float _accountBalance) : BaseModel(random(), random(), random()), accountName(_accountName),
                                          accountBalance(_accountBalance),
                                          accountNumber(_accountNumber), accountType(_accountType) {
}

std::string Account::getAccountNumber() const { return this->accountNumber; }
std::string Account::getAccountName() const { return this->accountName; }
float Account::getAccountBalance() const { return this->accountBalance; }


std::string Account::getAccountType() const {
    switch (this->accountType) {
        case AccountType{UPI}:
            return "UPI";
        case AccountType{DEBIT_CARD}:
            return "DEBIT_CARD";
        case AccountType{CASH}:
            return "CASH";
        case AccountType{WALLET}:
            return "WALLET";
        case AccountType{CREDIT_CARD}:
            return "CREDIT_CARD";
        default:
            return "INVALID";
    };
}

void Account::setAccountNumber(std::string _accountNumber) { this->accountNumber = _accountNumber; }
void Account::setAccountName(std::string _accountName) { this->accountName = _accountName; }
void Account::setAccountBalance(float _accountBalance) { this->accountBalance = _accountBalance; }
void Account::setAccountType(AccountType _accountType) { this->accountType = _accountType; }

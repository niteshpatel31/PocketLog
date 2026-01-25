//
// Created by sloth on 1/24/26.
//

#ifndef POCKETLOG_TRANSACTION_H
#define POCKETLOG_TRANSACTION_H
#include<chrono>
#include<string>
#include "../models/base_model.h"

enum TransactionType { INCOME, EXPENSE, TRANSFER };

enum Category { FOOD, GROCERY, SOCIAL_LIFE, BEVERAGES, CLEANING, KITCHEN, STATIONARY, ENTERTAINMENT, FUEL, GAMING, };

enum AccountType { DEBIT_CARD, CREDIT_CARD, UPI, CASH, WALLET };


class Account : BaseModel{
private:
    std::string accountName;
    AccountType accountType;
    std::string accountNumber;
    float accountBalance;

public:
    Account(std::string _accountNumber, AccountType _accountType, std::string _accountName, float _accountBalance);

    std::string getAccountNumber();

    std::string getAccountType();

    std::string getAccountName();

    float getAccountBalance();
};


class Transaction {
private:
    TransactionType transactionType;
    Category category;
    std::string note;
    std::string description;
    Account* account;
    float amount;
public:

};
#endif //POCKETLOG_TRANSACTION_H

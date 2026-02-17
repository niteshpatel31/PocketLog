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


class Account : public BaseModel {
private:
    std::string accountName;
    AccountType accountType;
    std::string accountNumber;
    float accountBalance;

public:
    Account() = default;

    Account(std::string _accountNumber, AccountType _accountType, std::string _accountName, float _accountBalance);

    std::string getAccountNumber() const;

    std::string getAccountType() const;

    std::string getAccountName() const;

    float getAccountBalance() const;

    void setAccountBalance(float _balance);

    void setAccountNumber(std::string _accountNumber);

    void setAccountType(AccountType _accountType);

    void setAccountName(std::string _accountName);
};


class Transaction : public BaseModel {
private:
    TransactionType transactionType;
    Category transactionCategory;
    std::string transactionNote;
    std::string transactionDescription;
    Account transactionAccount;
    float transactionAmount;

public:
    Transaction() = default;

    Transaction(TransactionType _transactionType, Category _category, std::string _note, std::string _description,
                float _amount, Account _account);

    TransactionType getTransactionType() const;

    Category getTransactionCategory() const;

    std::string getTransactionNote() const;

    std::string getTransactionDescription() const;

    float getTransactionAmount() const;

    Account getTransactionAccount() const;

    void setTransactionNote(const std::string &_note);

    void setTransactionCategory(const Category &_category);

    void setTransactionDescription(const std::string &_description);

    void setTransactionAmount(const float &_amount);

    void setTransactionAccount(const Account &_account);

    void setTransactionType(const TransactionType &_transactionType);
};
#endif //POCKETLOG_TRANSACTION_H

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


class Transaction : BaseModel {
private:
    TransactionType transactionType;
    Category transactionCategory;
    std::string transactionNote;
    std::string transactionDescription;
    Account *transactionAccount;
    float transactionAmount;

public:
    Transaction(TransactionType _transactionType, Category _category, std::string _note, std::string _description,
                float _amount, Account *_account);

    TransactionType getTransactionType();

    Category getTransactionCategory();

    std::string getTransactionNote();

    std::string getTransactionDescription();

    float getTransactionAmount();

    Account *getTransactionAccount();

    void setTransactionNote(std::string _note);

    void setTransactionCategory(Category _category);

    void setTransactionDescription(std::string _description);

    void setTransactionAmount(float _amount);

    void setTransactionAccount(Account *_transactionAccount);

    void setTransactionType(TransactionType _transactionType);
};
#endif //POCKETLOG_TRANSACTION_H

//
// Created by sloth on 1/24/26.
//

#include "../../include/models/transaction.h"

//          # Account Handelling

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


//      # Transaction Handelling

Transaction::Transaction(TransactionType _transactionType, Category _category, std::string _note,
                         std::string _description, float _amount, Account _account)
    : transactionType(_transactionType), transactionAccount(_account), transactionCategory(_category),
      transactionDescription(_description), transactionAmount(_amount), transactionNote(_note) {
}

Account Transaction::getTransactionAccount() const { return this->transactionAccount; }
float Transaction::getTransactionAmount() const { return this->transactionAmount; }
std::string Transaction::getTransactionNote() const { return this->transactionNote; }
std::string Transaction::getTransactionDescription() const { return this->transactionDescription; }
Category Transaction::getTransactionCategory() const { return this->transactionCategory; }
TransactionType Transaction::getTransactionType() const { return this->transactionType; }

void Transaction::setTransactionType(const TransactionType &_transactionType) {
    this->transactionType = _transactionType;
}

void Transaction::setTransactionAccount(const Account &_account) { this->transactionAccount = _account; }
void Transaction::setTransactionCategory(const Category &_category) { this->transactionCategory = _category; }
void Transaction::setTransactionNote(const std::string &_note) { this->transactionNote = _note; }

void Transaction::setTransactionDescription(const std::string &_description) {
    this->transactionDescription = _description;
}

void Transaction::setTransactionAmount(const float &_amount) { this->transactionAmount = _amount; }

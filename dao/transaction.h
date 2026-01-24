//
// Created by sloth on 1/24/26.
//

#ifndef POCKETLOG_TRANSACTION_H
#define POCKETLOG_TRANSACTION_H
#include<chrono>
#include<string>

enum TransactionType { INCOME, EXPENSE, TRANSFER };

enum Category { FOOD, GROCERY, SOCIAL_LIFE, BEVERAGES, CLEANING, KITCHEN, STATIONARY, ENTERTAINMENT, FUEL, GAMING, };

enum AccountType { DEBIT_CARD, CREDIT_CARD, UPI, CASH, WALLET };


class Transaction;
class Account;

#endif //POCKETLOG_TRANSACTION_H

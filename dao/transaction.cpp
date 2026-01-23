//
// Created by sloth on 1/24/26.
//

#include "transaction.h"

#include "../util/date_time.h"

class Transaction {
private:
    DateTime dateTime;
    float amount;
    Category category;
    Account account;
    std::string note;
    std::string description;

};

#include "../../include/utils/time_util.h"

DateTime::DateTime() : date_time(current_time_and_date()) {
}

std::string DateTime::getDateTime() const {
    return this->date_time;
}

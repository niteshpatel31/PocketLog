//
// Created by sloth on 1/24/26.
//
// Source - https://stackoverflow.com/a/17223443
// Posted by bames53, modified by community. See post 'Timeline' for change history
// Retrieved 2026-01-24, License - CC BY-SA 4.0
#pragma once

#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string

// TODO : fix the low escape
inline std::string current_time_and_date() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}


class DateTime {
private:
    std::string date_time;
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;

public:
    DateTime();

    [[nodiscard]] std::string getDateTime() const;

    // [[nodiscard]] std::string getYear() const { return std::to_string(year); }
    // [[nodiscard]] std::string getMonth() const { return std::to_string(month); }
    // [[nodiscard]] std::string getDay() const { return std::to_string(day); }
    // [[nodiscard]] std::string getHour() const { return std::to_string(hour); }
    // [[nodiscard]] std::string getMinute() const { return std::to_string(minute); }
    // [[nodiscard]] std::string getSecond() const { return std::to_string(second); }
};

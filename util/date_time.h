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
    ss << std::put_time(std::localtime(&in_time_t), "%Y_%m_%d %X");
    return ss.str();
}


class DateTime {
private:
    std::string date_time;
    // uint16_t year;
    // uint8_t month;
    // uint8_t day;
    // uint8_t hour;
    // uint8_t minute;
    // uint8_t second;

public:
    DateTime(const std::string time = current_time_and_date()) : date_time(time) {
    };
    ~DateTime() { delete this; };
    // FIXME: Fix the Constructor to getdate and time individual elements
    // DateTime() {
    //     std::stringstream ss;
    //     auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    //     ss << std::put_time(std::localtime(&now), "%Y%m%d%X");
    //     date_time = ss.str();
    //     year = std::stoi(date_time.substr(0, 4));
    //     month = std::stoi(date_time.substr(4, 2));
    //     day = std::stoi(date_time.substr(6, 2));
    //     hour = std::stoi(date_time.substr(8, 2));
    //     minute = std::stoi(date_time.substr(11, 2));
    //     second = std::stoi(date_time.substr(13, 2));
    // }
    //
    [[nodiscard]] std::string getDateTime() const { return date_time; }
    // [[nodiscard]] std::string getYear() const { return std::to_string(year); }
    // [[nodiscard]] std::string getMonth() const { return std::to_string(month); }
    // [[nodiscard]] std::string getDay() const { return std::to_string(day); }
    // [[nodiscard]] std::string getHour() const { return std::to_string(hour); }
    // [[nodiscard]] std::string getMinute() const { return std::to_string(minute); }
    // [[nodiscard]] std::string getSecond() const { return std::to_string(second); }
};

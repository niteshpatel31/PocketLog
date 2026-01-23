//
// Created by sloth on 1/24/26.
//
// Source - https://stackoverflow.com/a/17223443
// Posted by bames53, modified by community. See post 'Timeline' for change history
// Retrieved 2026-01-24, License - CC BY-SA 4.0

#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string

class DateTime {
private:
    std::string date_time;
};

std::string current_time_and_date()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

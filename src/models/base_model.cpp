//
// Created by sloth on 1/26/26.
//

#include "../../include/models/base_model.h"

BaseModel::BaseModel() : id(random()),
                         created_at(BaseModel::strToTime(current_time_and_date())),
                         update_at(BaseModel::strToTime(current_time_and_date())) {
}

BaseModel::BaseModel(uint64_t _id, std::time_t _created_at, std::time_t _update_at) : id(_id), created_at(_created_at),
    update_at(_update_at) {
}

uint64_t BaseModel::getId() const { return this->id; }
std::time_t BaseModel::getCreatedAt() const { return this->created_at; }
std::time_t BaseModel::getUpdatedAt() const { return this->update_at; }

void BaseModel::setId(uint64_t _id) { id = _id; }
void BaseModel::setCreatedAt(std::time_t _created_at) { this->created_at = _created_at; }
void BaseModel::setUpdateAt(std::time_t _update_at) { this->update_at = _update_at; }

void BaseModel::touch() { this->update_at = std::time(nullptr); }

const std::string BaseModel::timeToStr(const std::time_t _time) {
    std::tm *tm{std::gmtime(&_time)};
    std::stringstream ss;
    ss << std::put_time(tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

const std::time_t BaseModel::strToTime(const std::string _time) {
    std::tm tm{}; // creating ptr without memory is worthless leads to -> SIGSEGV 139
    std::istringstream ss{_time};
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    return (ss.fail()) ? 0 : std::mktime(&tm);
}

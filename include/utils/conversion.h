//
// Created by sloth on 1/26/26.
//

#ifndef POCKETLOG_CONVERSION_H
#define POCKETLOG_CONVERSION_H
#include <iosfwd>
#include <string>
#include <sstream>

namespace conversion {
    template <typename T>
    std::string anyToStr(T t) {
        std::stringstream ss;
        ss << t;
        return ss.str();
    }
}

#endif //POCKETLOG_CONVERSION_H
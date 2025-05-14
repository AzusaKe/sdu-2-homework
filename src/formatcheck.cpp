//
// Created by Azusa_Ke on 25-5-14.
//

#include "formatcheck.h"
#include<regex>
#include<string>

bool is_valid_date(const std::string& date) {
    regex pattern(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$)");
    return regex_match(date, pattern);
}


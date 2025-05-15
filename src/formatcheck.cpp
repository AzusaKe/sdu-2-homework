//
// Created by Azusa_Ke on 25-5-14.
//

#include "formatcheck.h"
using namespace std;

bool is_valid_time(const string& time) {
    regex pattern(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])\s([01]\d|2[0-3]):([0-5]\d)$)");
    if (!regex_match(time, pattern)) {
            return false;
        }
        // 进一步解析并校验时间有效性
    int year, month, day, hour, minute;
    char dash1, dash2, space, colon;
    stringstream ss(time);
    ss >> year >> dash1 >> month >> dash2 >> day >> space >> hour >> colon >> minute;
    if (dash1 != '-' || dash2 != '-' || space != ' ' || colon != ':') {
        return false;
    }
    // 校验日期
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (is_leap_year && month == 2) {
        days_in_month[1] = 29;
    }
    if (month < 1 || month > 12 || day < 1 || day > days_in_month[month - 1]) {
        return false;
    }
    // 校验时间
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        return false;
    }
    return true;
}

bool is_valid_date(const string& date) {
    regex pattern(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$)");
    smatch match;
    if (!regex_match(date, match, pattern)) {
        return false;
    }
    /*进行日期逻辑检查*/
    int year,month,day;
    char dash;
    stringstream ss(date);
    ss >> year >> dash >> month >> dash >> day;
    //检查天数是否正确
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month < 1 ||month > 12) {
        return false;
    }
    bool is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (is_leap_year && month == 2) {
        days_in_month[1] = 29;
    }
    return day >= 1 && day <= days_in_month[month - 1];
}

bool is_valid_month(const string& month) {
    regex pattern(R"(^\d{4}-(0[1-9]|1[0-2])$)");
    if (!regex_match(month, pattern)) {
            return false;
    }
    int year, mon;
    char dash;
    stringstream ss(month);
    ss >> year >> dash >> mon;
    if (dash != '-' || mon < 1 || mon > 12) {
        return false;
    }
    return true;
}


//
// Created by Azusa_Ke on 25-5-14.
//

#ifndef FORMATCHECK_H
#define FORMATCHECK_H
#include<string>
#include<sstream>
#include<regex>
using namespace std;

bool is_valid_time(const string& time);
bool is_valid_date(const string& date);
bool is_valid_month(const string& month);
bool is_valid_priority(const int& priority);

#endif //FORMATCHECK_H

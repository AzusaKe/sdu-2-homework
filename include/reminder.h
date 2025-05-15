//
// Created by Azusa_Ke on 25-5-13.
//

#ifndef REMINDER_H
#define REMINDER_H

#include"notebasic.h"
#include<vector>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include <string>

using namespace std;

class reminder : public notebasic {
private:
    struct event {
        string time;
        string content;
        int priority;
    };
    vector<event> entries;
    vector<event> search_result;
public:
    void load_from_file(const string &filepath) override;
    void save_to_file(const string &filepath) override;
    void display(const string&) override;
    void search(const string& month) override;
    void sort() override;
    //string get_type() const override;

    void add_entry(const string& time,const string& content,const int& priority);
    void init() override;
    void close() override;

};

#endif //REMINDER_H

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
public:
    struct event {
        string time;
        string content;
        int priority;
    };
private:
    string current_date;
    vector<event> entries;
    vector<event> search_result;
    vector<event> old_entries;
    bool is_in_index;
    string file_path = "./data/reminder.txt";
    string old_file_path = "./data/old_reminder.txt";
public:
    reminder();
    ~reminder();
    void load_from_file() override;
    void save_to_file() override;
    void display(const string&) override;
    void search(const string& month) override;
    void sort() override;
    void get_current_date();
    void add_old_entries();
    //string get_type() const override;

    void add_entry(const string& time,const string& content,const int& priority);
    void init() override;
    void close() override;

};

#endif //REMINDER_H

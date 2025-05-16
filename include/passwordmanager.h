//
// Created by Azusa_Ke on 25-5-13.
//

#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include"notebasic.h"
#include<vector>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include <string>

using namespace std;

class passwordmanager : public notebasic {
private:
    struct record {
        string site_name;
        string username;
        string password;
    };
    struct search_record {
        string site_name;
        string username;
        string password;
        double similarity;
    };
    vector<record> entries;
    vector<search_record> search_result;
    string key;
public:
    void load_from_file(const string &filepath) override;
    void save_to_file(const string &filepath) override;
    void display(const string&) override;
    void search(const string& site_name) override;
    void sort() override;
    string decoder(const string& this_password);//解密函数
    string encoder(const string& this_password);//加密函数
    //string get_type() const override;

    bool is_already_exist(const string& site_name,const string& username,const string& password);
    void add_entry(const string& site_name,const string& username,const string& password);
    void init() override;
    void close() override;
};

#endif //PASSWORDMANAGER_H

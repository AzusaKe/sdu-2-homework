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
public:
    struct record {
        string site_name;
        string username;
        string password;
    };
private:
    struct search_record {
        string site_name;
        string username;
        string password;
        double similarity;
    };
    vector<record> entries;
    vector<search_record> search_result;
    string key;
    string correct_key_sha_256;
    bool is_new_user = false;
    string file_path = "./data/password.txt";
public:
    passwordmanager();
    ~passwordmanager();
    void load_from_file() override;
    void save_to_file() override;
    void display(const string&) override;
    void search(const string& site_name) override;
    void sort() override;
    string decoder(const string& this_password);//普通解密函数
    string encoder(const string& this_password);//普通加密函数
    vector<search_record> operator=(const vector<record> & entries);
    //string get_type() const override;

    bool is_already_exist(const string& site_name,const string& username,const string& password);
    bool is_correct_key(const string & tested_key);
    void add_entry(const string& site_name,const string& username,const string& password);
    void init() override;
    void close() override;

    bool is_new_user_flag() const;
    void set_correct_key_sha_256(string key);

    //临时测hi用
    //void set_key(const string& k);
};

#endif //PASSWORDMANAGER_H

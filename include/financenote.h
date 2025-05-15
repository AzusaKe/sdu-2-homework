//
// Created by Azusa_Ke on 25-5-13.
//

#ifndef FINANCENOTE_H
#define FINANCENOTE_H

#include"notebasic.h"
#include<vector>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include <string>

using namespace std;

class financenote : public notebasic {
private:
    struct entry {
        string date;//日期
        double amount;//金额
        string category;//类别
    };
    vector<entry> entries;//创建向量用于存储记录
    vector<entry> search_result;
public:
    void load_from_file(const string &filepath) override;//从文件加载，继承自基类
    void save_to_file(const string &filepath) override;//保存到文件，继承自基类
    void display(const string&) override;//显示，继承自基类
    void search(const string& month) override;//搜索，继承自基类
    //string get_type() const override;//获取类别，继承自基类

    void add_entry(const string& date,double amount,const string& category);//添加记录
    void init() override;
    void close() override;

};

#endif //FINANCENOTE_H

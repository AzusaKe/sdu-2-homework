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
public:
    struct entry {
        string date;//日期
        double amount;//金额
        string category;//类别
    };//定义结构体用于存储每条记录
private:
    vector<entry> entries;//创建向量用于存储记录
    vector<entry> search_result;
    string file_path = "./data/finance.txt";
public:

    financenote();
    ~financenote();
    void load_from_file() override;//从文件加载，继承自基类
    void save_to_file() override;//保存到文件，继承自基类
    void display(const string&) override;//显示，继承自基类
    void search(const string& month) override;//搜索，继承自基类
    void sort() override;//按日期排序
    vector<entry> get_search_result(); //获取搜索结果
    //string get_type() const override;//获取类别，继承自基类

    void add_entry(const string& date,double amount,const string& category);//添加记录
    void init() override;
    void close() override;

};

#endif //FINANCENOTE_H

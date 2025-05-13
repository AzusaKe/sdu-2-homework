//
// Created by Azusa_Ke on 25-5-13.
//

#include"notebasic.h"
#include "financenote.h"

void financenote::load_from_file(const string &filepath) {//文件加载函数
    entries.clear();//清除之前内存里的记录
    ifstream file(filepath);//获取文件路径
    if (!file.is_open()) {//检测文件是否可读
        cerr << "无法打开目标文件：" << filepath << "，请检查数据文件夹是否损坏" << endl;//报错
        return;
    }

    string line;
    while (getline(file, line)) {//检测是否有下一行数据并更新line，避免死循环
        stringstream ss(line);//读取特定行
        entry temp;//创建临时表
        ss >> temp.date >> temp.amount >> temp.category;//将变量写入到临时表
        entries.push_back(temp);//将这个临时表加入总表
    }
    file.close();//关闭文件占用
}

void financenote::save_to_file(const string &filepath) {//文件写入函数
    ofstream file(filepath);//创建文件输出流
    if (!file.is_open()) {//检测文件是否可写
        cerr << "无法修改目标文件：" << filepath << "，请检查数据文件夹是否损坏" << endl;//报错
        return;
    }

    for (const auto& temp : entries) {//从总表中遍历临时表
        file << temp.date << " " << temp.amount << " " << temp.category << endl;//用空格隔开
    }
    file.close();//关闭文件占用
}

void financenote::display() const {//显示函数
    cout << left << setw(10) << "日期"
         << setw(10) << "金额"
         << setw(10) << "类别" << endl;//表格格式分别输出三种数据
    cout << string(40,'-') << endl;

    for (const auto& temp : entries) {//从总表中遍历临时表
        cout << left << setw(15) << temp.date//输出日期
             << setw(10) << fixed << setprecision(2) << temp.amount//输出金额
             << setw(15) << temp.category << endl;//输出类别
    }
}
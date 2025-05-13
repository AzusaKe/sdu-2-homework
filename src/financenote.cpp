//
// Created by Azusa_Ke on 25-5-13.
//

#include"notebasic.h"
#include "financenote.h"

void financenote::load_from_file(const string &filepath) {//文件加载函数
    entries.clear();//清除之前内存里的记录
    ifstream file(filepath);//获取文件路径
    if (!file.is_open()) {//检测文件是否可读
        cerr << "无法打开目标文件：" << filepath << "，请检查数据文件夹是否损坏" << endl;
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

void

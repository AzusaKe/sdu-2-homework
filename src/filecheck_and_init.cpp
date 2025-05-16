//
// Created by Azusa_Ke on 25-5-13.
//

#include "filecheck_and_init.h"
#include <filesystem>
#include<fstream>
using namespace std;
void filecheck_and_init() {
    if (!filesystem::exists("data")) {
        filesystem::create_directory("data");
    }//防止由于data文件夹不存在出错，也用作初始化
    if (!filesystem::exists("./data/finance.txt")) {
        ofstream file("./data/finance.txt");//记账本
    }
    if (!filesystem::exists("./data/reminder.txt")) {
        ofstream file("./data/reminder.txt");//提醒
    }
    if (!filesystem::exists("./data/password.txt")) {
        ofstream file("./data/password.txt");//密码管理
    }
}
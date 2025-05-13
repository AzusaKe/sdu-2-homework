//
// Created by Azusa_Ke on 25-5-13.
//

#include "filecheck_and_init.h"
#include <filesystem>
using namespace std;
void filecheck_and_init() {
    if (!filesystem::exists("data")) {
        filesystem::create_directory("data");
    }//防止由于data文件夹不存在出错，也用作初始化
    if (!filesystem::exists("data/finance.txt")) {
        filesystem::create_directory("data/finance.txt");
    }
    if (!filesystem::exists("data/reminder.txt")) {
        filesystem::create_directory("data/reminder.txt");
    }
    if (!filesystem::exists("data/password.txt")) {
        filesystem::create_directory("data/password.txt");
    }
}
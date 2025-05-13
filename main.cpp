#include<iostream>
#include<filesystem>
#include"fileoperater.h"
#include"financenote.h"
#include"passwordmanager.h"
#include"reminder.h"

using namespace std;

int main() {
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
    financenote finanace_note;
    string path = "./data/finance.txt";

    finanace_note.load_from_file(path);
    finanace_note.add_entry("2025-05-13",88.88,"娱乐");
    finanace_note.display();
    finanace_note.save_to_file(path);
    return 0;
}

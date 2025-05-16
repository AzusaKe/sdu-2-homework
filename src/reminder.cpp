//
// Created by Azusa_Ke on 25-5-13.
//

#include"console_adaption.h"

#include "notebasic.h"
#include "reminder.h"
#include "formatcheck.h"
#include <cstdlib>
#include <iostream>
//逻辑部分--------------------------------------------------------------------------------------------------------------------
//文件加载函数
void reminder::load_from_file(const string &filepath) {
    entries.clear();
    ifstream file(filepath);
    if (!file.is_open()) {
        cerr << "无法打开目标文件：" << filepath << "，即将自动创建新文件" << endl;
        ofstream createFile(filepath);
        if (!createFile.is_open()) {
            cerr << "无法创建文件：" << filepath << "，请检查数据文件夹是否损坏" << endl;
            system_pause();
            return;
        }
        createFile.close();
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        event temp;
        ss >> temp.time >> temp.content >> temp.priority;
        if (!temp.time.empty()) {
            entries.push_back(temp);
        }
    }
    file.close();
}
//文件写入函数
void reminder::save_to_file(const string &filepath) {
    ofstream file(filepath);
    if (!file.is_open()) {
        cerr << "无法修改目标文件：" << filepath << "，即将自动创建新文件" << endl;
        ofstream createFile(filepath);
        if (!createFile.is_open()) {
            cerr << "无法创建文件：" << filepath << "，请检查数据文件夹是否损坏" << endl;
            system_pause();
            return;
        }
        createFile.close();
    }

    for (const auto& temp : entries) {
        file << temp.time << " " << temp.content << " " << temp.priority << endl;
    }
    file.close();
}

//搜索函数
void reminder::search(const string &date) {
    search_result.clear();
    for (const auto& temp : entries) {
        if (temp.time.substr(0,10) == date ) {
            event temp_search = temp;
            search_result.push_back(temp_search);
        }else {
            continue;
        }
    }
}

//记录添加函数
void reminder::add_entry(const string &time,const string& content, const int &priority) {
    entries.push_back({time,content,priority});
    reminder::save_to_file("./data/reminder.txt");
}

//关闭函数，避免错误保存
void reminder::close() {
    reminder::save_to_file("./date/reminder.txt");
}

void reminder::sort() {
    std::sort(search_result.begin(),search_result.end(),[](const event& a,const event& b) {
        return a.time > b.time;
    });
}

//逻辑部分结束-------------------------------------------------------------------------------------------------------------------
//命令行交互部分----------------------------------------------------------------------------------------------------------------

//显示函数
void reminder::display(const string &date) {
    system_clear();
    if (date.empty()) {
        cout << "[全部课程提醒]" << endl;
        search_result = entries;
    } else {
        cout << "[" << date << "日课程提醒]" << endl;
        reminder::search(date);
    }
    cout << left << setw(19) << "时间"
         << setw(24) << "| 内容"
         << setw(15) << "| 优先级" << endl;
    cout << string(55,'-') << endl;

    reminder::sort();

    for (const auto& temp : search_result){
        cout << left << setw(17) << temp.time
                 << "| " << setw(20) << temp.content
                 << "| " << setw(15) << temp.priority <<endl;
    }
    if (!date.empty()) {
        cout << "回车以回到提醒主页：" << endl;
        system_pause();
    }
}

//初始化函数，包含课程提醒主页
void reminder::init() {
    string path = "./data/reminder.txt";
    reminder::load_from_file(path);
    while (true) {
        reminder::display("");
        cout << "请选择你希望的操作：" << endl << "1.添加提醒" << endl << "2.按日期筛选提醒并输出"<< endl << "选择数字并按下回车(为0则退出)：" << endl;
        int choice;
        cin >> choice;
        system_clear();
        if (choice == 1) {
            string time;
            string content;
            int priority;
            do {
                cout << "请输入提醒时间(YYYY-MM-DD HH:MM)：" << endl;
                cin >> time;
                system_clear();
                if (!is_valid_date(time)) {
                    cerr << "错误的时间格式！请重新输入！" << endl;
                }
            }while (!is_valid_date(time));
            cout << "请输入提醒内容：" << endl;
            cin >> content;
            cout << "请输入优先级：" << endl;
            cin >> priority;
            reminder::add_entry(time,content,priority);
        }else if (choice == 2) {
            string date;
            do {
                cout << "请输入日期(YYYY-MM-DD)：" << endl;
                cin >> date;
                system_clear();
                if (!is_valid_date(date)) {
                    cerr << "错误的日期格式！请重新输入！" << endl;
                }
            }while (!is_valid_date(date));
            reminder::display(date);
        }else {
            break;
        }

    }reminder::close();
}


//
// Created by Azusa_Ke on 25-5-13.
//

#include"console_adaption.h"

#include "reminder.h"
#include "formatcheck.h"
#include <iostream>
#include <iomanip>
#include <ctime>

reminder::reminder(){
    reminder::load_from_file();
    *(azusa_log::log) << "日程提醒构造成功！" << endl;
}

reminder::~reminder(){
    reminder::close();
    *(azusa_log::log) << "日程提醒析构成功！" << endl;
}

//逻辑部分--------------------------------------------------------------------------------------------------------------------
//文件加载函数-复用自记账本
void reminder::load_from_file() {
    entries.clear();
    ifstream file(file_path);
    if (!file.is_open()) {
        cerr << "无法打开目标文件：" << file_path << "，即将自动创建新文件" << endl;
        ofstream createFile(file_path);
        if (!createFile.is_open()) {
            cerr << "无法创建文件：" << file_path << "，请检查数据文件夹是否损坏" << endl;
            system_pause();
            return;
        }
        createFile.close();
    }
    //读取正常事件列表
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        event temp;
        string date;
        string minute;
        ss >> date >> minute >> temp.content >> temp.priority;
        temp.time = date + " " + minute;
        if (!temp.time.empty()) {
            entries.push_back(temp);
        }
    }
    file.close();
    *(azusa_log::log) << "正常提醒已读取！" << endl;
    //读取过时事件列表
    ifstream old_file(old_file_path);
    string old_line;
    while (getline(old_file, old_line)) {
        stringstream ss(old_line);
        event temp;
        string date;
        string minute;
        ss >> date >> minute >> temp.content >> temp.priority;
        temp.time = date + " " + minute;
        if (!temp.time.empty()) {
            old_entries.push_back(temp);
        }
    }
    old_file.close();
    *(azusa_log::log) << "过时提醒已读取！" << endl;
}
//文件写入函数-复用自记账本
void reminder::save_to_file() {
    ofstream file(file_path);//创建文件输出流
    if (!file.is_open()) {//检测文件是否可写
        cerr << "无法修改目标文件：" << file_path << "，即将自动创建新文件" << endl;//报错
        ofstream createFile(file_path);
        if (!createFile.is_open()) {//检测文件是否能够打开
            cerr << "无法创建文件：" << file_path << "，请检查数据文件夹是否损坏" << endl;//报错
            system_pause();
            return;//退出
        }
        createFile.close();//关闭
    }
    //正常事件存入
    for (const auto& temp : entries) {
        file << temp.time << " " << temp.content << " " << temp.priority << endl;
    }
    file.close();
    *(azusa_log::log) << "正常提醒已保存！" << endl;
    //过时事件存入
    ofstream old_file(old_file_path);
    for (const auto& temp : old_entries) {
        old_file << temp.time << " " << temp.content << " " << temp.priority << endl;
    }
    old_file.close();
    *(azusa_log::log) << "过时提醒已保存！" << endl;
}

//搜索函数-复用自记账本
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
    *(azusa_log::log) << "[ " << date << " ]搜索完成！" << endl;
}

//记录添加函数-复用自记账本
void reminder::add_entry(const string &time,const string& content, const int &priority) {
    entries.push_back({time,content,priority});
    reminder::save_to_file();
        *(azusa_log::log) << "已将记录： " << time << "、" << content << "、" << priority << " 添加至列表！" << endl;
}

//关闭函数，避免错误保存-复用自记账本
void reminder::close() {
    reminder::save_to_file();
    *(azusa_log::log) << "已关闭这个日程提醒实例！" << endl;
}

void reminder::sort() {
    if (is_in_index) {
        std::sort(search_result.begin(),search_result.end(),[](const event& a,const event& b) {
        return a.time < b.time;
    });
    }else {
        std::sort(search_result.begin(),search_result.end(),[](const event& a,const event& b) {
        return a.time > b.time;
    });
    }
    *(azusa_log::log) << "已完成排序！" << endl;
}

//获取当前时间并将其转化为YYYY-MM-DD的形式
void reminder::get_current_date() {
    const time_t t = time(nullptr); //获取当前时间
    if (t == -1) {
        *(azusa_log::log) << "无法获取当前时间" << endl;
        current_date = "1970-01-01"; // 设置默认日期以防错误
        *(azusa_log::log) << "调试信息：本地时间：" << current_date << endl;
        system_pause();
        return;
    }
    const tm *now = localtime(&t); //转换为本地时间
    if (now == nullptr) {
        *(azusa_log::log) << "无法转换为本地时间" << endl;
        current_date = "1970-01-01"; // 设置默认日期以防错误
        *(azusa_log::log) << "调试信息：本地时间：" << current_date << endl;
        system_pause();
        return;
    }
    ostringstream oss; //创建字符串流对象
    oss << put_time(now, "%Y-%m-%d"); //格式化输出时间
    current_date = oss.str(); //赋值给current_time
    *(azusa_log::log) << "调试信息：本地时间：" << current_date << endl;
}

void reminder::add_old_entries() {
    //遍历当前事件容器
    reminder::get_current_date();
    for (auto it = entries.begin(); it != entries.end();) {
        //检测当前事件是否过时
        if (it->time.substr(0, 10) < current_date) {
            //如果过时，加入过时事件
            old_entries.push_back(*it);
            //从当前事件容器中删除过时事件
            it = entries.erase(it);
        } else {
            //如果不过时，继续遍历
            ++it;
        }
    }
}


//逻辑部分结束-------------------------------------------------------------------------------------------------------------------
//命令行交互部分----------------------------------------------------------------------------------------------------------------

//显示函数
void reminder::display(const string &date) {
    system_clear();
    if (date.empty()) {
        cout << "[全部课程提醒]" << endl;
        search_result = entries;
    } else if (date == "-") {
        cout << "[当前为回收站中过时提醒]" << endl;
        search_result = old_entries;
        is_in_index = false;
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
       //添加中文字符支持，避免显示错位
       auto pad = [](const std::string& s, int width) {
           int w = 0;
           for (size_t i = 0; i < s.size(); ) {
               unsigned char c = s[i];
               if (c >= 0x80) { w += 2; i += (c >= 0xE0 ? 3 : 2); } // 粗略判断UTF-8中文宽度
               else { w += 1; ++i; }
           }
           std::cout << s;
           for (int i = w; i < width; ++i) std::cout << ' ';
       };
       pad(temp.time, 17);
       cout << "| ";
       pad(temp.content, 20);
       cout << "| ";
       pad(to_string(temp.priority), 15);
       cout << endl;
   }
    if (!date.empty()) {
        if (search_result.empty()) {
            cout << "似乎当前条件没有满足的提醒..." << endl;
            if (date != "-") {
                cout << "去回收站试试？" << endl;
            }
        }
        cout << "回车以回到提醒主页：" << endl;
        system_pause();
    }
    is_in_index = true;
}

//初始化函数，包含课程提醒主页
void reminder::init() {
    is_in_index = true;
    reminder::load_from_file();
    while (true) {
        reminder::display("");
        cout << "请选择你希望的操作：" << endl << "1.添加提醒" << endl << "2.按日期筛选提醒并输出" << endl << "3.将过时事件移入回收站" << endl << "4.查看回收站" << endl << "选择数字并按下回车(为0则退出)：" << endl;
        int choice;
        cin >> choice;
        system_clear();
        if (choice == 1) {
            string time;
            string content;
            int priority;
            cin.ignore();
            do {
                cout << "请输入提醒时间(YYYY-MM-DD HH:MM)：" << endl;
                getline(cin,time);
                system_clear();
                if (!is_valid_time(time)) {
                    cerr << "错误的时间格式！请重新输入！" << endl;
                }
            }while (!is_valid_time(time));
            system_clear();
            cout << "请输入提醒内容(请不要带有空格！)：" << endl;
            cin >> content;
            system_clear();
            do {
                cout << "请输入优先级：" << endl;
                cin.ignore();
                cin >> priority;
                if (!is_valid_priority(priority)) {
                    cerr << "错误的优先级！请重新输入！" << endl;
                }
            }while (!is_valid_priority(priority));
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
        }else if (choice == 3) {
            reminder::add_old_entries();
            system_clear();
            cout << "已将过时的提醒加入回收站！" << endl;
            system_pause();
        }else if (choice == 4) {
            reminder::display("-");
        }else {
            break;
        }
    }reminder::close();
}
//命令行交互部分结束---------------------------------------------------------------------------------------------
//图形化交互部分------------------------------------------------------------------------------------------------------


//图形化交互部分结束-------------------------------------------------------------------------------------------------------

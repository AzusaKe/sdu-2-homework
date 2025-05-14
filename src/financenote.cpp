//
// Created by Azusa_Ke on 25-5-13.
//

#include"notebasic.h"
#include "financenote.h"
#include "formatcheck.h"
#include <cstdlib>
#include <iostream>

//文件加载函数
void financenote::load_from_file(const string &filepath) {
    entries.clear();//清除之前内存里的记录
    ifstream file(filepath);//获取文件路径
    if (!file.is_open()) {//检测文件是否可读
        cerr << "无法打开目标文件：" << filepath << "，即将自动创建新文件" << endl;//报错
        ofstream createFile(filepath);//重新创建文件
        if (!createFile.is_open()) {//检测文件是否存在
            cerr << "无法创建文件：" << filepath << "，请检查数据文件夹是否损坏" << endl;//报错
	    return;//退出
        }
        createFile.close();//关闭
    }

    string line;
    while (getline(file, line)) {//检测是否有下一行数据并更新line，避免死循环
        stringstream ss(line);//读取特定行
        entry temp;//创建临时表
        ss >> temp.date >> temp.amount >> temp.category;//将变量写入到临时表
        if (!temp.date.empty()) {//若读取数据不为空
            entries.push_back(temp);//将这个临时表加入总表
        }//反之不写入
    }
    file.close();//关闭文件占用
}
//文件写入函数
void financenote::save_to_file(const string &filepath) {
    ofstream file(filepath);//创建文件输出流
    if (!file.is_open()) {//检测文件是否可写
        cerr << "无法修改目标文件：" << filepath << "，即将自动创建新文件" << endl;//报错
        ofstream createFile(filepath);
        if (!createFile.is_open()) {//检测文件是否能够打开
            cerr << "无法创建文件：" << filepath << "，请检查数据文件夹是否损坏" << endl;//报错
            return;//退出
        }
        createFile.close();//关闭
    }

    for (const auto& temp : entries) {//从总表中遍历临时表
        file << temp.date << " " << temp.amount << " " << temp.category << endl;//用空格隔开
    }
    file.close();//关闭文件占用
}
//显示函数
void financenote::display(const string &month) const {
#ifdef _WIN32
    system("cls");//windows清屏代码
#else
    system("clear");//linux/macos清屏代码
#endif
    //提高兼容性
    if (month.empty()) {//如果没有传入参数，显示全部消费记录
        cout << "[全部消费记录]" << endl;
    } else {//如果传入参数，显示月份记录
        cout << "[" << month << "月消费记录]" << endl;
    }
    //表格格式分别输出三种数据表头
    cout << left << setw(19) << "日期"
         << setw(24) << "| 金额"
         << setw(15) << "| 类别" << endl;
    cout << string(55,'-') << endl;

    double total = 0.0;//记录总开销
    bool has_record = false;//检测是否有记录，避免误判
    //遍历总表，寻找符合要求的记录
    for (const auto& temp : entries) {
        //如果参数为空或者符合搜索条件，输出全部删记录
        if (month.empty() || temp.date.substr(0, 7) == month) {
            cout << left << setw(17) << temp.date//以行为单位输出记录
                 << "| " << setw(20) << fixed << setprecision(2) << temp.amount
                 << "| " << setw(15) << temp.category << endl;
            total += temp.amount;
            has_record = true;
        }//如果传入参数且不符合搜索条件，跳过
        else if (!month.empty() && temp.date.substr(0, 7) != month) {
            continue;
        }
    }//判定是否有记录，有则输出
    if (has_record) {
        cout << "总支出：" << total << endl;
    }//无则输出：无记录
    else {
        cout << "没有记录" << endl;
    }//如果传入搜索参数，显示返回操作
    if (!month.empty()) {
        cout << "回车以回到记账本主页：" << endl;
        #ifdef _WIN32
            system("pause");
        #else
            system("read -p 'Press any key to continue...' var");
        #endif
        //添加兼容代码
    }
}
//记录添加函数
void financenote::add_entry(const string &date, double amount, const string &category) {
    entries.push_back({date, amount, category});//将数据添加进总表
    financenote::save_to_file("./data/finance.txt");//每添加一次记录就保存一次，避免出错
}
//关闭函数，避免错误保存
void financenote::close() {
    financenote::save_to_file("./data/finance.txt");
}
//初始化函数，包含记账本主页
void financenote::init() {
    string path = "./data/finance.txt";
    financenote::load_from_file(path);//加载数据
    while (true) {//循环输入选项
        financenote::display("");
        cout << "请选择你希望的操作：" << endl << "1.添加记录" << endl << "2.按月份筛选消费记录并输出总金额"<< endl << "选择数字并按下回车(为0则退出)：" << endl;//记账本主界面
        int choice;
        cin >> choice;
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        //提高兼容性
        if (choice == 1) {
            string date;//日期
            double amount;//金额
            string category;//初始化变量
            do {
                cout << "请输入日期：" << endl;
                cin >> date;//输入日期
#ifdef _WIN32
                system("cls");
#else
                system("clear");
#endif
                //提高兼容性
                if (!is_valid_date(date)) {//检验日期是否合法
                    cerr << "错误的日期格式！请重新输入！" << endl;
                }
            }while (!is_valid_date(date));
            cout << "请输入金额：" << endl;
            cin >> amount;
            cout << "请输入类别：" << endl;
            cin >> category;
            financenote::add_entry(date,amount,category);//添加行函数
        }else if (choice == 2) {
            string month;
            do {
                cout << "请输入月份(YYYY-MM)：" << endl;
                cin >> month;//搜索界面
#ifdef _WIN32
                system("cls");
#else
                system("clear");
#endif
                //提高兼容性
                if (!is_valid_month(month)) {
                    cerr << "错误的日期格式！请重新输入！"
                }
            }while (!is_valid_month(month));
            financenote::display(month);
        }else {
            break;//返回
        }
        financenote::close();//关闭窗口
    }
}

#include<windows.h>
#include<iostream>
#include"fileoperater.h"
#include"financenote.h"
#include"passwordmanager.h"
#include"reminder.h"
#include"filecheck_and_init.h"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "请选择你要使用的工具：" << endl << "1.记账本" << endl << "选择数字并按下回车：" << endl;
    int choice;
    cin >> choice;
    system("cls");
    if (choice == 1) {
        financenote finance_note;
        finance_note.init();
        cout << "请选择你希望的操作：" << endl << "1.添加记录" << endl << "2.关闭记账本" << endl << "选择数字并按下回车：" << endl;
        finance_note.add_entry("2025-05-13",88.88,"娱乐");
        finance_note.display();
        finance_note.close();
    }

    return 0;
}

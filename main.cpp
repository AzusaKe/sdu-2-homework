#include<windows.h>
#include<iostream>
#include"financenote.h"
#include"passwordmanager.h"
#include"reminder.h"
#include"filecheck_and_init.h"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    filecheck_and_init();
    while (true) {
        cout << "请选择你要使用的工具：" << endl << "1.记账本" << endl << "选择数字并按下回车(为0则退出)：" << endl;
        int choice;
        cin >> choice;
        system("cls");
        if (choice == 1) {//记账本模式
            financenote finance_note;
            finance_note.init();
        }else {
            break;
        }
    }
    return 0;
}

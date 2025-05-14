#ifdef _WIN32
#include<windows.h>
#endif

#include<iostream>
#include"financenote.h"
#include"passwordmanager.h"
#include"reminder.h"
#include"filecheck_and_init.h"
using namespace std;

int main(bool graphics = false) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    filecheck_and_init();
    while (graphics != true) {
        cout << "请选择你要使用的工具：" << endl << "1.记账本" << endl << "选择数字并按下回车(为0则退出)：" << endl;
        int choice;
        cin >> choice;
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        //提高兼容性
        if (choice == 1) {//记账本模式
            financenote finance_note;
            finance_note.init();
        }else {
            break;
        }
    }
    return 0;
}

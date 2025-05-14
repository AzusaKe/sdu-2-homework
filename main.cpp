#ifdef _WIN32
#include<windows.h>
#endif

#include<iostream>
#include"financenote.h"
#include"passwordmanager.h"
#include"reminder.h"
#include"filecheck_and_init.h"
using namespace std;

//图形化程序入口
void runGraphicalInterface() {
    std::cout << "Running graphical interface..." << std::endl;
    // 在这里实现你的图形化界面代码
}

//命令行程序入口
int runCommandLineInterface(int argc, char* argv[]) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE),ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT);
#endif
    filecheck_and_init();
    while (true) {
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

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        // 如果有命令行参数，运行命令行界面
        runCommandLineInterface(argc, argv);
    } else {
        // 否则，运行图形化界面
        runGraphicalInterface();
    }
    return 0;
}

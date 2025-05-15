#ifdef _WIN32
#include<windows.h>
#endif
//为不同系统添加兼容代码

#include<iostream>
#include"financenote.h"
#include"passwordmanager.h"
#include"reminder.h"
#include"filecheck_and_init.h"
using namespace std;//使用标准命名空间

//图形化程序入口
void run_Graphical_Interface() {
    cout << "Running graphical interface..." << endl;//调试用代码
    //图形化界面代码实现
}

//命令行程序入口
int run_Command_Line_Interface(int argc, char* argv[]) {
    //windows兼容代码
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE),ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT);//修改控制台编码格式,避免乱码
#endif
    filecheck_and_init();//检查文件是否存在并初始化
    while (true) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        cout << "请选择你要使用的工具：" << endl << "1.记账本" << endl << "选择数字并按下回车(为0则退出)：" << endl;//选择功能
        int choice;
        cin >> choice;//输入功能
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        //提高兼容性
        if (choice == 1) {//记账本模式
            financenote finance_note;//创建记账本对象
            finance_note.init();//记账本初始化
        }else {
            break;//退出代码
        }
    }
    return 0;//退出
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {//在完成图形化后记得修改为if (argc > 1)
        // 如果没有命令行参数，运行命令行界面
        run_Command_Line_Interface(argc, argv);
    } else {
        // 否则，运行图形化界面
        run_Graphical_Interface();
    }
    return 0;//退出
}

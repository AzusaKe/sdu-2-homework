#include "console_adaption.h"
//为不同系统添加兼容代码

#include<iostream>
#include"financenote.h"
#include"passwordmanager.h"
#include"reminder.h"
#include"filecheck_and_init.h"
#include "SHA_256.h"

using namespace std;//使用标准命名空间

bool is_graphic = false;//是否为图形化界面

//图形化程序入口
int run_Graphical_Interface(int argc, char* argv[]) {
    is_graphic = true;
    cout << "Running graphical interface..." << endl;//调试用代码
    reminder a;
    passwordmanager b;
    cout <<"is_graphic = " << (is_graphic ? "True" : "False") << endl;
    a.get_current_date();
    cout << "SHA256::sha_256(123)= " << SHA256::sha_256("123") << endl;
    cout << "SHA256::sha_256(123456)= " << SHA256::sha_256("123456") << endl;
    cout << "SHA256::sha_256(123456789)= " << SHA256::sha_256("123456789") << endl;
    //图形化界面代码实现
    try {
        QApplication app(argc, argv);
        QLabel *info_label = new QLabel;
        QLabel *whelcome_label = new QLabel;
        QLabel *choice_info_label = new QLabel;
        QPushButton *financenote_button = new QPushButton;
        QPushButton *reminder_button = new QPushButton;
        QPushButton *passwordmanager_button = new QPushButton;
        QPushButton *exit_button = new QPushButton;
        QHBoxLayout *choice_layout = new QHBoxLayout;
        QHBoxLayout *exit_layout = new QHBoxLayout;
        QVBoxLayout *main_layout = new QVBoxLayout;

        whelcome_label -> setText("欢迎");
        choice_info_label -> setText("任选一个功能以继续：");
        financenote_button -> setText("记账本");
        reminder_button -> setText("日程提醒");
        passwordmanager_button -> setText("密码管理器");
        exit_button -> setText("退出");
        
        choice_layout -> addWidget(financenote_button);
        choice_layout -> addWidget(reminder_button);
        choice_layout -> addWidget(passwordmanager_button);

        exit_layout -> addWidget(exit_button);

        main_layout -> addWidget(whelcome_label);
        main_layout -> addWidget(choice_info_label);
        main_layout -> addLayout(choice_layout);
        main_layout -> addLayout(exit_layout);

        QWidget *index = new QWidget;
        index -> setLayout(main_layout);

        index -> setWindowTitle("桌面工具");

        index -> show();

        return app.exec();
    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return -1;
    }

}

//命令行程序入口
int run_Command_Line_Interface(int argc, char* argv[]) {
    is_graphic = false;
    while (true) {
        system_clear();
        cout << "请选择你要使用的工具：" << endl << "1.记账本" << endl << "2.提醒" << endl << "3.密码管理器" << endl << "选择数字并按下回车(为0则退出)：" << endl;//选择功能
        int choice;
        cin >> choice;//输入功能
        system_clear();
        //提高兼容性
        if (choice == 1) {//记账本模式
            financenote finance_note;//创建记账本对象
            finance_note.init();//记账本初始化
        }else if (choice == 2) {
            reminder reminder_temp;
            reminder_temp.init();
        }
        else if (choice == 3) {
            passwordmanager password_manager;
            password_manager.init();
        }else {
            break;//退出代码
        }
    }
    return 0;//退出
}

int main(int argc, char* argv[]) {
    //windows兼容代码
#ifdef Q_OS_WIN
    //设置控制台输出为UTF-8编码
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE),ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT);//修改控制台编码格式,避免乱码
#endif
    filecheck_and_init();//检查文件是否存在并初始化
    if (argc > 1) {//在完成图形化后记得修改为if (argc > 1)
        // 如果没有命令行参数，运行命令行界面
        run_Command_Line_Interface(argc, argv);
    } else {
        // 否则，运行图形化界面
        run_Graphical_Interface(argc, argv);
    }
    return 0;//退出
}

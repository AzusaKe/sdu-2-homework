#include "console_adaption.h"
//为不同系统添加兼容代码

#include<iostream>
#include"filecheck_and_init.h"
#include "SHA_256.h"

#include"mainwindow.h"
#include<QTranslator>
#include<QLocale>
#include<QIcon>

using namespace std;//使用标准命名空间

bool is_graphic = false;//是否为图形化界面

int run_Graphical_Interface(int argc, char* argv[]);//图形化界面函数
int run_Command_Line_Interface(int argc, char* argv[]);//命令行界面函数

int main(int argc, char* argv[]) {
    //windows兼容代码
#ifdef Q_OS_WIN
    //设置控制台输出为UTF-8编码
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE),ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT);//修改控制台编码格式,避免乱码
#endif
    filecheck_and_init();//检查文件是否存在并初始化
    if (argc > 1) {// 在完成图形化后记得修改为if (argc > 1)
        // 如果没有命令行参数，运行命令行界面
        run_Command_Line_Interface(argc, argv);
    } else {
        // 否则，运行图形化界面
        run_Graphical_Interface(argc, argv);
    }
    return 0;//退出
}

//图形化程序入口
int run_Graphical_Interface(int argc, char* argv[]) {
    is_graphic = true;
    // log系统启动
    log();
#ifdef Q_OS_WIN
    ::FreeConsole();
#elif defined(Q_OS_LINUX)
    // 无需隐藏
#endif
    cout << "运行图形界面..." << endl;//调试用代码
    financenote finance_note;
    reminder reminder_temp;
    passwordmanager password_manager;
    cout << "测试：" << endl;
    cout <<"is_graphic = " << (is_graphic ? "True" : "False") << endl;
    reminder_temp.get_current_date();
    cout << "SHA256::sha_256(123)= " << SHA256::sha_256("123") << endl;
    cout << "SHA256::sha_256(123456)= " << SHA256::sha_256("123456") << endl;
    cout << "SHA256::sha_256(123456789)= " << SHA256::sha_256("123456789") << endl;
    try {
        QApplication app(argc,argv);
        cout << "已创建QApplication对象！" << endl;

        QPixmap pixmap(":/icons/icon.ico");
        if (pixmap.isNull()) {
            cerr << "加载图标失败！" << endl;
        }else {
            app.setWindowIcon(QIcon(":/icons/icon.ico"));
            cout << "已设置图标！" << endl;
        }

        QTranslator translator;
        const QStringList uiLanguages = QLocale::system().uiLanguages();
        for (const QString &locale : uiLanguages) {
            const QString baseName = "main_ui_" + QLocale(locale).name();
            if (translator.load(":/i18n/" + baseName)) {
                app.installTranslator(&translator);
                break;
            }
        }

        financenote *finance_note_ptr = &finance_note;
        reminder *reminder_temp_ptr = &reminder_temp;
        passwordmanager *password_manager_ptr = &password_manager;

        MainWindow main_window;
        main_window.set_ptr_financenote_2(finance_note_ptr);
        main_window.set_ptr_reminder_2(reminder_temp_ptr);
        main_window.set_ptr_passwordmanager_2(password_manager_ptr);
        main_window.show();

        // 监听 MainWindow 的 exit 信号，析构三个模块并关闭程序
        QObject::connect(&main_window, &MainWindow::exit, [&]() {
            // 析构模块对象
            app.quit();
            return 0;
        });

        return app.exec();
    }catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return -1;
    }

    //图形化界面代码实现测试，已注释
    /*try {
        QApplication app(argc, argv);
        QLabel *info_label = new QLabel;
        QLabel *welcome_label = new QLabel;
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
    }*/
}

//命令行程序入口
int run_Command_Line_Interface(int argc, char* argv[]) {
    is_graphic = false;
    // log系统启动
    log();
    while (true) {
        financenote finance_note;
        reminder reminder_temp;
        passwordmanager password_manager;
        system_clear();
        cout << "请选择你要使用的工具：" << endl << "1.记账本" << endl << "2.提醒" << endl << "3.密码管理器" << endl << "选择数字并按下回车(为0则退出)：" << endl;//选择功能
        int choice;
        cin >> choice;//输入功能
        system_clear();
        //提高兼容性
        if (choice == 1) {//记账本模式
            finance_note.init();//记账本初始化
        }else if (choice == 2) {
            reminder_temp.init();
        }
        else if (choice == 3) {
            password_manager.init();
        }else {
            break;//退出代码
        }
    }
    return 0;//退出
}

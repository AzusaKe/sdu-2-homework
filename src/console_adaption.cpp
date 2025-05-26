//
// Created by Azusa_Ke on 25-5-15.
//

#include "console_adaption.h"
#include"dual_streambuf.h"

void system_clear() {
#ifdef Q_OS_WIN
    system("cls");
#elif defined(Q_OS_LINUX)
    system("clear");
#endif
}

void system_pause() {
#ifdef Q_OS_WIN
    system("pause");
#elif defined(Q_OS_LINUX)
    system("read -p 'Press any key to continue...' var");
#endif
}

string system_get_hidden_input() {
    cin.ignore();
    #ifdef Q_OS_WIN
    string input;
    char ch;
    while ((ch = _getch()) != '\r'){
        if (ch == '\b'){
            if (!input.empty()){
                input.pop_back();
                cout << "\b \b";
            }
        } else {
            input += ch;
            cout << '*';
        }
    }
    return input;
    #elif defined(Q_OS_LINUX)
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    string input;
    char ch;
    while (true) {
        ch = getchar();
        if (ch == '\n' || ch == EOF) {
            break;
        }
        if (ch == 127 || ch == 8) { // handle both DEL and backspace
            if (!input.empty()) {
                input.pop_back();
                cout << "\b \b";
                cout.flush();
            }
        } else {
            input += ch;
            cout << '*';
            cout.flush();
        }
    }
    cout << endl;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return input;
    #endif
}

void log() {
    std::filesystem::create_directories("log");
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm;
#ifdef _WIN32
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif
    std::ostringstream oss;
    oss << "log/"
        << std::put_time(&tm, "%Y-%m-%d_%H-%M-%S")
        << ".log";
    std::string log_path = oss.str();

    static std::ofstream log_file(log_path, std::ios::out | std::ios::app);
    if (!is_graphic) {
        static dual_streambuf dsb(std::cout.rdbuf(), log_file.rdbuf());
        std::cout.rdbuf(&dsb);
        static dual_streambuf dsb_err(std::cerr.rdbuf(), log_file.rdbuf());
        std::cerr.rdbuf(&dsb_err);
    } else {
        std::cout.rdbuf(log_file.rdbuf());
        std::cerr.rdbuf(log_file.rdbuf());
    }
}
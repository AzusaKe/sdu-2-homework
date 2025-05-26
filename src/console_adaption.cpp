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
//
// Created by Azusa_Ke on 25-5-15.
//

#include "console_adaption.h"

void system_clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void system_pause() {
#ifdef _WIN32
    system("pause");
#else
    system("read -p 'Press any key to continue...' var");
#endif
}

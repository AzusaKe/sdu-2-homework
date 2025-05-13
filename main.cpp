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
    filecheck_and_init();
    financenote finance_note;
    finance_note.init();
    finance_note.add_entry("2025-05-13",88.88,"娱乐");
    finance_note.display();
    finance_note.close();
    return 0;
}

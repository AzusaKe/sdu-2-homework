#include<iostream>
#include"fileoperater.h"
#include"financenote.h"
#include"passwordmanager.h"
#include"reminder.h"

using namespace std;

int main() {

    financenote finance_note;
    string path = "./data/finance.txt";

    finance_note.load_from_file(path);
    finance_note.add_entry("2025-05-13",88.88,"娱乐");
    finance_note.display();
    finance_note.save_to_file(path);
    return 0;
}

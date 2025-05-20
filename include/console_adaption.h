//
// Created by Azusa_Ke on 25-5-15.
//

#ifndef CONSOLE_ADAPTION_H
#define CONSOLE_ADAPTION_H

#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QtCore/qglobal.h>

#ifdef Q_OS_WIN
#include<windows.h>
#include<conio.h>
#elif defined(Q_OS_LINUX)
#include<unistd.h>
#include<termios.h>
#endif
#include<string>
#include<cstdlib>
#include<iostream>
using namespace std;

#pragma once
extern bool is_graphic;
void system_clear();
void system_pause();
string system_get_hidden_input();

#endif //CONSOLE_ADAPTION_H

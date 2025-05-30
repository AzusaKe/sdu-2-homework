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
#define WIN32_LEAN_AND_MEAN
#define NOGDI
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
#include<fstream>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <sstream>
#include"mainwindow.h"
#include "log.h"
using namespace std;

#pragma once

void system_clear();
void system_pause();
string system_get_hidden_input();

#endif //CONSOLE_ADAPTION_H

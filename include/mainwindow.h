#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "financenote_window.h"
#include "reminder_window.h"
#include "passwordmanager_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

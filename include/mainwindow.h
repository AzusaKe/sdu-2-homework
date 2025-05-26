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

    void set_ptr_financenote_2(financenote *ptr);
    void set_ptr_reminder_2(reminder *ptr);
    void set_ptr_passwordmanager_2(passwordmanager *ptr);
public slots:
    void on_financenote_button_clicked();
    void on_reminder_button_clicked();
    void on_passwordmanager_button_clicked();
    void on_exit_button_clicked();
    void open_passwordmanager_window();

private:
    Ui::MainWindow *ui;
    financenote *finance_note_ptr_2;
    reminder *reminder_temp_ptr_2;
    passwordmanager *password_manager_ptr_2;
};
#endif // MAINWINDOW_H

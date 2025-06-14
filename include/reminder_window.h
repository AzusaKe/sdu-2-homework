#ifndef REMINDER_WINDOW_H
#define REMINDER_WINDOW_H

#include <QMainWindow>
#include "r_add_record_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Reminder_Window;
}
QT_END_NAMESPACE

class Reminder_Window : public QMainWindow
{
    Q_OBJECT

public:
    Reminder_Window(QWidget *parent = nullptr);
    ~Reminder_Window();

    void set_ptr(reminder *ptr);
    void closeEvent(QCloseEvent *event) override;
    public slots:
    void display();
    void on_search_Button_clicked();
    void on_add_Button_clicked();
    void on_clear_Button_clicked();
    void on_move_to_old_Button_clicked();
    void on_change_to_old_Button_clicked();

private:
    Ui::Reminder_Window *ui;
    reminder *reminder_temp_ptr_3;
};
#endif // REMINDER_WINDOW_H

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

private:
    Ui::Reminder_Window *ui;
};
#endif // REMINDER_WINDOW_H

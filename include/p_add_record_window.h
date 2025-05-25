#ifndef P_ADD_RECORD_WINDOW_H
#define P_ADD_RECORD_WINDOW_H

#include <QMainWindow>
#include "passwordauth_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class p_add_record_Window;
}
QT_END_NAMESPACE

class p_add_record_Window : public QMainWindow
{
    Q_OBJECT

public:
    p_add_record_Window(QWidget *parent = nullptr);
    ~p_add_record_Window();

private:
    Ui::p_add_record_Window *ui;
};
#endif // P_ADD_RECORD_WINDOW_H

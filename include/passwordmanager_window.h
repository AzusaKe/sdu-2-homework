#ifndef PASSWORDMANAGER_WINDOW_H
#define PASSWORDMANAGER_WINDOW_H

#include <QMainWindow>
#include "p_add_record_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Passwordmanager_Window;
}
QT_END_NAMESPACE

class Passwordmanager_Window : public QMainWindow
{
    Q_OBJECT

public:
    Passwordmanager_Window(QWidget *parent = nullptr);
    ~Passwordmanager_Window();

    void set_ptr(passwordmanager *ptr);

    void closeEvent(QCloseEvent *event) override;

private:
    Ui::Passwordmanager_Window *ui;
    passwordmanager *password_manager_ptr_4;
};
#endif // PASSWORDMANAGER_WINDOW_H

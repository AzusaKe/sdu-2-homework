#ifndef PASSWORDAUTH_WINDOW_H
#define PASSWORDAUTH_WINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "passwordmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Passwordauth_Window;
}
QT_END_NAMESPACE

class Passwordauth_Window : public QMainWindow
{
    Q_OBJECT

public:
    Passwordauth_Window(QWidget *parent = nullptr);
    ~Passwordauth_Window();

    void set_ptr(passwordmanager *ptr) ;

    void authenticate();

    void closeEvent(QCloseEvent *event) override;
    signals:
    void authenticated();

private:
    Ui::Passwordauth_Window *ui;
    passwordmanager *password_manager_ptr_5;
    bool is_authenticated = false;
};
#endif // PASSWORDAUTH_WINDOW_H

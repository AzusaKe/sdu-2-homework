#ifndef PASSWORDAUTH_WINDOW_H
#define PASSWORDAUTH_WINDOW_H

#include <QMainWindow>

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

private:
    Ui::Passwordauth_Window *ui;
};
#endif // PASSWORDAUTH_WINDOW_H

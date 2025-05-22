#ifndef PASSWORDMANAGER_WINDOW_H
#define PASSWORDMANAGER_WINDOW_H

#include <QMainWindow>

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

private:
    Ui::Passwordmanager_Window *ui;
};
#endif // PASSWORDMANAGER_WINDOW_H

#ifndef FINANCENOTE_WINDOW_H
#define FINANCENOTE_WINDOW_H

#include <QMainWindow>
#include"f_add_record_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Financenote_Window;
}
QT_END_NAMESPACE

class Financenote_Window : public QMainWindow
{
    Q_OBJECT

public:
    Financenote_Window(QWidget *parent = nullptr);
    ~Financenote_Window();

private:
    Ui::Financenote_Window *ui;
};
#endif // FINANCENOTE_WINDOW_H

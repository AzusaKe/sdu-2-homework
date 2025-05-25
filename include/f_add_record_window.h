#ifndef F_ADD_RECORD_WINDOW_H
#define F_ADD_RECORD_WINDOW_H

#include <QMainWindow>
#include "financenote.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class f_add_record_Window;
}
QT_END_NAMESPACE

class f_add_record_Window : public QMainWindow
{
    Q_OBJECT

public:
    f_add_record_Window(QWidget *parent = nullptr);
    ~f_add_record_Window();

private:
    Ui::f_add_record_Window *ui;
};
#endif // F_ADD_RECORD_WINDOW_H

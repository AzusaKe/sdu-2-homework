#ifndef R_ADD_RECORD_WINDOW_H
#define R_ADD_RECORD_WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class r_add_record_Window;
}
QT_END_NAMESPACE

class r_add_record_Window : public QMainWindow
{
    Q_OBJECT

public:
    r_add_record_Window(QWidget *parent = nullptr);
    ~r_add_record_Window();

private:
    Ui::r_add_record_Window *ui;
};
#endif // R_ADD_RECORD_WINDOW_H

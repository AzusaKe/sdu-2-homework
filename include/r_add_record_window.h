#ifndef R_ADD_RECORD_WINDOW_H
#define R_ADD_RECORD_WINDOW_H

#include <QMainWindow>
#include "reminder.h"

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

    void set_ptr(reminder *ptr);
    void closeEvent(QCloseEvent *event) override;
    signals:
    void refresh();
    public slots:
    void on_add_record_Button_clicked();

private:
    Ui::r_add_record_Window *ui;
    reminder *reminder_temp_ptr_5;
};
#endif // R_ADD_RECORD_WINDOW_H

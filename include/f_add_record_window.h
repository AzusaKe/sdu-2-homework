#ifndef F_ADD_RECORD_WINDOW_H
#define F_ADD_RECORD_WINDOW_H

#include <QMainWindow>
#include <QMessageBox>
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

    void set_ptr(financenote *ptr);
    void closeEvent(QCloseEvent *event) override;
    signals:
    void refresh();
    public slots:
    void on_add_record_Button_clicked();

private:
    Ui::f_add_record_Window *ui;
    financenote *finance_note_ptr_5;
};
#endif // F_ADD_RECORD_WINDOW_H

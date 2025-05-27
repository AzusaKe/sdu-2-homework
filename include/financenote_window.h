#ifndef FINANCENOTE_WINDOW_H
#define FINANCENOTE_WINDOW_H

#include <QMainWindow>
#include <QMessageBox>
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

    void set_ptr(financenote *ptr);
    void closeEvent(QCloseEvent *event) override;
    signals:
    public slots:
    void display();
    void on_search_Button_clicked();
    void on_add_Button_clicked() ;

private:
    Ui::Financenote_Window *ui;
    financenote *finance_note_ptr_3;
};
#endif // FINANCENOTE_WINDOW_H

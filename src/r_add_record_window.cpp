#include "r_add_record_window.h"
#include "./ui_r_add_record_window.h"
#include <QMessageBox>

#include "formatcheck.h"

r_add_record_Window::r_add_record_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::r_add_record_Window)
{
    ui->setupUi(this);
    setWindowTitle("添加一条日程提醒...");
    connect(ui->exit_Button, &QPushButton::clicked, this, &r_add_record_Window::close);
    connect(ui->add_Button, &QPushButton::clicked, this, &r_add_record_Window::on_add_record_Button_clicked);
}

r_add_record_Window::~r_add_record_Window()
{
    delete ui;
}

void r_add_record_Window::set_ptr(reminder *ptr) {
    reminder_temp_ptr_5 = ptr;
}

void r_add_record_Window::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    if (reminder_temp_ptr_5) {
        reminder_temp_ptr_5->close();
    }
    emit destroyed();
}

void r_add_record_Window::on_add_record_Button_clicked() {
    string time = ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm").toStdString();
    string content_temp = ui->content_lineEdit->text().toStdString();
    int priority = ui->priority_spinBox->value();

    if (time.empty() || content_temp.empty()) {
        QMessageBox::warning(this, "警告", "请填写所有字段！");
        return;
    }


    reminder_temp_ptr_5->add_entry(time, content_temp, priority);
    reminder_temp_ptr_5->search("");
    reminder_temp_ptr_5->sort();
    emit refresh(); // 发送刷新信号
    close(); // 关闭窗口
}
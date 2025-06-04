#include "f_add_record_window.h"
#include "./ui_f_add_record_window.h"

f_add_record_Window::f_add_record_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::f_add_record_Window)
{
    ui->setupUi(this);
    setWindowTitle("添加一条账单记录...");
    // 绑定信号和槽
    // 连接退出按钮和关闭事件
    connect(ui->exit_Button, &QPushButton::clicked, this, &f_add_record_Window::close);
    // 连接添加按钮和添加记录槽函数
    connect(ui->add_Button, &QPushButton::clicked, this, &f_add_record_Window::on_add_record_Button_clicked);
}

f_add_record_Window::~f_add_record_Window()
{
    delete ui;
}

void f_add_record_Window::set_ptr(financenote *ptr) {
    // 设置指针函数
    finance_note_ptr_5 = ptr;
}

void f_add_record_Window::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    if (finance_note_ptr_5) {
        finance_note_ptr_5->close();
    }
    emit destroyed();
}

void f_add_record_Window::on_add_record_Button_clicked() {
    // 获取输入的日期、金额和类别
    // 日期
    string date = ui->dateEdit->date().toString("yyyy-MM-dd").toStdString();
    // 金额
    QString amount_temp = ui->amount_lineEdit->text();
    // 类别
    string category = ui->category_lineEdit->text().toStdString();

    // 检查输入是否为空
    if (date.empty() || amount_temp.isEmpty() || category.empty()) {
        QMessageBox::warning(this, "警告", "请填写所有字段！");
        return;
    }

    // 检查金额是否为正数
    double amount = ui->amount_lineEdit->text().toDouble();
    if (amount <= 0) {
        QMessageBox::warning(this, "警告", "金额必须大于0！");
        return;
    }
    // 将记录加入记账本
    finance_note_ptr_5->add_entry(date, amount, category);
    finance_note_ptr_5->search("");
    finance_note_ptr_5->sort();
    emit refresh(); // 发送刷新信号
    close(); // 关闭窗口
}
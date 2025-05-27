#include "financenote_window.h"
#include "./ui_financenote_window.h"
#include "log.h"

Financenote_Window::Financenote_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Financenote_Window)
{
    ui->setupUi(this);
    setWindowTitle("桌面工具-记账本");
    connect(ui->exit_Button,&QPushButton::clicked,this, &Financenote_Window::close);
    connect(ui->search_Button, &QPushButton::clicked, this, &Financenote_Window::on_search_Button_clicked);
    connect(ui->add_record_Button, &QPushButton::clicked, this, &Financenote_Window::on_add_Button_clicked);
}

Financenote_Window::~Financenote_Window()
{
    delete ui;
}
//设置指针函数
void Financenote_Window::set_ptr(financenote *ptr) {
    finance_note_ptr_3 = ptr;
    display(); // 初始化时显示数据
}

void Financenote_Window::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    if (finance_note_ptr_3) {
        finance_note_ptr_3->close();
    }
    emit destroyed();
}

//搜索函数
void Financenote_Window::on_search_Button_clicked() {
    string month = ui->search_lineEdit->text().toStdString();
    if (month.empty()) {
        QMessageBox::warning(this, "警告", "请输入月份！");
        return;
    }else {
        finance_note_ptr_3->search(month);
    }
}

//添加记录函数
void Financenote_Window::on_add_Button_clicked(){
    f_add_record_Window *add_record_window = new f_add_record_Window(this);
    add_record_window->set_ptr(finance_note_ptr_3);
    add_record_window->show();
    connect(add_record_window,SIGNAL(refresh()), this,SLOT(display()) );
}

//显示
void Financenote_Window::display() {
    
}

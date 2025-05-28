#include "reminder_window.h"
#include "./ui_reminder_window.h"
#include "log.h"
#include <QTableWidget>
#include <QStringList>
#include <QMessageBox>

Reminder_Window::Reminder_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reminder_Window)
{
    ui->setupUi(this);
    setWindowTitle("桌面工具-日程提醒");
    ui->reminder_record_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->reminder_record_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->exit_Button,&QPushButton::clicked,this, &Reminder_Window::close);
}

Reminder_Window::~Reminder_Window()
{
    delete ui;
    for (QObject *child : children()) {
        *(azusa_log::log) << "正在析构子对象：" << child->objectName().toStdString() << endl;
        delete child; //析构子对象
    }
    *(azusa_log::log) << "日程提醒窗口已析构！" << endl;
}
//设置指针函数
void Reminder_Window::set_ptr(reminder *ptr) {
    reminder_temp_ptr_3 = ptr;
    if (!reminder_temp_ptr_3) {
        *(azusa_log::log) << "Error: 日程提醒指针为空!" << endl;
        return;
    }
    reminder_temp_ptr_3->search("");
    reminder_temp_ptr_3->sort(); // 确保数据已排序
    display(); // 初始化时显示数据
}

//关闭窗口事件
void Reminder_Window::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    reminder_temp_ptr_3->close();
    emit destroyed();
}

void Reminder_Window::display(){
    try{
        if(!reminder_temp_ptr_3){
            *(azusa_log::log) << "Error: 日程提醒指针为空!" << endl;
            QMessageBox::critical(this, "错误", "日程提醒指针为空，请先设置指针！");
            return;
        }else{
            ui->reminder_record_table->setRowCount(0);
            auto search_result = reminder_temp_ptr_3->get_search_result();
            int size = search_result.size();
            ui->reminder_record_table->setRowCount(size);
            ui->reminder_record_table->setColumnCount(3);
            ui->reminder_record_table->setHorizontalHeaderLabels(QStringList() << "时间" << "内容" << "优先级");

            *(azusa_log::log) << "日程提醒行数为：" << size << endl;

            for (int row = 0; row < size ; ++row){
                const auto &temp = search_result[row];
                ui->reminder_record_table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(temp.time)));
                ui->reminder_record_table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(temp.content)));
                ui->reminder_record_table->setItem(row, 2, new QTableWidgetItem(QString::number(temp.priority)));
            }
            *(azusa_log::log) << "日程提醒表格已更新！" << endl;
        }
    }catch(const std::exception &e) {
        *(azusa_log::log) << "Error: " << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
        return;
    }
}

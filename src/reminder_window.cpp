#include "reminder_window.h"
#include "./ui_reminder_window.h"
#include "log.h"
#include <QTableWidget>
#include <QStringList>
#include <QMessageBox>

#include "formatcheck.h"

Reminder_Window::Reminder_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reminder_Window)
{
    ui->setupUi(this);
    setWindowTitle("桌面工具-日程提醒");
    ui->reminder_record_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->reminder_record_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->exit_Button,&QPushButton::clicked,this, &Reminder_Window::close);
    connect(ui->search_Button, &QPushButton::clicked, this, &Reminder_Window::on_search_Button_clicked, Qt::UniqueConnection);
    connect(ui->add_record_Button, &QPushButton::clicked, this, &Reminder_Window::on_add_Button_clicked);
    connect(ui->clear_Button, &QPushButton::clicked, this, &Reminder_Window::on_clear_Button_clicked);
    connect(ui->add_old_record_Button, &QPushButton::clicked, this, &Reminder_Window::on_move_to_old_Button_clicked);
    connect(ui->old_record_Button, &QPushButton::clicked,this ,&Reminder_Window::on_change_to_old_Button_clicked);
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
    // 初始化时搜索所有记录
    reminder_temp_ptr_3->set_index_status(true); // 设置索引状态为true
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

void Reminder_Window::on_search_Button_clicked() {
    try {
        string date = ui->search_lineEdit->text().toStdString();
        if (is_valid_date(date)) {
            if (!reminder_temp_ptr_3->get_index_status()) {
                date = "-" + date; // 如果索引状态为false，添加'-'前缀
            }
            reminder_temp_ptr_3->search(date);
            reminder_temp_ptr_3->sort();
            display();
        }else {
            QMessageBox::warning(this, "输入错误", "请输入正确的日期格式（YYYY-MM-DD）！");
            *(azusa_log::log) << "输入的日期格式不正确：" << date << endl;
        }
        *(azusa_log::log) << "日程提醒搜索函数已被调用" << endl;
    } catch (const std::exception &e) {
        *(azusa_log::log) << "Error: " << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
    }
}

void Reminder_Window::on_add_Button_clicked() {
    try {
        r_add_record_Window *add_record_window = new r_add_record_Window(this);
        add_record_window->set_ptr(reminder_temp_ptr_3);
        add_record_window->show();
        reminder_temp_ptr_3->set_index_status(true); // 设置索引状态为true
        ui->old_record_Button->setText("查看回收站");
        reminder_temp_ptr_3->search(reminder_temp_ptr_3->get_index_status() ? "" : "-");
        reminder_temp_ptr_3->sort(); // 确保数据已排序
        display(); // 显示最新数据
        connect(add_record_window, SIGNAL(refresh()), this, SLOT(display()) );
    } catch (const std::exception &e) {
        *(azusa_log::log) << "Error(reminder::on_add_Button_clicked): " << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
    }
}

void Reminder_Window::on_clear_Button_clicked() {
    try {
        ui->search_lineEdit->clear();
        reminder_temp_ptr_3->search(reminder_temp_ptr_3->get_index_status() ? "" : "-");
        reminder_temp_ptr_3->sort();
        display();
        *(azusa_log::log) << "日程提醒已清空搜索结果！显示所有记录" << endl;
    } catch (const std::exception &e) {
        *(azusa_log::log) << "Error: (reminder_window::on_clear_Button_clicked)" << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
    }
}

void Reminder_Window::on_move_to_old_Button_clicked() {
    try {
        reminder_temp_ptr_3->add_old_entries();
        reminder_temp_ptr_3->search(reminder_temp_ptr_3->get_index_status() ? "" : "-");
        reminder_temp_ptr_3->sort();
        display();
    }
    catch (const std::exception &e) {
        *(azusa_log::log) << "Error: (reminder_window::on_move_to_old_Button_clicked)" << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
    }
}

void Reminder_Window::on_change_to_old_Button_clicked() {
    try {
        if (ui->old_record_Button->text().toStdString() == "查看回收站") {
            reminder_temp_ptr_3->set_index_status(false); // 设置索引状态为false
            ui->old_record_Button->setText("查看有效记录");
        }else if (ui->old_record_Button->text().toStdString() == "查看有效记录") {
            reminder_temp_ptr_3->set_index_status(true);
            ui->old_record_Button->setText("查看回收站");
        }
        reminder_temp_ptr_3->search(reminder_temp_ptr_3->get_index_status() ? "" : "-");
        reminder_temp_ptr_3->sort();
        display();
    }catch (const std::exception &e) {
        *(azusa_log::log) << "Error: (reminder_window::on_change_to_old_Button_clicked)" << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
    }
}

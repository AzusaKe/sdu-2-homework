#include "financenote_window.h"
#include "./ui_financenote_window.h"
#include "log.h"
#include <QTableWidget>
#include <QStringList>

#include "formatcheck.h"

Financenote_Window::Financenote_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Financenote_Window)
{
    ui->setupUi(this);
    setWindowTitle("桌面工具-记账本");
    ui->financenote_record_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->financenote_record_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->exit_Button,&QPushButton::clicked,this, &Financenote_Window::close);
    connect(ui->search_Button, &QPushButton::clicked, this, &Financenote_Window::on_search_Button_clicked,Qt::UniqueConnection);
    connect(ui->add_record_Button, &QPushButton::clicked, this, &Financenote_Window::on_add_Button_clicked);
    connect(ui->clear_Button, &QPushButton::clicked, this, &Financenote_Window::on_clear_Button_clicked);
}

Financenote_Window::~Financenote_Window()
{
    delete ui;
    for (QObject *child : children()) {
        *(azusa_log::log) << "正在析构子对象：" << child->objectName().toStdString() << endl;
        delete child; //析构子对象
    }
    *(azusa_log::log) << "记账本窗口已析构！" << endl;
}
//设置指针函数
void Financenote_Window::set_ptr(financenote *ptr) {
    finance_note_ptr_3 = ptr;
    if (!finance_note_ptr_3) {
        *(azusa_log::log) << "Error: 记账本指针为空!" << endl;
        return;
    }
    finance_note_ptr_3->search("");
    finance_note_ptr_3->sort(); // 确保数据已排序
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
    if (is_valid_month(month)) {
        finance_note_ptr_3->search(month);
        finance_note_ptr_3->sort();
        display();
    }else {
        QMessageBox::warning(this, "输入错误", "请输入正确的日期格式（YYYY-MM）！", QMessageBox::Ok);
        *(azusa_log::log) << "输入的日期格式不正确：" << month << endl;
    }
    *(azusa_log::log) << "记账本搜索函数已被调用" << endl;
}

//添加记录函数
void Financenote_Window::on_add_Button_clicked(){
    try {
        f_add_record_Window *add_record_window = new f_add_record_Window(this);
        add_record_window->set_ptr(finance_note_ptr_3);
        add_record_window->show();
        connect(add_record_window,SIGNAL(refresh()), this,SLOT(display()) );
    }catch (const std::exception& e) {
        *(azusa_log::log) << "Error(financenote::on_add_Button_clicked): " << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
    }

}

//显示
void Financenote_Window::display() {
    try {double total = 0.0;
        if (!finance_note_ptr_3) {
            *(azusa_log::log) << "Error: 记账本指针为空!" << endl;
        } else {
            ui->financenote_record_table->setRowCount(0); // 清空表格内容
            auto search_results = finance_note_ptr_3->get_search_result();
            ui->financenote_record_table->setRowCount(search_results.size());
            ui->financenote_record_table->setColumnCount(3);
            ui->financenote_record_table->setHorizontalHeaderLabels({"日期", "金额", "类别"});

            *(azusa_log::log) << "记账本行数为：" << search_results.size() << endl;

            for (int row = 0; row < search_results.size(); ++row) {
                const auto &record = search_results[row];
                ui->financenote_record_table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(record.date)));
                ui->financenote_record_table->setItem(row, 1, new QTableWidgetItem(QString::number(record.amount, 'f', 2))); // 保留两位小数
                total += record.amount; // 累加金额
                ui->financenote_record_table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(record.category)));
            }
            ui->display_label->setText("总金额：" + QString::number(total, 'f', 2) + " 元");
            *(azusa_log::log) << "记账本数据已显示！" << endl;
        }
    } catch (const std::bad_alloc& e) {
        *(azusa_log::log) << "内存分配错误(financenote_window::display): " << e.what() << endl;
        QMessageBox::critical(this, "内存错误", "内存分配失败，请检查系统资源。");
    } catch (const std::exception& e) {
        *(azusa_log::log) << "Error:(financenote_window::display): " << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
    }
}

void Financenote_Window::on_clear_Button_clicked() {
    try {
        ui->search_lineEdit->clear();
        finance_note_ptr_3->search("");
        finance_note_ptr_3->sort();
        display();
        *(azusa_log::log) << "已清除搜索条件，显示所有记录。" << endl;
    }catch (const std::exception& e) {
        *(azusa_log::log) << "Error(financenote_window::on_clear_Button_clicked): " << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
    }

}

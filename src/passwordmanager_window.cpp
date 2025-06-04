#include "passwordmanager_window.h"
#include "./ui_passwordmanager_window.h"
#include "log.h"

Passwordmanager_Window::Passwordmanager_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Passwordmanager_Window)
{
    ui->setupUi(this);
    setWindowTitle("桌面工具-密码管理器");
    ui->passwordmanager_record_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->passwordmanager_record_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->exit_Button,&QPushButton::clicked,this, &Passwordmanager_Window::close);
    connect(ui->search_Button, &QPushButton::clicked, this, &Passwordmanager_Window::on_search_Button_clicked, Qt::UniqueConnection);
    connect(ui->add_record_Button, &QPushButton::clicked, this, &Passwordmanager_Window::on_add_Button_clicked);
    connect(ui->clear_Button, &QPushButton::clicked, this, &Passwordmanager_Window::on_clear_Button_clicked);

}

Passwordmanager_Window::~Passwordmanager_Window()
{
    delete ui;
    for (QObject *child : children()) {
        *(azusa_log::log) << "正在析构子对象：" << child->objectName().toStdString() << endl;
        delete child; //析构子对象
    }
    *(azusa_log::log) << "密码管理器窗口已析构！" << endl;
}
//设置指针函数
void Passwordmanager_Window::set_ptr(passwordmanager *ptr) {
    password_manager_ptr_4 = ptr;
    if (!password_manager_ptr_4) {
        *(azusa_log::log) << "Error: 密码管理器指针为空!" << endl;
        return;
    }
    password_manager_ptr_4->search("");
    password_manager_ptr_4->sort(); // 确保数据已排序,只在全部显示时使用
    display(); // 初始化时显示数据
}

void Passwordmanager_Window::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    if (password_manager_ptr_4) {
        password_manager_ptr_4->close();
    }
    emit destroyed();
}

void Passwordmanager_Window::display() {
    try {
        if (!password_manager_ptr_4) {
            *(azusa_log::log) << "Error: 密码管理器指针为空！" << endl;
        }else {
            ui->passwordmanager_record_table->setRowCount(0);
            auto search_results = password_manager_ptr_4->get_search_result();
            ui->passwordmanager_record_table->setRowCount(search_results.size());
            ui->passwordmanager_record_table->setColumnCount(3);
            ui->passwordmanager_record_table->setHorizontalHeaderLabels({"网站名", "用户名", "密码"});

            *(azusa_log::log) << "密码管理器行数为：" << search_results.size() << endl;

            for (int row = 0;row < search_results.size(); ++row) {
                const auto &record = search_results[row];
                ui->passwordmanager_record_table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(record.site_name)));
                ui->passwordmanager_record_table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(record.username)));
                ui->passwordmanager_record_table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(password_manager_ptr_4->decoder(record.password))));
            }
            ui->display_label->setText("密码管理器已更新！共有 " + QString::number(search_results.size()) + " 条记录。");
            *(azusa_log::log) << "密码管理器显示函数已更新！" << endl;
        }
    }catch (const std::bad_alloc& e) {
        *(azusa_log::log) << "内存分配错误(passwordmanager_window::display): " << e.what() << endl;
        QMessageBox::critical(this, "内存错误", "内存分配失败，请检查系统资源。");
    } catch (const std::exception& e) {
        *(azusa_log::log) << "Error:(passwordmanager_window::display): " << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
    }
}

void Passwordmanager_Window::on_search_Button_clicked() {
    try {
        string site_name = ui->search_lineEdit->text().toStdString();
        if (site_name.empty()) {
            QMessageBox::warning(this, "输入错误", "请输入网站名进行搜索！", QMessageBox::Ok);
            *(azusa_log::log) << "搜索网站名为空，未进行搜索。" << endl;
            return;
        }
        password_manager_ptr_4->search(site_name);// 调用搜索函数
        display();
        *(azusa_log::log) << "密码管理器搜索函数已被调用" << endl;
    }catch (const std::exception& e) {
        *(azusa_log::log) << "Error(passwordmanager_window::on_search_Button_clicked): " << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
    }
}

void Passwordmanager_Window::on_add_Button_clicked() {
    try {
        p_add_record_Window *add_record_window = new p_add_record_Window(this);
        add_record_window->set_ptr(password_manager_ptr_4);
        add_record_window->show();
        connect(add_record_window, SIGNAL(refresh()), this, SLOT(display()));
    } catch (const std::exception& e) {
        *(azusa_log::log) << "Error(passwordmanager_window::on_add_Button_clicked): " << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
    }
}

void Passwordmanager_Window::on_clear_Button_clicked() {
    try {
        ui->search_lineEdit->clear();
        password_manager_ptr_4->search(""); // 清空搜索结果
        password_manager_ptr_4->sort(); // 确保数据已排序
        display(); // 更新显示
        *(azusa_log::log) << "密码管理器已清空搜索条件。" << endl;
    }catch (const std::exception& e) {
        *(azusa_log::log) << "Error(passwordmanager_window::on_clear_Button_clicked): " << e.what() << endl;
        QMessageBox::critical(this, "错误", QString::fromStdString(e.what()));
    }

}
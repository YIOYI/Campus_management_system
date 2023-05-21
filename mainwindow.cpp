
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tabwidget = new TabWidget;
    connect(ui->log_on,&QPushButton::clicked,this,&MainWindow::detect_input_code);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ready()
{
    All_students_information.get_students_information(); //将所有学生信息从文件中读入
    show();
}

void MainWindow::detect_input_code()
{
    int currentID = (ui->select_ID->currentText()).toInt();
    int index = All_students_information.getindex(currentID);
    int rightcode = All_students_information.students_information()[index].getpassword();
    qDebug()<<rightcode;
    qDebug()<<(ui->code_lineedit->text()).toInt();
    if(rightcode==(ui->code_lineedit->text()).toInt())
    {
        current_user.getID() = currentID;
        current_user.getpassword() = rightcode;
        current_user.getname() = All_students_information.students_information()[index].getname();
        current_user.get_perevents();
        logon_to_main();
    }
    else
        ui->label_wrong->setText("账号或者密码错误");
}


 void MainWindow::logon_to_main()
{
    tabwidget->init(&current_user);
    this->hide();//关闭登录界面
 }





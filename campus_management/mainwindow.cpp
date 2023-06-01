
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("登录界面");
    tabwidget = new TabWidget;
    current_user = new Person;
    connect(ui->log_on,&QPushButton::clicked,this,&MainWindow::detect_input_code);
    connect(ui->select_ID,&QComboBox::currentIndexChanged,this,&MainWindow::select_change);
    connect(tabwidget,&TabWidget::quit_tabwidget,this,&MainWindow::clean);
}

MainWindow::~MainWindow()
{
    delete tabwidget;
    delete current_user;
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
        current_user->getID() = currentID;
        current_user->getpassword() = rightcode;
        current_user->getname() = All_students_information.students_information()[index].getname();

        QString log_on;
        log_on.append(current_user->getname()).append("登录学生管理系统成功\n");
        current_user->inputlog(log_on);

        current_user->get_perevents();
        logon_to_main();
    }
    else
        ui->label_wrong->setText("账号或者密码错误");
}

void MainWindow::logon_to_main()
{
    _Time *ti=new _Time;
    ti->time_set(1,1,0);
    tabwidget->init(current_user,ti);
    this->hide();//关闭登录界面
 }

void MainWindow::select_change()
{
    ui->code_lineedit->clear();
    QString picture_address=":/picture/";
    picture_address += ui->select_ID->currentText();
    picture_address += ".png";
    QImage image(picture_address);
    ui->head_sculpture->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::clean()
{
    qDebug()<<"重新登录";
    tabwidget->close();
    delete tabwidget;
    delete current_user;
    tabwidget = new TabWidget;
    current_user = new Person;
    connect(tabwidget,&TabWidget::quit_tabwidget,this,&MainWindow::clean);
    this->show();
}













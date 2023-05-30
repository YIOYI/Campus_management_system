
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("登录界面");
    current_user = new Person;
    connect(ui->log_on,&QPushButton::clicked,this,&MainWindow::detect_input_code);
    connect(ui->select_ID,&QComboBox::currentIndexChanged,this,&MainWindow::select_change);
}

MainWindow::~MainWindow()
{
    delete tabwidget;
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
        current_user->get_perevents();
        current_user->Tag = STUDENT;
        logon_to_main();
    }
    else if (ui->select_ID->currentText() == "88888888" && ui->code_lineedit->text() == "88888888")
    {
        current_user->getID() = 88888888;
        current_user->getpassword() = 88888888;
        current_user->getname() = "管理员";
        qDebug() << "正在读取";
        current_user->get_admin_perevents();
        qDebug() << "读取结束";
        current_user->Tag = ADMIN;
        logon_to_main();
    }
    else
        ui->label_wrong->setText("账号或者密码错误");
}


 void MainWindow::logon_to_main()
{
    tabwidget = new TabWidget;
    connect(tabwidget,&TabWidget::quit_tabwidget,this,&MainWindow::clean);
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
    current_user = new Person;
    this->show();
}

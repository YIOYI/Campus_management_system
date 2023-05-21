
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QLineEdit>
#include<QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QGridLayout>  //排版 网格状布局
#include"Person.h"
#include"Event.h"
#include"tabwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//登录界面
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ready();
signals:
    void right();
    void wrong();

public slots:
    void detect_input_code();
    void logon_to_main();
protected:
    Ui::MainWindow *ui;
private:
    Person current_user;//当前登录用户信息
    TabWidget *tabwidget;
    Students All_students_information;
    Curriculum Total_curriculums; //整个课表，包括学生选修必修以及集体事务
    //Form1 form1;
};

#endif // MAINWINDOW_H

#ifndef FORM1_H
#define FORM1_H

#include <QWidget>
#include<QMessageBox>
#include<QCloseEvent>
#include <QMouseEvent>
#include <QToolTip>
#include <QLabel>
#include<unordered_map>
#include <QCompleter>
#include "ui_form1.h"
#include"insert_event.h"
#include"Person.h"
#include"Event.h"

namespace Ui {
class Form_events;
}




class Form1 : public QWidget
{
    Q_OBJECT

public:
    _Time* ti;
    explicit Form1(QWidget *parent = nullptr);
    void init_current_user(QString,int);
    ~Form1();
    bool isexist(Event &a);/*判断当前事件在其他周是否有属性一模一样的事件，即时间姓名地点一样*/
signals:
    void select_week();//用户选择第几周的课表
public slots:
    void init_form1(Person *,_Time *);//登录成功后初始化用户界面
    void show_percurriculum();// 输出课表
    void check_detial(int r, int c);//点击单个单元格显示事件具体信息
    void skip_to_dialog(int r,int c);//双击单元格，跳转到修改窗口。
    void doubleclick_set(int r,int c);//双击非空格单元格，初始化右下角事件增删框
    void dialog_add_event(QAbstractButton*);
    void handle_event();/*增删事件*/
    void clear_frame2();/*清空事务增删表*/
    void auto_give_end(){ui->comboBox_end_time->setCurrentIndex(ui->comboBox_start_time->currentIndex());};/*下拉框槽函数*/
    void auto_give_start(){ui->comboBox_start_time->setCurrentIndex(ui->comboBox_end_time->currentIndex());};/*下拉框槽函数*/
    void seek_position();/*修改事件时定位事件*/
    void add_event(Event &);
    void revise_event(Event &);
    void delete_event(Event &);
    void wideget_control(bool);
    void insert_ID();

    void set_time(const QString &tmp);
    void timeUpdate();
    void time_pause();
    void FF_hour();
    void FF_day();
    void set_week();

private:

    Map *m;      //地图数据
    arrayindex event_position;
    int positioning_tag;
    vector<int> ID;
    QString label_ID;
    Ui::Form_events *ui;
    Person* current_user;  //目前正在登录的学生
    Dialog insert_dialog; //增加事件
};

#endif // FORM1_H

#ifndef _ADMINWDT_H_
#define _ADMINWDT_H_

#include <QWidget>
#include<QMessageBox>
#include<QCloseEvent>
#include <QMouseEvent>
#include <QToolTip>
#include <QLabel>
#include<unordered_map>
#include "ui_adminwdt.h"
#include"insert_event.h"
#include"Person.h"
#include"Event.h"


namespace Ui {
class adminwdt;
}

class adminwdt : public QWidget
{
    Q_OBJECT

public:
    explicit adminwdt(QWidget *parent = nullptr);
    void init_current_user(QString,int);
    ~adminwdt();
    bool isexist(Event &a);/*判断当前事件在其他周是否有属性一模一样的事件，即时间姓名地点一样*/
    void init_week_sel_combo (vector<int> week);
    void init_ID_sel_combo (vector<int> student_ID);
    void change_week_sel_combo (int);
    void change_ID_sel_combo(int);

signals:
    void select_week();//用户选择第几周的课表
public slots:
    void init_adminwdt(Person *);//登录成功后初始化用户界面
    void show_percurriculum();// 输出课表
    void add_event(Event &);
    void delete_event(Event &);
private:
    position event_position;
    int positioning_tag;
    vector<int> ID;
    QString label_ID;
    int refresh;//刷新信号
    Ui::adminwdt *ui;
    Person* current_user;  //目前正在登录的学生
    Dialog insert_dialog; //增加事件
};

#endif // _ADMINWDT_H_

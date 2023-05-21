#ifndef FORM1_H
#define FORM1_H

#include <QWidget>
#include<QMessageBox>
#include<QCloseEvent>
#include <QMouseEvent>
#include <QToolTip>
#include <QLabel>
#include<unordered_map>
#include "ui_form1.h"
#include"insert_event.h"
#include"Person.h"
#include"Event.h"

namespace Ui {
class Form_events;
}


struct col{
    int col_index;
    int count;
    int pad;
};

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = nullptr);
    void init_current_user(QString,int);
    ~Form1();
signals:
    void select_week();//用户选择第几周的课表
public slots:
    void init_form1(Person *);//登录成功后初始化用户界面
    void show_percurriculum();// 输出课表
    void check_detial(int r, int c);//点击单个单元格显示事件具体信息
    void skip_to_dialog(int r,int c);//双击单元格，跳转到修改窗口。
    int add_event(QAbstractButton*);
    void update_event();/*增删事件*/
    void clear_frame2();/*清空事务增删表*/
    void auto_give_end(){ui->comboBox_end_time->setCurrentIndex(ui->comboBox_start_time->currentIndex());};
    void auto_give_start(){ui->comboBox_start_time->setCurrentIndex(ui->comboBox_end_time->currentIndex());};
private:

    Ui::Form_events *ui;
    Person* current_user;  //目前正在登录的学生
    unordered_map <int,col> cell_events; //通过单元格行列找到事件的数组下标
    Dialog insert_dialog; //增加事件
};

#endif // FORM1_H

#ifndef FORM3_H
#define FORM3_H

#include <QWidget>
#include<QMessageBox>
#include<QCloseEvent>
#include "ui_form3.h"
#include<QImage>
#include"Person.h"
#include "Alarm.h"
#include <QStandardItemModel>


namespace Ui {
class Form3;
}

class Form3 : public QWidget
{
    Q_OBJECT

signals:
    void QUIT_form();
    void jmp_to_guide(Building);
    void alarm_ring();
public slots:
    void set_time(const QString &tmp);
    void timeUpdate();
    void time_pause();
    void FF_hour();
    void FF_day();
    void set_week();
public:
    _Time *ti;
    explicit Form3(QWidget *parent = nullptr);
    ~Form3();
    void init_form3(Person *,_Time *ti);
    void search();
    void mycellenter(int row, int column);
    void search_outcome(int row,int column);
    void quit();
    void correct();
    void AlarmTable_init();
    void AddAlarmRow (const int row, Alarm& single);
    void on_UseCheck_activated (const QStandardItem* item);
    void on_TimeCmb_activated (const int Index);
    void on_TagCmb_activated (const int Index);
    void on_WeekCmb_activated (const int Index);
    void on_ThingCmb_activated (const int Index);
    void on_ClassCmb_activated (const QString &text);
    void on_AfterclassCmb_activated (const QString &text);
    void on_TemporaryCmb_activated(const QString& text);
    void NoneLineedit_textChanged (const QString& text);
    int find_alarm_index (int ID);
    void Ring (Alarm &single);
    QString alarm_to_format_QString(Event &temp);
    bool format_QString_to_Event(const QString &text, Event &tar);
    void keysearch();//关键字搜索

    void detect_alarm ();
    void read_alarm_file (void);
    void write_alarm_file (void);
    void show_log(int);//显示学生消息通知
    void show_one_day_event();//展示当天所有事务

private slots:
    void on_pushButton_clicked();
    void on_deleteButton_clicked();
private:
    Person* current_user;  //目前正在登录的学生
    int previousColorRow;
    vector<QString> search_select;/*与搜索匹配的事件名称*/
    vector<Alarm> all_alarm; //所有闹钟
    QStandardItemModel* model;
    Ui::Form3 *ui;
};

#endif // FORM3_H

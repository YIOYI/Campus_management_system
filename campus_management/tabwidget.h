#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include<QMessageBox>
#include<QCloseEvent>
#include"form1.h"
#include"form2.h"
#include"form3.h"

namespace Ui {
class TabWidget;
}

class TabWidget : public QTabWidget
{
    Q_OBJECT

signals:
    void quit_tabwidget();
public slots:
    void time_update();
    void alarm_guide(Building dest);
public:
    QTimer*timer_calendar;
    _Time *ti;  /*虚拟时间*/
    TimePause *tp;
    explicit TabWidget(QWidget *parent = nullptr);
    ~TabWidget();
    void init(Person *,_Time *);
    //void closeEvent(QCloseEvent *);
    void save();/*退出时保存数据*/
    void quit();
private:
    Form1 *page1;
    Form2 *page2;
    Form3 *page3;
    Person *current_user;
    Ui::TabWidget *ui;
};


#endif // TABWIDGET_H

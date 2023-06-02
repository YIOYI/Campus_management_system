#include "tabwidget.h"
#include "ui_tabwidget.h"

TabWidget::TabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabWidget)
{
    ui->setupUi(this);
    page1 =new Form1;
    page2 =new Form2;
    page3 =new Form3;
    addTab(page3,"学生主页");
    addTab(page1,"事件处理系统");
    addTab(page2,"导航系统");

    connect(page3,&Form3::QUIT_form,this,&TabWidget::quit);
    connect(this,&TabWidget::currentChanged,page3,&Form3::show_log);

    setWindowTitle("学生事务管理系统");
    setStyleSheet(
        "QTabBar::tab{"
        "    min-width:28ex;"
        "    min-height:10ex;"
        "}"
        );
}

TabWidget::~TabWidget()
{
    current_user->update_perevents();
    delete page3;
    delete page2;
    delete page1;
    delete ui;
}

void TabWidget::init(Person* user_information,_Time *t)
{
    this->ti=t;
    ti->time_now();
    current_user = user_information;
    page1->init_form1(current_user,ti);
    page2->init_form2(current_user,ti);
    page3->init_form3(current_user);
    show();

    time_update();
    QTimer*timer_calendar = new QTimer(this);
    timer_calendar->start(1000);
    connect(timer_calendar,&QTimer::timeout,this,&TabWidget::time_update);

}

void TabWidget::quit()
{
    qDebug()<<"退出 tab";
    emit quit_tabwidget();
}

void TabWidget::time_update()
{
    QString tmp;
    QString day;
    ti->time_now();
    switch (ti->day())
    {
    case 1: day="周一"; break;
        case 2: day="周二"; break;
        case 3: day="周三"; break;
        case 4: day="周四"; break;
        case 5: day="周五"; break;
        case 6: day="周六"; break;
        case 7: day="周日"; break;
    }

    tmp=day+QString("/%1点").arg(ti->hour());
    page1->set_time(tmp);
    page2->set_time(tmp);
}

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
    connect(page3,&Form3::jmp_to_guide,this,&TabWidget::alarm_guide);
    connect(page3,&Form3::alarm_ring,this,&TabWidget::time_update);



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

    delete page3;
    delete ui;
}

void TabWidget::init(Person* user_information,_Time *t)
{
    this->ti=t;
    tp=ti->tp;
    ti->time_now();
    current_user = user_information;
    page1->init_form1(current_user,ti);
    page2->init_form2(current_user,ti);
    page3->init_form3(current_user,ti);
    show();


    time_update();
    timer_calendar = new QTimer(this);
    timer_calendar->start(1000);
    connect(timer_calendar,&QTimer::timeout,this,&TabWidget::time_update);
    connect(timer_calendar,&QTimer::timeout,page3,&Form3::detect_alarm);
    connect(ti->tp,&TimePause::t_pause,this,&TabWidget::time_update);
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
    qDebug()<<"tab时间"<<ti->week()<<ti->day()<<ti->hour();
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
    page3->set_time(tmp);
    if(ti->is_init()==0)
        ti->set_init();
}
void TabWidget::alarm_guide(Building dest)
{
    setCurrentIndex(2);
    page2->guide_for_alarm(dest);
}

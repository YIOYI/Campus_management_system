#include "tabwidget.h"
#include "ui_tabwidget.h"

TabWidget::TabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabWidget)
{
    ui->setupUi(this);

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
    qDebug()<<"退出";
    current_user->update_perevents();
    delete page3;
    delete page2;
    delete page1;
    delete ui;
}

void TabWidget::init(Person* user_information,_Time *t)
{
    this->ti=t;
    tp=ti->tp;
    ti->time_now();
    current_user = user_information;
    
    if (current_user->Tag == STUDENT)
    {
        page1 =new Form1;
        page2 =new Form2;
        page3 =new Form3;
        addTab(page3,"学生主页");
        addTab(page1,"事件处理系统");
        addTab(page2,"导航系统");

        connect(page3,&Form3::QUIT_form,this,&TabWidget::quit);
        connect(page3,&Form3::jmp_to_guide,this,&TabWidget::alarm_guide);
        connect(page3,&Form3::alarm_ring,this,&TabWidget::time_update);
        connect(this,&TabWidget::update_one_day_event,this->page3,&Form3::show_one_day_event);


        page1->init_form1(current_user,ti);
        page2->init_form2(current_user,ti);
        page3->init_form3(current_user,ti);


        time_update();
        timer_calendar = new QTimer(this);
        timer_calendar->start(1000);
        connect(timer_calendar,&QTimer::timeout,this,&TabWidget::time_update);
        connect(timer_calendar,&QTimer::timeout,page3,&Form3::detect_alarm);
        connect(ti->tp,&TimePause::t_pause,this,&TabWidget::time_update);
    }
    else if (current_user->Tag == ADMIN)
    {
        page4 = new adminwdt;
        addTab(page4, "管理员界面");
        page4->init_adminwdt(current_user);
    }


    show();



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

    if(ti->hour()==20||ti->hour()==0)
        emit update_one_day_event();
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

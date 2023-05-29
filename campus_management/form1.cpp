#include "form1.h"
#include "ui_form1.h"
#include"QDebug"
#include"QModelIndex"

Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_events)
{
    ui->setupUi(this);
    refresh = 0;
    positioning_tag =0;
    event_position.count = -1;

    ui->widget->hide();
    ui->tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
    ui->radioButton_revise->setCheckable(false);
    ui->frame->setStyleSheet("#frame{border-image: url(:/picture/who.jpg)}"); //添加背景图片
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,0)");//设置背景为透明
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgba(0,0,0,0);width:130px;color:black;border-color:black}");//调整列头(时间点)
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgba(0,0,0,0);height:59px;color:black;border-color:black}");//调整行头(星期几)
    ui->tableWidget->setMouseTracking(true);

    connect(ui->select_week,&QComboBox::currentIndexChanged,this,&Form1::show_percurriculum);/*更换课表显示的周数*/
    connect(ui->tableWidget,&QTableWidget::cellClicked, this, &Form1::check_detial);/*单击单元格查看该事件细节，传递参数为该单元格的行数列数*/
    connect(ui->tableWidget,&QTableWidget::cellDoubleClicked,this,&Form1::doubleclick_set);/*双击单元格添加或者修改事件，传递参数为该单元格的行数列数*/
    connect(insert_dialog.ui->buttonBox,&QDialogButtonBox::clicked,this,&Form1::dialog_add_event);/*修改确认后事件添加成功*/
    connect(ui->pushButton_ok,&QPushButton::clicked,this,&Form1::handle_event);/*点击确定按钮结束增删事件，处理用户输入*/
    connect(ui->comboBox_end_time,&QComboBox::currentIndexChanged,this,&Form1::auto_give_start);/*选择开始时间自动生成结束时间*/
    connect(ui->comboBox_start_time,&QComboBox::currentIndexChanged,this,&Form1::auto_give_end);/*选择结束时间自动生成开始时间*/
    connect(ui->pushButton_refresh,&QPushButton::clicked,this,&Form1::show_percurriculum);/*刷新课表*/
    connect(ui->pushButton_clean,&QPushButton::clicked,this,&Form1::clear_frame2);/*清空事件增删框*/
    connect(ui->pushButton_getevent,&QPushButton::clicked,this,&Form1::seek_position);/*定位事件*/
    connect(ui->radioButton_event3,&QRadioButton::toggled,this,&Form1::wideget_control);
    connect(ui->pushButton_getID,&QPushButton::clicked,this,&Form1::insert_ID);

    connect(ui->bt_pause,&QPushButton::clicked,this,&Form1::time_pause);
    connect(ui->bt_hour,&QPushButton::clicked,this,&Form1::FF_hour);
    connect(ui->bt_day,&QPushButton::clicked,this,&Form1::FF_day);
    connect(ui->cb_week,&QComboBox::currentIndexChanged,this,&Form1::set_week);
}

Form1::~Form1()
{
    delete ui;
}

void Form1::init_current_user(QString personal_name,int personal_ID)
{
    current_user->name=personal_name;
    current_user->ID=personal_ID;
}

void Form1::show_percurriculum()
{
    ui->tableWidget->clearContents(); /*清空单元格内容*/
    int week=ui->select_week->currentIndex()+1; /*获取周数*/

    qDebug()<<"课表刷新";

    for (int day = 0; day < DAY; day++)
    {
        for (int i = 0; i < HOURS; i++) /*遍历事件*/
        {
            if(current_user->perEvents[day][i].size()!=0)
            {
                for(auto X:current_user->perEvents[day][i])
                {
                    bool is =false; /*判断该事件本周是否有*/
                    if(X.Tag==1||X.Tag==2)/*课程每周都有*/
                        is=true;
                    else
                    {
                        for(auto tempweek:X.weeks)
                            if(tempweek==week)
                            {
                                is=true;
                                break;
                            }
                    }

                    if(is)
                    {
                        for(int temphour =X.start.hour();temphour!=X.end.hour();temphour++)
                        {
                            ui->tableWidget->setItem(temphour-6,day,new QTableWidgetItem(X.name));
                            ui->tableWidget->item(temphour-6,day)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                            ui->tableWidget->item(temphour-6,day)->setForeground(Qt::black);
                        }
                        break;
                    }
                }
            }
        }
    }
}

void Form1::check_detial(int r, int c)
{
    QString detail;

    ui->event_detial->clear();
    int week = ui->select_week->currentIndex()+1;
    QTableWidgetItem* item = ui->tableWidget->item(r, c);
    if (item == nullptr)
       return;
    vector<int> index =current_user->find_index(week,c+1,r+6);
    detail.append("事件名称: ");
    if(index.size()>1)
    {
        for(auto count:index)
        {
            detail.append(current_user->perEvents[c][r][count].name).append(" ");
        }
    }
    else
        detail.append(current_user->perEvents[c][r][index[0]].name);

    detail.append("\n");
    detail.append("持续时间: ");
    detail.append(QString::number(current_user->perEvents[c][r][index[0]].start.hour(),10));
    detail.append(":00 -- ");
    detail.append(QString::number(current_user->perEvents[c][r][index[0]].end.hour(),10));
    detail.append(":00\n");
    detail.append("事件地点: ");
    detail.append("\n");
    detail.append("事件类型: ");
    switch(current_user->perEvents[c][r][index[0]].Tag)
    {
        case 1:detail.append("必修课");break;
        case 2:detail.append("选修课");break;
        case 3:detail.append("集体事务");break;
        case 4:detail.append("个人事务");break;
        case 5:detail.append("临时事务");break;
    }

    detail.append("\n");
    detail.append("事件周数: ");
    if(current_user->perEvents[c][r][index[0]].Tag==1 ||current_user->perEvents[c][r][index[0]].Tag==2)
    {
        detail.append("每周都有");
        detail.append("\n考试信息:");
    }

    else if(index.size()>1)
    {
        detail.append("各个事件不同，详细信息请在主页搜索");
    }
    else
    {
        for(auto a:current_user->perEvents[c][r][index[0]].weeks)
        {
            detail.append(QString::number(a));
            detail.append(" ");
        }
    }

    ui->event_detial->setText(detail);
}

void Form1::init_form1(Person *a,_Time *t)
{
    this->ti=t;
    current_user = a;
    insert_dialog.current_ID = current_user->ID;
    show_percurriculum();
}
void Form1::set_time(const QString &tmp)
{
    ui->cb_week->setCurrentIndex(ti->week()-1);
    ui->label_time->setText(tmp);
    if(ti->is_continue()==1)
        ui->bt_pause->setStyleSheet("border-image: url(:/picture/continue.png);color: rgba(255, 255, 255, 0);");
    else
        ui->bt_pause->setStyleSheet("border-image: url(:/picture/pause.png);color: rgba(255, 255, 255, 0);");
}
void Form1::timeUpdate()
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
    ui->label_time->setText(tmp);
    ui->cb_week->setCurrentIndex(ti->week()-1);
}
void Form1::time_pause()
{
    if(ti->is_continue()==0)
    {
        ti->time_continue();
    ui->bt_pause->setStyleSheet("border-image: url(:/picture/continue.png);color: rgba(255, 255, 255, 0);");
    }
    else
    {
        ti->time_suspend();
    ui->bt_pause->setStyleSheet("border-image: url(:/picture/pause.png);color: rgba(255, 255, 255, 0);");
    }
}
void Form1::FF_hour()
{
    ti->time_now();
    ti->time_set(ti->week(),ti->day(),ti->hour()+1);
    timeUpdate();
}
void Form1::FF_day()
{
    ti->time_now();
    ti->time_set(ti->week(),ti->day()+1,ti->hour());
    timeUpdate();
}
void Form1::set_week()
{
    ti->time_set(ui->cb_week->currentIndex()+1,1,0);
    timeUpdate();
}

void Form1::skip_to_dialog(int r,int c)
{
       insert_dialog.ui->lineEdit->clear();
       insert_dialog.ui->lineEdit_2->clear();
       insert_dialog.show();
       insert_dialog.row =r;
       insert_dialog.line=c;
}

int Form1::dialog_add_event(QAbstractButton* button)
{
    insert_dialog.ui->widget->hide();
    if(button == (QAbstractButton *)(insert_dialog.ui->buttonBox->button(QDialogButtonBox::Ok)))
    {
        Event temp;
        refresh =1;
        temp.name=insert_dialog.ui->lineEdit->text();
        temp.weeks.push_back(ui->select_week->currentIndex()+1);
        temp.start.day()=insert_dialog.line+1;
        temp.start.hour()=insert_dialog.row+6;
        temp.end.hour()=temp.start.hour()+1;

        if(insert_dialog.ui->comboBox->currentText()=="个人事务")
            temp.Tag=4;
        else if(insert_dialog.ui->comboBox->currentText()=="临时事务")
            temp.Tag=5;
        else
            temp.Tag=3;

        temp.ID.push_back(current_user->ID);
        temp.ID.insert(temp.ID.end(),insert_dialog.ID.begin(),insert_dialog.ID.end());

        if(!isexist(temp))
        {
            current_user->perEvents[insert_dialog.line][insert_dialog.row].push_back(temp);
            if(current_user->namequeue.find(temp.name)==current_user->namequeue.end())
                current_user->event_names.push_back(temp.name);
            current_user->namequeue[temp.name].push_back({insert_dialog.line,insert_dialog.row,(int)current_user->perEvents[insert_dialog.line][insert_dialog.row].size()});
        }//未找到属性一致的事件，新增事件


        //在课表上显示
        ui->tableWidget->setItem(insert_dialog.row,insert_dialog.line,new QTableWidgetItem(temp.name));
        ui->tableWidget->item(insert_dialog.row,insert_dialog.line)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->item(insert_dialog.row,insert_dialog.line)->setForeground(Qt::black);

    }

    return 0;
}

void Form1::handle_event()
{
    int operate_tag =0; /*用户选择操作的类型,1--add;2--revise;3--delete*/
    Event insert_event; /*储存用户输入的事件的信息*/
    QMessageBox msgBox;

    /*获取用户选择增删的事件类型*/
    if(ui->radioButton_event3->isChecked())
        insert_event.Tag = 3;
    else if(ui->radioButton_event4->isChecked())
        insert_event.Tag = 4;
    else if(ui->radioButton_event5->isChecked())
        insert_event.Tag = 5;
    else
    {
        msgBox.setWindowTitle("提示");
        msgBox.setText("未选择事件类型");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Ok || ret == QMessageBox::Cancel)
            return;
    }

    /*获取用户对该类型事件要进行的操作*/
    if(ui->radioButton_add->isChecked())
        operate_tag = 1;
    else if(ui->radioButton_revise->isChecked())
        operate_tag = 2;
    else if(ui->radioButton_delete->isChecked())
        operate_tag = 3;
    else
    {
        msgBox.setWindowTitle("提示");
        msgBox.setText("未选择要进行的操作");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Ok || ret == QMessageBox::Cancel)
            return;
    }

    /*获取用户输入的事件的信息*/
    if(ui->lineEdit_name->text().isEmpty())
    {
        msgBox.setWindowTitle("提示");
        msgBox.setText("事件名称不能为空");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Ok || ret == QMessageBox::Cancel)
            return;
    }

    if(ui->checkBox_week1->isChecked())
        insert_event.weeks.push_back(1);
    if(ui->checkBox_week2->isChecked())
        insert_event.weeks.push_back(2);
    if(ui->checkBox_week3->isChecked())
        insert_event.weeks.push_back(3);
    if(ui->checkBox_week4->isChecked())
        insert_event.weeks.push_back(4);
    if(ui->checkBox_week5->isChecked())
        insert_event.weeks.push_back(5);
    if(ui->checkBox_week6->isChecked())
        insert_event.weeks.push_back(6);
    if(ui->checkBox_week7->isChecked())
        insert_event.weeks.push_back(7);
    if(ui->checkBox_week8->isChecked())
        insert_event.weeks.push_back(8);
    if(ui->checkBox_week9->isChecked())
        insert_event.weeks.push_back(9);
    if(ui->checkBox_week10->isChecked())
        insert_event.weeks.push_back(10);
    if(ui->checkBox_week11->isChecked())
        insert_event.weeks.push_back(11);
    if(ui->checkBox_week12->isChecked())
        insert_event.weeks.push_back(12);
    if(ui->checkBox_week13->isChecked())
        insert_event.weeks.push_back(13);
    if(ui->checkBox_week14->isChecked())
        insert_event.weeks.push_back(14);
    if(ui->checkBox_week15->isChecked())
        insert_event.weeks.push_back(15);
    if(ui->checkBox_week16->isChecked())
        insert_event.weeks.push_back(16);


    insert_event.start.day()=ui->comboBox_day->currentIndex()+1;
    insert_event.start.hour()=ui->comboBox_start_time->currentIndex()+6;
    insert_event.name = ui->lineEdit_name->text();
    insert_event.end.hour()=insert_event.start.hour()+1;
    insert_event.periodicity = insert_event.weeks.size();
    insert_event.ID.push_back(current_user->ID);



    if(operate_tag == 1 && insert_event.periodicity!=0)
    {
        add_event(insert_event);
        clear_frame2();
    }

    else if(operate_tag == 2 && insert_event.periodicity!=0)
    {
        revise_event(insert_event);
        clear_frame2();
    }

    else if(operate_tag == 3)
    {
        delete_event(insert_event);
        clear_frame2();
    }
    ID.clear();
}

void Form1::add_event(Event & insert_event)
{
    qDebug()<<"add";
    QMessageBox msgBox;

    insert_event.ID.insert(insert_event.ID.end(),ID.begin(),ID.end());
    for(auto a:insert_event.ID)
        qDebug()<<a;

    if(insert_event.Tag == 3&&insert_event.ID.size()<2)
    {
        msgBox.setWindowTitle("提示");
        msgBox.setText("人数不够");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Ok)
            return;
    }

    if(refresh)
    {
        current_user->init_perevents_time_set();
        refresh=0;

    }
    seektime temp_time=current_user->iscollision(insert_event);

    if(temp_time.tag == 1)
    {
        if(!isexist(insert_event))
        {
            qDebug()<<"no exist";
            current_user->perEvents[insert_event.start.day()-1][insert_event.start.hour()-6].push_back(insert_event);
            if(current_user->namequeue.find(insert_event.name)==current_user->namequeue.end())
                current_user->event_names.push_back(insert_event.name);
            current_user->namequeue[insert_event.name].push_back({insert_event.start.day()-1,insert_event.start.hour()-6,(int)current_user->perEvents[insert_event.start.day()-1][insert_event.start.hour()-6].size()});
        }//未找到属性一致的事件，新增事件

        refresh=1;
        if(!positioning_tag)
        {
            msgBox.setWindowTitle("提示");
            msgBox.setText("添加成功");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            int ret = msgBox.exec();
            if(ret == QMessageBox::Ok)
                return;
        }
        else
        {
            positioning_tag = 0;
            msgBox.setWindowTitle("提示");
            msgBox.setText("修改成功");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            int ret = msgBox.exec();
            if(ret == QMessageBox::Ok)
                return;
        }
    }

    else if(temp_time.tag == 0)
    {
        QString tip;

        vector<seektime> idle_time = current_user->findidle(temp_time);/*找到最近的三个时间点*/
        if(temp_time.week != 0)
        {
            tip+="在第";tip+=QString::number(temp_time.week);tip+="周\n";
        }

        tip+="周";tip+=QString::number(temp_time.day);
        tip+="       ";
        tip+=QString::number(temp_time.hour);tip+=":00 ~ ";tip+=QString::number(temp_time.hour+1);tip+=":00\n";
        tip+="与其他事务发生冲突\n";
        tip+="距离冲突时间最近的三个时间点为:    \n";

        for(auto a:idle_time)
        {
            tip+="第";
            tip+=QString::number(a.week);
            tip+="周  星期";
            tip+=QString::number(a.day);
            tip+="  ";
            tip+=QString::number(a.hour);
            tip+=":00~";
            tip+=QString::number(a.hour+1);
            tip+=":00\n";
        }

        msgBox.setWindowTitle("提示");
        msgBox.setText(tip);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Ok)
            return;
    }

}

void Form1::revise_event(Event & insert_event)
{
    delete_event(current_user->perEvents[event_position.first_index][event_position.second_index][event_position.count]);/*删除已定位的事件*/
    add_event(insert_event);
    ui->radioButton_revise->setCheckable(false);
}

void Form1::delete_event(Event & insert_event)
{
    qDebug()<<"delete";
    Event tempevent;
    arrayindex temparray;
    QMessageBox msgBox;

    int count =0;
    qDebug()<<current_user->namequeue[insert_event.name].size();
    QString temp1;
    QString temp2;
    temp1.append(insert_event.name).append(QString::number(insert_event.Tag)).append(QString::number(insert_event.start.day())).append(QString::number(insert_event.start.hour()));

    for(auto &a:current_user->perEvents[insert_event.start.day()-1][insert_event.start.hour()-6])
    {
        if(a.name == insert_event.name && a.Tag == insert_event.Tag)
        {
            if(a.Tag==3&&a.ID[0]!=current_user->ID)
            {
                msgBox.setWindowTitle("提示");
                msgBox.setText("无权限修改该集体事务");
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.setDefaultButton(QMessageBox::Ok);
                int ret = msgBox.exec();
                if(ret == QMessageBox::Ok)
                    return;
            }
            refresh=1;
            current_user->perEvents[insert_event.start.day()-1][insert_event.start.hour()-6].erase(current_user->perEvents[insert_event.start.day()-1][insert_event.start.hour()-6].begin()+count);
            if((int)current_user->namequeue[insert_event.name].size()>1)/*判断该名称是否还有其他事件*/
            {
                for(int i=0;i<(int)current_user->namequeue[insert_event.name].size();i++)/*删除该容器已经删除的事件的下标*/
                {
                    temparray = current_user->namequeue[insert_event.name][i];
                    tempevent = current_user->perEvents[temparray.first_index][temparray.second_index][temparray.count-1];
                    temp2.clear();
                    temp2.append(tempevent.name).append(QString::number(tempevent.Tag)).append(QString::number(tempevent.start.day())).append(QString::number(tempevent.start.hour()));
                    qDebug()<<temparray.first_index<<temparray.second_index<<temparray.count;
                    if(temp1==temp2)
                    {
                        current_user->namequeue[insert_event.name].erase(current_user->namequeue[insert_event.name].begin()+i);
                    }
                }
            }
            else/*若该名称已没有其他事件，直接从容器中删除该名称*/
            {
                current_user->namequeue.erase(insert_event.name);
            }

            qDebug()<<current_user->namequeue[insert_event.name].size();
            if(!positioning_tag)
            {
                msgBox.setWindowTitle("提示");
                msgBox.setText("删除成功");
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.setDefaultButton(QMessageBox::Ok);
                int ret = msgBox.exec();
                if(ret == QMessageBox::Ok)
                    return;
            }
            return ;
        }
        count++;
    }
    msgBox.setWindowTitle("提示");
    msgBox.setText("不存在该事件或者不能删除/修改该事件");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Ok)
        return;
}

void Form1::clear_frame2()
{
    ui->lineEdit_name->clear();
    ui->lineEdit_address->clear();
    ui->comboBox_day->setCurrentIndex(0);
    ui->comboBox_start_time->setCurrentIndex(0);
    ui->comboBox_end_time->setCurrentIndex(1);

    ui->checkBox_week1->setChecked(false);
    ui->checkBox_week2->setChecked(false);
    ui->checkBox_week3->setChecked(false);
    ui->checkBox_week4->setChecked(false);
    ui->checkBox_week5->setChecked(false);
    ui->checkBox_week6->setChecked(false);
    ui->checkBox_week7->setChecked(false);
    ui->checkBox_week8->setChecked(false);
    ui->checkBox_week9->setChecked(false);
    ui->checkBox_week10->setChecked(false);
    ui->checkBox_week11->setChecked(false);
    ui->checkBox_week12->setChecked(false);
    ui->checkBox_week13->setChecked(false);
    ui->checkBox_week14->setChecked(false);
    ui->checkBox_week15->setChecked(false);
    ui->checkBox_week16->setChecked(false);

    ui->radioButton_add->setChecked(true);
    ui->radioButton_delete->setChecked(true);
    ui->radioButton_revise->setChecked(false);
    ui->radioButton_add->setChecked(true);
    ui->radioButton_delete->setChecked(false);
    ui->radioButton_revise->setChecked(false);
    ui->radioButton_event3->setChecked(true);
    ui->radioButton_event4->setChecked(false);
    ui->radioButton_event5->setChecked(false);
}

void Form1::doubleclick_set(int r,int c)
{
    QTableWidgetItem* item = ui->tableWidget->item(r, c);
    if (item == nullptr) //单元格为空时增加事务
    {
        skip_to_dialog(r,c);
    }
    else
    {
        clear_frame2();
        vector<int> index = current_user->find_index(ui->select_week->currentIndex()+1,c+1,r+6);

        if(index.size()<5 && current_user->perEvents[c][r][index[0]].Tag == 5)
        {
            insert_dialog.ui->comboBox->setCurrentIndex(2);
            skip_to_dialog(r,c);
        }

        Event set_event = current_user->perEvents[c][r][index[0]];

        switch(set_event.Tag)
        {
            case 1:{return;break;}
            case 2:{return;break;}
            case 3:{
            ui->radioButton_event3->setChecked(true);break;
            }
            case 4:{
            ui->radioButton_event4->setChecked(true);break;
            }
            case 5:{
            ui->radioButton_event5->setChecked(true);break;
            }
        }


        ui->lineEdit_name->setText(set_event.name);
        ui->comboBox_day->setCurrentIndex(set_event.start.day()-1);
        ui->comboBox_start_time->setCurrentIndex(set_event.start.hour()-6);
        ui->comboBox_end_time->setCurrentIndex(set_event.end.hour()-7);

        for(auto tempweek :set_event.weeks)
        {
            switch(tempweek)
            {
                case 1:ui->checkBox_week1->setChecked(true);break;
                case 2:ui->checkBox_week2->setChecked(true);break;
                case 3:ui->checkBox_week3->setChecked(true);break;
                case 4:ui->checkBox_week4->setChecked(true);break;
                case 5:ui->checkBox_week5->setChecked(true);break;
                case 6:ui->checkBox_week6->setChecked(true);break;
                case 7:ui->checkBox_week7->setChecked(true);break;
                case 8:ui->checkBox_week8->setChecked(true);break;
                case 9: ui->checkBox_week9->setChecked(true);break;
                case 10:ui->checkBox_week10->setChecked(true);break;
                case 11:ui->checkBox_week11->setChecked(true);break;
                case 12:ui->checkBox_week12->setChecked(true);break;
                case 13:ui->checkBox_week13->setChecked(true);break;
                case 14:ui->checkBox_week14->setChecked(true);break;
                case 15:ui->checkBox_week15->setChecked(true);break;
                case 16:ui->checkBox_week16->setChecked(true);break;
            }
        }
    }

}

bool Form1::isexist(Event &a)
{
    bool alreadyin=false;
    for(auto &p:current_user->perEvents[a.start.day()-1][a.start.hour()-6])
    {
        if(p.name == a.name&&p.Tag==a.Tag)//在其他周找到属性完全一致的事件，将当前事件的周数加入其中
        {
            for(auto week_insert:a.weeks)
            {
                alreadyin=false;
                for(auto week_alreadyin:p.weeks)
                {
                    if(week_insert==week_alreadyin)
                    {alreadyin = true;break;}
                }
                if(alreadyin == false)
                    p.weeks.push_back(week_insert);
            }
            return 1;
        }
    }
    return 0;
}

void Form1::seek_position()
{
    QString name;
    int TAG;
    QMessageBox msgBox;
    int count=0;
    if(ui->radioButton_event3->isChecked())
        TAG = 3;
    else if(ui->radioButton_event4->isChecked())
        TAG = 4;
    else if(ui->radioButton_event5->isChecked())
        TAG = 5;
    else
    {
        msgBox.setWindowTitle("提示");
        msgBox.setText("未选择事件类型");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Ok || ret == QMessageBox::Cancel)
            return;
    }

    event_position.first_index=ui->comboBox_day->currentIndex();
    event_position.second_index=ui->comboBox_start_time->currentIndex();
    name = ui->lineEdit_name->text();

    for(auto a:current_user->perEvents[event_position.first_index][event_position.second_index])
    {
        if(a.name==name&&a.Tag==TAG)
        {
            positioning_tag =1;
            event_position.count = count;
            ui->radioButton_revise->setCheckable(true);
            ui->radioButton_add->setCheckable(false);
            ui->radioButton_delete->setCheckable(false);
            msgBox.setWindowTitle("提示");
            msgBox.setText("事件定位成功");
            msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Ok);
            int ret = msgBox.exec();
            if(ret == QMessageBox::Ok || ret == QMessageBox::Cancel)
                return;
        }
        count++;
    }

    msgBox.setWindowTitle("提示");
    msgBox.setText("未找到该事件");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Ok || ret == QMessageBox::Cancel)
        return;

}

void Form1::wideget_control(bool ischecked)
{
    if(ischecked == true)
        ui->widget->show();
    else
        ui->widget->hide();
}

void Form1::insert_ID()
{
    int buffer_ID = ui->comboBox_ID->currentText().toInt();
    if(buffer_ID==current_user->ID)
        return;
    else
    {
        ID.push_back(buffer_ID);
        label_ID.append(ui->comboBox_ID->currentText()).append(" ");
    }
    if(ID.size()%5 == 0)
        label_ID.append("\n");
    ui->label_ID->setText(label_ID);
}
















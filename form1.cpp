#include "form1.h"
#include "ui_form1.h"
#include"QDebug"
#include"QModelIndex"

Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_events)
{
    ui->setupUi(this);

    ui->tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

    ui->frame->setStyleSheet("#frame{border-image: url(:/picture/who.jpg)}"); //添加背景图片
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,0)");//设置背景为透明
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgba(0,0,0,0);width:130px;color:black;border-color:black}");//调整列头(时间点)
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgba(0,0,0,0);height:59px;color:black;border-color:black}");//调整行头(星期几)
    ui->tableWidget->setMouseTracking(true);

    connect(ui->select_week,&QComboBox::currentIndexChanged,this,&Form1::show_percurriculum);/*更换课表显示的周数*/
    connect(ui->tableWidget,&QTableWidget::cellClicked, this, &Form1::check_detial);/*单击单元格查看该事件细节，传递参数为该单元格的行数列数*/
    connect(ui->tableWidget,&QTableWidget::cellDoubleClicked,this,&Form1::skip_to_dialog);/*双击单元格添加或者修改事件，传递参数为该单元格的行数列数*/
    connect(insert_dialog.ui->buttonBox,&QDialogButtonBox::clicked,this,&Form1::add_event);/*修改确认后事件添加成功*/
    connect(ui->pushButton_ok,&QPushButton::clicked,this,&Form1::update_event);/*点击确定按钮结束增删事件，处理用户输入*/
    connect(ui->comboBox_end_time,&QComboBox::currentIndexChanged,this,&Form1::auto_give_start);/*选择开始时间自动生成结束时间*/
    connect(ui->comboBox_start_time,&QComboBox::currentIndexChanged,this,&Form1::auto_give_end);/*选择结束时间自动生成开始时间*/
    connect(ui->pushButton_refresh,&QPushButton::clicked,this,&Form1::show_percurriculum);/*刷新课表*/
    connect(ui->pushButton_clean,&QPushButton::clicked,this,&Form1::clear_frame2);/*清空事件增删框*/

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
    cell_events.clear(); /*每刷新一次都把cell_events清空*/
    ui->tableWidget->clearContents(); /*清空单元格内容*/
    int week=ui->select_week->currentIndex()+1; /*获取周数*/

    qDebug()<<"课表刷新";

    for (int day = 0; day < DAY; day++)
    {
        for (int i = 0; i < HOURS; i++) /*遍历事件*/
        {
            int count =0;
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
                            cell_events[(temphour-6)+day*HOURS]={X.start.hour()-6,count,temphour};/*便于点击课表单元格直接搜索事件*/
                            ui->tableWidget->setItem(temphour-6,day,new QTableWidgetItem(X.name));
                            ui->tableWidget->item(temphour-6,day)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                            ui->tableWidget->item(temphour-6,day)->setForeground(Qt::black);
                        }
                        break;
                    }
                    count++;
                }
            }
        }
    }
}

void Form1::check_detial(int r, int c)
{
    int index;
    int index_2;
    QString detail;

    ui->event_detial->clear();
    QTableWidgetItem* item = ui->tableWidget->item(r, c);
    if (item == nullptr)
       return;

    if(cell_events.find(r+c*16)!=cell_events.end())
    {
        index=cell_events[r+c*16].col_index;
        qDebug()<<index;
        index_2=cell_events[r+c*16].count;
        qDebug()<<index_2;
        detail.append("事件名称: ");
        detail.append(current_user->perEvents[c][index][index_2].name);
        detail.append("\n");
        detail.append("持续时间: ");
        detail.append(QString::number(current_user->perEvents[c][index][index_2].start.hour(),10));
        detail.append(":00 -- ");
        detail.append(QString::number(current_user->perEvents[c][index][index_2].end.hour(),10));
        detail.append(":00\n");
        detail.append("事件地点: ");
        detail.append("\n");
        detail.append("事件类型: ");
        switch(current_user->perEvents[c][index][index_2].Tag)
        {
            case 1:detail.append("必修课");break;
            case 2:detail.append("选修课");break;
            case 3:detail.append("集体事务");break;
            case 4:detail.append("个人事务");break;
            case 5:detail.append("临时事务");break;
        }

        ui->event_detial->setText(detail);
    }
    else
       return;

}

void Form1::init_form1(Person *a)
{
    current_user = a;
    show_percurriculum();
}

void Form1::skip_to_dialog(int r,int c)
{
    QTableWidgetItem* item = ui->tableWidget->item(r, c);
    if (item == nullptr) //单元格为空时增加事务
    {
       insert_dialog.ui->lineEdit->clear();
       insert_dialog.ui->lineEdit_2->clear();
       insert_dialog.show();
       insert_dialog.row =r;
       insert_dialog.line=c;
    }
}


int Form1::add_event(QAbstractButton* button)
{
    if(button == (QAbstractButton *)(insert_dialog.ui->buttonBox->button(QDialogButtonBox::Ok)))
    {
        Event temp;
        temp.name=insert_dialog.ui->lineEdit->text();
        temp.weeks.push_back(ui->select_week->currentIndex()+1);
        temp.start.day()=insert_dialog.line+1;
        temp.start.hour()=insert_dialog.row+6;
        temp.end.hour()=temp.start.hour()+1;

        if(insert_dialog.ui->comboBox->currentText()=="个人事务")
            temp.Tag=4;
        else
            temp.Tag=5;
        current_user->perEvents[insert_dialog.line][insert_dialog.row].push_back(temp);//新增事件

        //在课表上显示
        ui->tableWidget->setItem(insert_dialog.row,insert_dialog.line,new QTableWidgetItem(temp.name));
        ui->tableWidget->item(insert_dialog.row,insert_dialog.line)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->item(insert_dialog.row,insert_dialog.line)->setForeground(Qt::black);

        //插入哈希，便于通过单元格行列查找
        cell_events[insert_dialog.row+insert_dialog.line*16]= {insert_dialog.row,(int)(current_user->perEvents[insert_dialog.line][insert_dialog.row].size()-1),1};
    }
    else if(button == (QAbstractButton *)(insert_dialog.ui->buttonBox->button(QDialogButtonBox::Cancel)))
    {
        qDebug() << "(Button Cancle has been clicked.)";
    }
    return 0;
}

void Form1::update_event()
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
        insert_event.weeks.push_back(int(1));
    if(ui->checkBox_week2->isChecked())
        insert_event.weeks.push_back(int(2));
    if(ui->checkBox_week3->isChecked())
        insert_event.weeks.push_back(int(3));
    if(ui->checkBox_week4->isChecked())
        insert_event.weeks.push_back(int(4));
    if(ui->checkBox_week5->isChecked())
        insert_event.weeks.push_back(int(5));
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

    insert_event.name = ui->lineEdit_name->text();
    insert_event.start.day()=ui->comboBox_day->currentIndex()+1;
    insert_event.start.hour()=ui->comboBox_start_time->currentIndex()+6;
    insert_event.end.hour()=insert_event.start.hour()+1;
    insert_event.periodicity = insert_event.weeks.size();


    /*获取用户输入的事件的信息*/
    if(operate_tag == 1 && insert_event.periodicity!=0)
    {
        seektime temp_time=current_user->iscollision(insert_event);

        if(temp_time.tag == 1)
        {
            current_user->perEvents[insert_event.start.day()-1][insert_event.start.hour()-6].push_back(insert_event);/*增加事件*/
            msgBox.setWindowTitle("提示");
            msgBox.setText("添加成功");
            msgBox.setStandardButtons(QMessageBox::Ok );
            msgBox.setDefaultButton(QMessageBox::Ok);
            int ret = msgBox.exec();
            if(ret == QMessageBox::Ok)
                return;

        }
        else if(temp_time.tag == 0)
        {
            QString tip;
            if(temp_time.week != 0)
            {
                tip+="在第";tip+=QString::number(temp_time.week);tip+="周\n";
            }

            tip+="星期";tip+=QString::number(temp_time.day);
            tip+=QString::number(temp_time.hour);tip+=":00 ~ ";tip+=QString::number(temp_time.hour+1);tip+=":00\n";
            tip+="与其他事务发生冲突";
            msgBox.setWindowTitle("提示");
            msgBox.setText(tip);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            int ret = msgBox.exec();
            if(ret == QMessageBox::Ok)
                return;
        }

    }

    else if(operate_tag == 2 && insert_event.periodicity!=0)
    {
        for(auto &a:current_user->perEvents[insert_event.start.day()-1][insert_event.start.hour()-6])
        {
            if(a.name == insert_event.name && a.Tag == insert_event.Tag)
            {
                a.weeks = insert_event.weeks;/*匹配成功则修改事件*/

                msgBox.setWindowTitle("提示");
                msgBox.setText("修改成功");
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.setDefaultButton(QMessageBox::Ok);
                int ret = msgBox.exec();
                if(ret == QMessageBox::Ok)
                    return;
            }
        }
        msgBox.setWindowTitle("提示");
        msgBox.setText("不存在该事件");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Ok)
            return;
    }

    else if(operate_tag == 3)
    {
        int count =0;
        for(auto &a:current_user->perEvents[insert_event.start.day()-1][insert_event.start.hour()-6])
        {
            if(a.name == insert_event.name && a.Tag == insert_event.Tag)
            {
                current_user->perEvents[insert_event.start.day()-1][insert_event.start.hour()-6].erase(current_user->perEvents[insert_event.start.day()-1][insert_event.start.hour()-6].begin()+count);
                msgBox.setWindowTitle("提示");
                msgBox.setText("删除成功");
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.setDefaultButton(QMessageBox::Ok);
                int ret = msgBox.exec();
                if(ret == QMessageBox::Ok)
                    return;
            }
            count++;
        }
        msgBox.setWindowTitle("提示");
        msgBox.setText("不存在该事件或者不能删除该事件");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Ok)
            return;
    }
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
    ui->radioButton_delete->setChecked(false);
    ui->radioButton_revise->setChecked(false);
    ui->radioButton_event3->setChecked(true);
    ui->radioButton_event4->setChecked(false);
    ui->radioButton_event5->setChecked(false);
}



#include "adminwdt.h"
#include "ui_adminwdt.h"
#include"QDebug"
#include"QModelIndex"
#include <QListView>
#include <QListWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QCheckBox>

adminwdt::adminwdt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminwdt)
{
    ui->setupUi(this);
    refresh = 0;
    positioning_tag =0;
    event_position.count = -1;

    ui->tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
    ui->frame->setStyleSheet("#frame{border-image: url(:/picture/admin.png)}"); //添加背景图片
    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,0)");//设置背景为透明
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgba(0,0,0,0);width:130px;color:black;border-color:black}");//调整列头(时间点)
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgba(0,0,0,0);height:59px;color:black;border-color:black}");//调整行头(星期几)
    ui->tableWidget->setMouseTracking(true);

    connect(ui->select_week,&QComboBox::currentIndexChanged,this,&adminwdt::show_percurriculum);/*更换课表显示的周数*/
    connect(ui->pushButton_refresh,&QPushButton::clicked,this,&adminwdt::show_percurriculum);/*刷新课表*/

}

adminwdt::~adminwdt()
{
    delete ui;
}

void adminwdt::init_current_user(QString personal_name,int personal_ID)
{
    current_user->name=personal_name;
    current_user->ID=personal_ID;
}

void adminwdt::show_percurriculum()
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

void adminwdt::init_adminwdt(Person *a)
{
    current_user = a;
    insert_dialog.current_ID = current_user->ID;
    show_percurriculum();
    init_week_sel_combo({});
    init_ID_sel_combo({});
}

void adminwdt::add_event(Event & insert_event)
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


void adminwdt::delete_event(Event & insert_event)
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


bool adminwdt::isexist(Event &a)
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

void adminwdt::init_week_sel_combo (vector<int> week)
{
    auto it = week.begin();

    QListWidget *weel_sel_listwdt = new QListWidget;
    for (int i = 1; i <= 16; ++i) {
        QListWidgetItem* pItem = new QListWidgetItem();// 增加listwidget的item
        pItem->setData(Qt::UserRole, i);

        QCheckBox *pCheckBox = new QCheckBox(this);
        pCheckBox->setText(QString("第%1周").arg(i));
        pCheckBox->setChecked(true);
        pCheckBox->setCheckState(Qt::Unchecked);
        if (it != week.end() && i == *it)
        {
            pCheckBox->setCheckState(Qt::Checked);
            it ++;
        }

        weel_sel_listwdt->addItem(pItem);
        weel_sel_listwdt->setItemWidget(pItem, pCheckBox);

        connect(pCheckBox, &QCheckBox::stateChanged, this, &adminwdt::change_week_sel_combo);
    }
    ui->week_sel_combo->setModel(weel_sel_listwdt->model());
    ui->week_sel_combo->setView(weel_sel_listwdt);

    QLineEdit * week_sel_LineEdit = new QLineEdit;
    week_sel_LineEdit->setReadOnly(true);
    ui->week_sel_combo->setLineEdit(week_sel_LineEdit);

    change_week_sel_combo(0);
}

void adminwdt::change_week_sel_combo (int status)
{
    QString strSelectedData("");
    QListWidget *weel_sel_listwdt = (QListWidget *) (ui->week_sel_combo->view());

    if (weel_sel_listwdt == nullptr)
        return ;
    int nCount = weel_sel_listwdt->count();
    for (int i = 0; i < nCount; ++i)
    {
        QListWidgetItem *pItem = weel_sel_listwdt->item(i);
        QWidget *pWidget = weel_sel_listwdt->itemWidget(pItem);
        QCheckBox *pCheckBox = (QCheckBox *)pWidget;
        if (pCheckBox->isChecked())
        {
            QString strText = pCheckBox->text();
            strSelectedData.append(strText).append(",");
        }
    }
    if (strSelectedData.endsWith(","))
        strSelectedData.remove(strSelectedData.count() - 1, 1);
    if (!strSelectedData.isEmpty())
    {
        ui->week_sel_combo->lineEdit()->setText(strSelectedData);
        ui->week_sel_combo->lineEdit()->setToolTip(strSelectedData);
    }
    else
    {
        ui->week_sel_combo->lineEdit()->clear();
    }
}

void adminwdt::init_ID_sel_combo (vector<int> student_ID)
{
    auto it = student_ID.begin();

    QListWidget *ID_sel_listwdt = new QListWidget;
    for (int i = 0; i <= 9; ++i) {
        QListWidgetItem* pItem = new QListWidgetItem();// 增加listwidget的item
        pItem->setData(Qt::UserRole, i);

        QCheckBox *pCheckBox = new QCheckBox(this);
        pCheckBox->setText(QString("202121%1").arg(i));
        pCheckBox->setChecked(true);
        pCheckBox->setCheckState(Qt::Unchecked);
        if (it != student_ID.end() && i+2021210 == *it)
        {
            pCheckBox->setCheckState(Qt::Checked);
            it ++;
        }

        ID_sel_listwdt->addItem(pItem);
        ID_sel_listwdt->setItemWidget(pItem, pCheckBox);

        connect(pCheckBox, &QCheckBox::stateChanged, this, &adminwdt::change_ID_sel_combo);
    }
    ui->ID_sel_combo->setModel(ID_sel_listwdt->model());
    ui->ID_sel_combo->setView(ID_sel_listwdt);

    QLineEdit * ID_sel_LineEdit = new QLineEdit;
    ID_sel_LineEdit->setReadOnly(true);
    ui->ID_sel_combo->setLineEdit(ID_sel_LineEdit);

    change_ID_sel_combo(0);
}

void adminwdt::change_ID_sel_combo (int status)
{
    QString strSelectedData("");
    QListWidget *ID_sel_listwdt = (QListWidget *) (ui->ID_sel_combo->view());

    if (ID_sel_listwdt == nullptr)
        return ;
    int nCount = ID_sel_listwdt->count();
    for (int i = 0; i < nCount; ++i)
    {
        QListWidgetItem *pItem = ID_sel_listwdt->item(i);
        QWidget *pWidget = ID_sel_listwdt->itemWidget(pItem);
        QCheckBox *pCheckBox = (QCheckBox *)pWidget;
        if (pCheckBox->isChecked())
        {
            QString strText = pCheckBox->text();
            strSelectedData.append(strText).append(",");
        }
    }
    if (strSelectedData.endsWith(","))
        strSelectedData.remove(strSelectedData.count() - 1, 1);
    if (!strSelectedData.isEmpty())
    {
        ui->ID_sel_combo->lineEdit()->setText(strSelectedData);
        ui->ID_sel_combo->lineEdit()->setToolTip(strSelectedData);
    }
    else
    {
        ui->ID_sel_combo->lineEdit()->clear();
    }
}

#include "form3.h"
#include "ui_form3.h"
#include <QStandardItem>
#include <QMediaPlayer>
#include <QAudioOutput>
#include<set>

Form3::Form3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form3)
{
    ui->setupUi(this);
    QImage img (":/picture/mkim1.png");
    ui->label->setPixmap(QPixmap::fromImage(img));
    current_user = nullptr;

    QAction * searchAction = new QAction(ui->lineEdit);
    searchAction->setIcon(QIcon(":/picture/search.png"));
    ui->lineEdit->addAction(searchAction,QLineEdit::LeadingPosition);
    ui->lineEdit->setClearButtonEnabled(true);
    ui->tableWidget_search->horizontalHeader()->setVisible(false);
    ui->tableWidget_search->verticalHeader()->setVisible(false);
    ui->tableWidget_search->setShowGrid(false);
    ui->tableWidget_search->setMouseTracking(true);

    QHeaderView* header = ui->tableWidget_outcome->horizontalHeader();
    header->setStyleSheet("QHeaderView::section{background-color:rgba(225, 74, 28,100);}");

    connect(ui->lineEdit,&QLineEdit::textChanged,this,&Form3::search);//搜索框内容改变时重新搜索
    connect(ui->tableWidget_search,&QTableWidget::cellEntered,this,&Form3::mycellenter);
    connect(ui->tableWidget_search,&QTableWidget::cellClicked,this,&Form3::search_outcome);
    connect(ui->pushButton_quit,&QPushButton::clicked,this,&Form3::quit);
    connect(ui->pushButton_correct,&QPushButton::clicked,this,&Form3::correct);

    connect(ui->bt_pause,&QPushButton::clicked,this,&Form3::time_pause);
    connect(ui->bt_hour,&QPushButton::clicked,this,&Form3::FF_hour);
    connect(ui->bt_day,&QPushButton::clicked,this,&Form3::FF_day);
    connect(ui->cb_week,&QComboBox::currentIndexChanged,this,&Form3::set_week);
}

Form3::~Form3()
{
    ti->save_this_time();
    write_alarm_file();
    delete ui;
}

void Form3::init_form3(Person *a,_Time*t)
{
    ti=t;
    current_user =a;
    ui->label_name->setText(current_user->getname());
    ui->label_ID->setText(QString::number(current_user->getID()));
    QString address =":/picture/";
    address +=QString::number(current_user->getID());
    address +=".png";
    QImage image(address);
    ui->label_image->setPixmap(QPixmap::fromImage(image));
    ui->tableWidget_search->hide();
    show_one_day_event();

    ui->label_log->setText(current_user->log);
    read_alarm_file();
    AlarmTable_init();
}

void Form3::search()
{
    const QString text = ui->lineEdit->text();
    search_select.clear();

    if(text.isEmpty())
    {
        ui->tableWidget_search->hide();
        return;
    }

    for(auto a:current_user->getevent_name())
    {
        if(a.indexOf(text) != -1)
        {
            search_select.push_back(a);
        }
    }

    ui->tableWidget_search->setRowCount(search_select.size()+1);
    ui->tableWidget_search->setColumnCount(1);


    for(int row=1;row < (int)search_select.size()+1;row++)
    {
        QString out =QString::number(row);
        if(row<10)
            out+="    ";
        else
            out+="   ";
        out += search_select[row-1];
        ui->tableWidget_search->setItem(row,0,new QTableWidgetItem(out));
    }

    ui->tableWidget_search->show();

}

void Form3::mycellenter(int row,int column)
{
    QTableWidgetItem *item = 0;
    QColor color;

    //还原上一行的颜色
    item = ui->tableWidget_search->item(previousColorRow, 0);
    color.setRgb(74, 74, 74, 100);
    color.setRgba(100);
    if (item != 0)
    {
        item->setBackground(color);
    }

    //设置当前行的颜色
    color.setRgb(140, 140, 140);
    item = ui->tableWidget_search->item(row, 0);
    if (item != 0 && !item->text().isEmpty())
    {
        item->setBackground(color);
    }

    previousColorRow = row;
}

void Form3::search_outcome(int row,int column)
{
    int line=0;

    ui->tableWidget_outcome->clearContents();
    current_user->reorder(search_select[row-1]);
    vector<arrayindex> p = current_user->namequeue[search_select[row-1]];
    ui->tableWidget_outcome->setRowCount(p.size());
    QString foundation_information;
    foundation_information += search_select[row-1];

    ui->label_foundation->setText(foundation_information);

    for(auto a:p)
    {
        QString type;
        QString time;
        QString week;
        QString address;
        QString tip;
        int tag = current_user->perEvents[a.first_index][a.second_index][a.count-1].Tag;

        switch (tag)
        {
        case 1:if(current_user->perEvents[a.first_index][a.second_index][a.count-1].name.endsWith("考试"))
                type.append("必修课考试");
            else
                type.append("必修课");
            break;
        case 2:if(current_user->perEvents[a.first_index][a.second_index][a.count-1].name.endsWith("考试"))
                type.append("选修课考试");
            else
                type.append("选修课");
            break;
        case 3:type.append("集体事务");break;
        case 4:type.append("个人事务");break;
        case 5:type.append("临时事务");break;
        }

        time += number_to_week((current_user->perEvents)[a.first_index][a.second_index][a.count-1].start.day());
        time+=" ";
        time+=QString::number((current_user->perEvents)[a.first_index][a.second_index][a.count-1].start.hour());
        time+=":00~";
        time+=QString::number(((current_user->perEvents)[a.first_index][a.second_index][a.count-1].end.hour()));
        time+=":00";

        if((tag==1 || tag ==2)&&!(current_user->perEvents)[a.first_index][a.second_index][a.count-1].name.endsWith("考试"))
            week+="每周都有";
        else
        {
            for(auto tempweek:(current_user->perEvents)[a.first_index][a.second_index][a.count-1].weeks)
            {
                week+=QString::number(tempweek);
                week+=" ";
            }
        }

        address = current_user->perEvents[a.first_index][a.second_index][a.count-1].building.name_();

        if(tag ==1||tag ==2)
        {
            QString exam_name = current_user->perEvents[a.first_index][a.second_index][a.count-1].name +"考试";
            if(current_user->namequeue.find(exam_name)!=current_user->namequeue.end())
                tip.append("已发布考试");
        }
        else if(tag == 3)
        {
            tip.append("参加学生：");
            for(auto tempID:current_user->perEvents[a.first_index][a.second_index][a.count-1].ID)
            {
                tip.append(QString::number(tempID)).append(" ");
            }
        }

        ui->tableWidget_outcome->setItem(line,0,new QTableWidgetItem(type));
        ui->tableWidget_outcome->item(line,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget_outcome->setItem(line,1,new QTableWidgetItem(time));
        ui->tableWidget_outcome->item(line,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget_outcome->setItem(line,2,new QTableWidgetItem(week));
        ui->tableWidget_outcome->item(line,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget_outcome->setItem(line,3,new QTableWidgetItem(address));
        ui->tableWidget_outcome->item(line,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget_outcome->setItem(line,4,new QTableWidgetItem(tip));
        ui->tableWidget_outcome->item(line,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        line++;
    }
}

void Form3::quit()
{
    qDebug()<<"退出";
    emit QUIT_form();
}

void Form3::correct()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("提示");
    msgBox.setText("无权限，请联系管理员修改密码");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Ok || ret == QMessageBox::Cancel)
        return;

}

#include <QComboBox>
#include <QCheckBox>
#include <QTreeView>
#include <QHBoxLayout>

void Form3::AlarmTable_init()
{
    model = new QStandardItemModel();
    ui->AlarmTable->setModel(model);
    ui->AlarmTable->setFocusPolicy(Qt::NoFocus); //去掉选中单元格时的虚框

    model->setHorizontalHeaderLabels({"启用", "时间", "重复", "事件", "备注", "ID"});
    ui->AlarmTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->AlarmTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->AlarmTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->AlarmTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->AlarmTable->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->AlarmTable->hideColumn(5);
    ui->AlarmTable->resizeRowsToContents();
    //ui->AlarmTable->setStyleSheet("#frame{border-image: url(:/picture/alarmtable_background.png)}");

    connect(model, &QStandardItemModel::itemChanged, this, &Form3::on_UseCheck_activated);

    for (auto single : all_alarm)
    {
        int rowcount = ui->AlarmTable->model()->rowCount();
        if (single.event_tag != CLASS)
        {
            AddAlarmRow(rowcount, single);
        }
        else
        {
            if ((single.alarm_event.start.hour()-single.alarm_hour) == 1)
                if (single.alarm_week+1 == single.alarm_event.start.day())
                    continue;
            AddAlarmRow(rowcount, single);
        }
    }

    //Ring(all_alarm[0]);
}

void Form3::AddAlarmRow (const int row, Alarm& single)
{
    disconnect(model, &QStandardItemModel::itemChanged, this, &Form3::on_UseCheck_activated);
    QStandardItem *UseCheck = new QStandardItem();
    UseCheck->setFlags(UseCheck->flags() | Qt::ItemIsUserCheckable);
    if (single.IsUsed == true)
        UseCheck->setCheckState(Qt::Checked);
    else
        UseCheck->setCheckState(Qt::Unchecked);
    model->setData(model->index(row, 0), UseCheck->checkState(), Qt::DisplayRole);
    model->setItem(row, 0, UseCheck);


    QComboBox* TimeCmb = new QComboBox();
    TimeCmb->addItems({"0:00  ", "1:00  ", "2:00  ", "3:00  ", "4:00  ", "5:00  ", "6:00  ", "7:00  ", "8:00  ", "9:00  ", "10:00  ", "11:00  ",
                       "12:00  ", "13:00  ", "14:00  ", "15:00  ", "16:00  ", "17:00  ", "18:00  ", "19:00  ", "20:00  ", "21:00  ", "22:00  ", "23:00  "});
    TimeCmb->setCurrentIndex(single.alarm_hour);
    ui->AlarmTable->setIndexWidget(model->index(row, 1), TimeCmb);

    QComboBox* TagCmb;
    QComboBox* WeekCmb;
    if (single.event_tag == CLASS)
    {
        WeekCmb = new QComboBox();
        WeekCmb->addItems({"星期一  ", "星期二  ", "星期三  ", "星期四  ", "星期五  ", "星期六  ", "星期天  "});
        WeekCmb->setCurrentIndex(single.alarm_week);
        ui->AlarmTable->setIndexWidget(model->index(row, 2), WeekCmb);
        connect(WeekCmb, &QComboBox::currentIndexChanged, this, &Form3::on_WeekCmb_activated);
    }
    else if (single.alarm_tag == WEEKLY)
    {
        WeekCmb = new QComboBox();
        WeekCmb->addItems({"星期一  ", "星期二  ", "星期三  ", "星期四  ", "星期五  ", "星期六  ", "星期天  ", "重置  "});
        WeekCmb->setCurrentIndex(single.alarm_week);
        ui->AlarmTable->setIndexWidget(model->index(row, 2), WeekCmb);
        connect(WeekCmb, &QComboBox::currentIndexChanged, this, &Form3::on_WeekCmb_activated);
    }
    else if (single.event_tag == TEMPORARY)
    {
        TagCmb = new QComboBox();
        TagCmb->addItems({"只响一次  "});
        TagCmb->setCurrentIndex(single.alarm_tag);
        ui->AlarmTable->setIndexWidget(model->index(row, 2), TagCmb);
        connect(TagCmb, &QComboBox::currentIndexChanged, this, &Form3::on_TagCmb_activated);
    }
    else
    {
        TagCmb = new QComboBox();
        TagCmb->addItems({"只响一次  ", "每天一次  ", "每周一次  "});
        TagCmb->setCurrentIndex(single.alarm_tag);
        ui->AlarmTable->setIndexWidget(model->index(row, 2), TagCmb);
        connect(TagCmb, &QComboBox::currentIndexChanged, this, &Form3::on_TagCmb_activated);
    }

    QComboBox* ThingCmb = new QComboBox();
    ThingCmb->addItems({"课程  ", "课外活动  ", "临时事物  ", "无  "});
    ThingCmb->setCurrentIndex(single.event_tag);
    ui->AlarmTable->setIndexWidget(model->index(row, 3), ThingCmb);

    QString indextoword{"一二三四五六日"};
    set<QString> st;
    QStringList word_list;
    word_list << "您未选择事件或是选择的事件已改变,请重新选择";
    if (single.event_tag == CLASS)
    {
        ui->AlarmTable->setIndexWidget(model->index(row, 4), nullptr);

        for (int i = 0; i < DAY; i ++)
        {
            for (int j = 0; j < HOURS; j ++)
            {
                for (int k = 0; k < (int)current_user->perEvents[i][j].size(); k ++)
                {
                    Event tmp = current_user->perEvents[i][j][k];
                    QString time;
                    if (tmp.Tag == 1 || tmp.Tag == 2)
                    {
                        time = alarm_to_format_QString(tmp);
                        if (!st.count(time))
                        {
                            st.insert(time);
                            word_list << time;
                        }
                    }
                }
            }
        }
        QComboBox* ClassCmb = new QComboBox();
        ClassCmb->addItems(word_list);
        if (st.count(single.tip))
        {
            ClassCmb->setCurrentText(single.tip);
            for (auto it = all_alarm.begin(); it != all_alarm.end(); it ++)
            {
                if (it->tip == single.tip)
                {
                    it->IsUsed = false;
                    break;
                }
            }
        }
        else
            ClassCmb->setCurrentText("您未选择事件或是选择的事件已改变,请重新选择");
        ui->AlarmTable->setIndexWidget(model->index(row, 4), ClassCmb);
        connect(ClassCmb, &QComboBox::currentTextChanged, this, &Form3::on_ClassCmb_activated);
    }
    else if (single.event_tag == AFTERCLASS)
    {
        ui->AlarmTable->setIndexWidget(model->index(row, 4), nullptr);

        for (int i = 0; i < DAY; i ++)
        {
            for (int j = 0; j < HOURS; j ++)
            {
                for (int k = 0; k < (int)current_user->perEvents[i][j].size(); k ++)
                {
                    Event tmp = current_user->perEvents[i][j][k];
                    QString time;
                    if (tmp.Tag == 3 || tmp.Tag == 4)
                    {
                        time = alarm_to_format_QString(tmp);
                        if (!st.count(time))
                        {
                            st.insert(time);
                            word_list << time;
                        }
                    }
                }
            }
        }
        QComboBox* AfterclassCmb = new QComboBox();
        AfterclassCmb->addItems(word_list);
//        AfterclassCmb->setItemData(0, Qt::ItemIsSelectable, Qt::NoItemFlags);
//        AfterclassCmb->setItemData(1, Qt::ItemIsSelectable, Qt::NoItemFlags);
        if (st.count(single.tip))
            AfterclassCmb->setCurrentText(single.tip);
        else
            AfterclassCmb->setCurrentText("您未选择事件或是选择的事件已改变,请重新选择");
        ui->AlarmTable->setIndexWidget(model->index(row, 4), AfterclassCmb);

        connect(AfterclassCmb, &QComboBox::currentTextChanged, this, &Form3::on_AfterclassCmb_activated);
    }
    else if (single.event_tag == TEMPORARY)
    {
        for (int i = 0; i < DAY; i ++)
        {
            for (int j = 0; j < HOURS; j ++)
            {
                for (int k = 0; k < (int)current_user->perEvents[i][j].size(); k ++)
                {
                    Event tmp = current_user->perEvents[i][j][k];
                    QString time;
                    if (tmp.Tag == 5)
                    {
                        time = alarm_to_format_QString(tmp);
                        if (!st.count(time))
                        {
                            st.insert(time);
                            word_list << time;
                        }
                    }
                }
            }
        }
        QComboBox* TemporaryCmb = new QComboBox();
        TemporaryCmb->addItems(word_list);
//        TemporaryCmb->setItemData(0, Qt::ItemIsSelectable, Qt::NoItemFlags);
//        TemporaryCmb->setItemData(1, Qt::ItemIsSelectable, Qt::NoItemFlags);
        if (st.count(single.tip))
            TemporaryCmb->setCurrentText(single.tip);
        else
            TemporaryCmb->setCurrentText("您未选择事件或是选择的事件已改变,请重新选择");
        ui->AlarmTable->setIndexWidget(model->index(row, 4), TemporaryCmb);

        connect(TemporaryCmb, &QComboBox::currentTextChanged, this, &Form3::on_TemporaryCmb_activated);
    }
    else if (single.event_tag == NONE)
    {
        QLineEdit* NoneLineedit = new QLineEdit();
        ui->AlarmTable->setIndexWidget(model->index(row, 4), NoneLineedit);
        NoneLineedit->setPlaceholderText("在此输入闹钟备注");
        if (!single.tip.isEmpty())
            NoneLineedit->setText(single.tip);
        connect(NoneLineedit, &QLineEdit::textChanged, this, &Form3::NoneLineedit_textChanged);
    }

    model->setItem(row, 5, new QStandardItem(QString::number(single.index)));
    model->item(row, 5)->setData(QString::number(single.index));

//    if (single.event_tag == TEMPORARY)
//        model->item(row, 2)->setSelectable(false);

    ui->AlarmTable->resizeRowsToContents();
    connect(model, &QStandardItemModel::itemChanged, this, &Form3::on_UseCheck_activated);
    connect(TimeCmb, &QComboBox::currentIndexChanged, this, &Form3::on_TimeCmb_activated);
    connect(ThingCmb, &QComboBox::currentIndexChanged, this, &Form3::on_ThingCmb_activated);
}

void Form3::on_pushButton_clicked()
{
    int rowcount = ui->AlarmTable->model()->rowCount();
    Alarm temp;
    if (all_alarm.size())
        temp.index = all_alarm[all_alarm.size()-1].index + 1;
    else
        temp.index = 0;
    all_alarm.push_back(temp);
    //temp.event_tag = NONE;
    AddAlarmRow(rowcount, temp);
//    qDebug()<<"添加在闹钟"
}

int Form3::find_alarm_index (int ID)
{
    int i = 0;
    for ( ; i < (int)all_alarm.size(); i ++)
    {
        if (all_alarm[i].index == ID)
            break;
    }
    return i;
}

void Form3::on_UseCheck_activated (const QStandardItem* item)
{
    if (item->column() != 0)
        return;
    int ID = model->item(item->row(), 5)->data().toInt();
    int alarm_index = find_alarm_index(ID);

    if (item->checkState() == Qt::Checked)
    {
        qDebug() << "打开为"<<all_alarm[alarm_index].tip<<"设置的闹钟";
        all_alarm[alarm_index].IsUsed = true;
    }
    else
    {
        qDebug() << "关闭为"<<all_alarm[alarm_index].tip<<"设置的闹钟";
        all_alarm[alarm_index].IsUsed = false;
    }
}

void Form3::on_TimeCmb_activated (const int Index)
{
    QModelIndexList selectList = ui->AlarmTable->selectionModel()->selectedIndexes();
    QModelIndex index = selectList.first();
    int ID = model->item(index.row(), 5)->data().toInt();
    int alarm_index = find_alarm_index(ID);
    all_alarm[alarm_index].alarm_hour = Index;
}

void Form3::on_TagCmb_activated (const int Index)
{
    QModelIndexList selectList = ui->AlarmTable->selectionModel()->selectedIndexes();
    QModelIndex index = selectList.first();
    int row = index.row();
    int ID = model->item(index.row(), 5)->data().toInt();
    int alarm_index = find_alarm_index(ID);
    all_alarm[alarm_index].alarm_tag = Index;

    if (Index == WEEKLY)
    {
        ui->AlarmTable->setIndexWidget(model->index(row, 2), nullptr);
        QComboBox* WeekCmb = new QComboBox();
        WeekCmb->addItems({"星期一  ", "星期二  ", "星期三  ", "星期四  ", "星期五  ", "星期六  ", "星期天  ", "重置  "});
        ui->AlarmTable->setIndexWidget(model->index(row, 2), WeekCmb);
        connect(WeekCmb, &QComboBox::currentIndexChanged, this, &Form3::on_WeekCmb_activated);
    }
}

void Form3::on_WeekCmb_activated (const int Index)
{
    QModelIndexList selectList = ui->AlarmTable->selectionModel()->selectedIndexes();
    QModelIndex index = selectList.first();
    int row = index.row();

    if (Index == 7)
    {
        ui->AlarmTable->setIndexWidget(model->index(row, 2), nullptr);
        QComboBox* TagCmb = new QComboBox();
        TagCmb->addItems({"只响一次  ", "每天一次  ", "每周一次  "});
        ui->AlarmTable->setIndexWidget(model->index(row, 2), TagCmb);
        connect(TagCmb, &QComboBox::currentIndexChanged, this, &Form3::on_TagCmb_activated);
    }
    else
    {
        int ID = model->item(row, 5)->data().toInt();
        int alarm_index = find_alarm_index(ID);
        all_alarm[alarm_index].alarm_week = Index;
    }
}

void Form3::on_ThingCmb_activated (const int Index)
{
    QModelIndexList selectList = ui->AlarmTable->selectionModel()->selectedIndexes();
    QModelIndex index;
    index = selectList.first();
    int row = index.row();
    int ID;
    int alarm_index;
    ID = model->item(row, 5)->data().toInt();
    alarm_index = find_alarm_index(ID);
    all_alarm[alarm_index].event_tag = Index;

    QString indextoword{"一二三四五六日"};
    set<QString> st;
    QStringList word_list;
    word_list << "您未选择事件或是选择的事件已改变,请重新选择";
    if (Index == CLASS)
    {
        ui->AlarmTable->setIndexWidget(model->index(row, 4), nullptr);
        for (int i = 0; i < DAY; i ++)
        {
            for (int j = 0; j < HOURS; j ++)
            {
                for (int k = 0; k < (int)current_user->perEvents[i][j].size(); k ++)
                {
                    Event tmp = current_user->perEvents[i][j][k];
                    QString time;
                    if (tmp.Tag == 1 || tmp.Tag == 2)
                    {
                        time = alarm_to_format_QString(tmp);
                        if (!st.count(time))
                        {
                            st.insert(time);
                            word_list << time;
                        }
                    }
                }
            }
        }
        QComboBox* ClassCmb = new QComboBox();
        ClassCmb->addItems(word_list);
        ui->AlarmTable->setIndexWidget(model->index(row, 4), ClassCmb);
        connect(ClassCmb, &QComboBox::currentTextChanged, this, &Form3::on_ClassCmb_activated);
    }
    else if (Index == AFTERCLASS)
    {
        ui->AlarmTable->setIndexWidget(model->index(row, 4), nullptr);
        for (int i = 0; i < DAY; i ++)
        {
            for (int j = 0; j < HOURS; j ++)
            {
                for (int k = 0; k < (int)current_user->perEvents[i][j].size(); k ++)
                {
                    Event tmp = current_user->perEvents[i][j][k];
                    QString time;
                    if (tmp.Tag == 3 || tmp.Tag == 4)
                    {
                        time = alarm_to_format_QString(tmp);
                        if (!st.count(time))
                        {
                            st.insert(time);
                            word_list << time;
                        }
                    }
                }
            }
        }
        QComboBox* AfterclassCmb = new QComboBox();
        AfterclassCmb->addItems(word_list);
        ui->AlarmTable->setIndexWidget(model->index(row, 4), AfterclassCmb);
        if (word_list.size() > 1)
            on_AfterclassCmb_activated(word_list[1]);
        connect(AfterclassCmb, &QComboBox::currentTextChanged, this, &Form3::on_AfterclassCmb_activated);
    }
    else if (Index == TEMPORARY)
    {
        ui->AlarmTable->setIndexWidget(model->index(row, 4), nullptr);
        for (int i = 0; i < DAY; i ++)
        {
            for (int j = 0; j < HOURS; j ++)
            {
                for (int k = 0; k < (int)current_user->perEvents[i][j].size(); k ++)
                {
                    Event tmp = current_user->perEvents[i][j][k];
                    QString time;
                    if (tmp.Tag == 5)
                    {
                        time = alarm_to_format_QString(tmp);
                        if (!st.count(time))
                        {
                            st.insert(time);
                            word_list << time;
                        }
                    }
                }
            }
        }
        QComboBox* TemporaryCmb = new QComboBox();
        TemporaryCmb->addItems(word_list);
        ui->AlarmTable->setIndexWidget(model->index(row, 4), TemporaryCmb);
        if (word_list.size() > 1)
            on_TemporaryCmb_activated(word_list[1]);
        connect(TemporaryCmb, &QComboBox::currentTextChanged, this, &Form3::on_TemporaryCmb_activated);
//        on_TagCmb_activated(ONCE);
    }
    else if (Index == NONE)
    {
        ui->AlarmTable->setIndexWidget(model->index(row, 4), nullptr);
        QLineEdit* NoneLineedit = new QLineEdit();
        ui->AlarmTable->setIndexWidget(model->index(row, 4), NoneLineedit);
        NoneLineedit->setPlaceholderText("在此输入闹钟备注");
        connect(NoneLineedit, &QLineEdit::textChanged, this, &Form3::NoneLineedit_textChanged);
    }

    if (Index == TEMPORARY)
    {
        ui->AlarmTable->setIndexWidget(model->index(row, 2), nullptr);
        QComboBox* TagCmb = new QComboBox();
        TagCmb->addItems({"只响一次  "});
        ui->AlarmTable->setIndexWidget(model->index(row, 2), TagCmb);
        connect(TagCmb, &QComboBox::currentIndexChanged, this, &Form3::on_TagCmb_activated);
        all_alarm[alarm_index].alarm_tag = ONCE;
    }
    else if (Index == CLASS)
    {
        ui->AlarmTable->setIndexWidget(model->index(row, 2), nullptr);
        QComboBox*WeekCmb = new QComboBox();
        WeekCmb->addItems({"星期一  ", "星期二  ", "星期三  ", "星期四  ", "星期五  ", "星期六  ", "星期天  "});
        ui->AlarmTable->setIndexWidget(model->index(row, 2), WeekCmb);
        connect(WeekCmb, &QComboBox::currentIndexChanged, this, &Form3::on_WeekCmb_activated);
        all_alarm[alarm_index].alarm_tag = WEEKLY;
    }
    else
    {
        ui->AlarmTable->setIndexWidget(model->index(row, 2), nullptr);
        QComboBox* TagCmb = new QComboBox();
        TagCmb->addItems({"只响一次  ", "每天一次  ", "每周一次  "});
        ui->AlarmTable->setIndexWidget(model->index(row, 2), TagCmb);
        connect(TagCmb, &QComboBox::currentIndexChanged, this, &Form3::on_TagCmb_activated);
    }

}

#include <sstream>

void Form3::on_AfterclassCmb_activated(const QString& text)
{
    ui->AlarmTable->resizeRowsToContents();
    if (text == "您未选择事件或是选择的事件已改变,请重新选择")
        return;
    QModelIndexList selectList = ui->AlarmTable->selectionModel()->selectedIndexes();
    QModelIndex index = selectList.first();
    int ID = model->item(index.row(), 5)->data().toInt();
    int alarm_index = find_alarm_index(ID);
    all_alarm[alarm_index].tip = text;

    format_QString_to_Event(text, all_alarm[alarm_index].alarm_event);

}

bool Form3::format_QString_to_Event(const QString &text, Event &tar)
{
    istringstream in(text.toStdString());
    string event_name_temp;
    in >> event_name_temp;
    QString event_name = QString::fromStdString(event_name_temp);
    auto p = current_user->namequeue[event_name];

    for (auto a : p)
    {
        Event tmp = current_user->perEvents[a.first_index][a.second_index][a.count-1];
        QString time;
        time = alarm_to_format_QString(tmp);
        if (time == text)
        {
            tar = tmp;
            return true;
        }
    }

    return false;
}

void Form3::on_TemporaryCmb_activated(const QString& text)
{
    on_AfterclassCmb_activated(text);
}

void Form3::on_ClassCmb_activated(const QString& text)
{
    ui->AlarmTable->resizeRowsToContents();
    if (text == "您未选择事件或是选择的事件已改变,请重新选择")
        return;
    QModelIndexList selectList = ui->AlarmTable->selectionModel()->selectedIndexes();
    QModelIndex index = selectList.first();
    int ID = model->item(index.row(), 5)->data().toInt();
    for (auto it = all_alarm.begin(); it != all_alarm.end(); it ++)
    {
        if (it->tip == text)
        {
            it->IsUsed = false;
            break;
        }
    }
    int alarm_index = find_alarm_index(ID);

    all_alarm[alarm_index].tip = text;

    format_QString_to_Event(text, all_alarm[alarm_index].alarm_event);

}

void Form3::NoneLineedit_textChanged (const QString& text)
{
    QModelIndexList selectList = ui->AlarmTable->selectionModel()->selectedIndexes();
    QModelIndex index = selectList.first();
    int ID = model->item(index.row(), 5)->data().toInt();
    int alarm_index = find_alarm_index(ID);
    all_alarm[alarm_index].tip = text;
}

void Form3::detect_alarm ()
{
    _Time now=*ti;
    static _Time prev = {-1, -1, -1};

    now.time_now();
    if (prev.day() == now.day() && prev.hour() == now.hour() && prev.week() == now.week())
        return;

    for (auto &single : all_alarm)
    {
        if (!single.IsUsed)
            continue;
        if (single.alarm_tag == ONCE && single.IsRung)
            continue;
        if (single.alarm_tag != NONE && format_QString_to_Event(single.tip, single.alarm_event) == false)
            continue;

        if (single.alarm_tag == ONCE)
        {
            if (now.hour() == single.alarm_hour)
            {
                Ring(single);
                single.IsRung = true;
                single.IsUsed = false;
            }
        }
        else if (single.alarm_tag == DAYLY)
        {
            if (now.hour() == single.alarm_hour)
                Ring(single);
        }
        else if (single.alarm_tag == WEEKLY)
        {
            if (now.hour() == single.alarm_hour && now.day() == single.alarm_week+1)
                Ring(single);
        }
    }

    prev = now;
}


void Form3::read_alarm_file (void)
{
    int cnt = 0;
    for (auto pQString : current_user->event_names)
    {
        auto p_arrayindex = current_user->namequeue[pQString];
        for (auto a : p_arrayindex)
        {
            Event event_temp = current_user->perEvents[a.first_index][a.second_index][a.count-1];
            if (event_temp.Tag != 1 && event_temp.Tag != 2)
                continue;

            Alarm alarm_temp;
            alarm_temp.alarm_event = event_temp;
            alarm_temp.alarm_hour = event_temp.start.hour() - 1;
            alarm_temp.alarm_tag = WEEKLY;
            alarm_temp.alarm_week = event_temp.start.day() - 1;
            alarm_temp.event_tag = CLASS;
            alarm_temp.IsRung = true;
            alarm_temp.IsUsed = true;
            alarm_temp.tip = alarm_to_format_QString(event_temp);
            alarm_temp.index = cnt;
            cnt ++;

            all_alarm.push_back(alarm_temp);
        }
    }


    QFile alarm_file("./information_file/perevent/" + QString::number(current_user->ID) + "_alarm.txt");
    if (!alarm_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "alarm_file not open in write_alarm_file";
        return;
    }
    QTextStream alarm_in(&alarm_file);

    while (!alarm_in.atEnd())
    {
        QString line_temp = alarm_in.readLine();
        QTextStream line_in(&line_temp);
        Alarm alarm_temp;
        int IsUsed_value, IsRung_value;
        line_in >> IsUsed_value >> alarm_temp.alarm_hour >> alarm_temp.alarm_week
            >> alarm_temp.alarm_tag >> alarm_temp.event_tag >> IsRung_value;
        char erasespace;
        line_in >> erasespace;
        alarm_temp.tip = line_in.readLine();
        alarm_temp.IsUsed = IsUsed_value;
        alarm_temp.IsRung = IsRung_value;
        alarm_temp.index = cnt;

        if (alarm_temp.event_tag == NONE || format_QString_to_Event(alarm_temp.tip, alarm_temp.alarm_event))
        {
            cnt ++;
            all_alarm.push_back(alarm_temp);
        }
    }
    alarm_file.close();

}

void Form3::write_alarm_file (void)
{
    QFile alarm_file("./information_file/perevent/" + QString::number(current_user->ID) + "_alarm.txt");
    if (!alarm_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "alarm_file not open in write_alarm_file";
        return;
    }
    QTextStream alarm_out(&alarm_file);
    for (auto single : all_alarm)
    {
        if (single.event_tag == CLASS)
            if ((single.alarm_event.start.hour()-single.alarm_hour) == 1)
                if (single.alarm_week+1 == single.alarm_event.start.day())
                    continue;

        alarm_out << single.IsUsed << " ";
        alarm_out << single.alarm_hour << " ";
        alarm_out << single.alarm_week << " ";
        alarm_out << single.alarm_tag << " ";
        alarm_out << single.event_tag << " ";
        alarm_out << single.IsRung << " ";
        alarm_out << single.tip;

        if (single != *all_alarm.rbegin())
            alarm_out << "\n";
    }
    alarm_file.close();
}

void Form3::Ring (Alarm &single)
{
    ti->time_suspend();
    emit alarm_ring();
    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput * audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("../campus_management/mp3/alarm.wav"));
    audioOutput->setVolume(50);
    player->play();

    vector<QString> tag_QString = {"课程", "课余活动", "临时活动", ""};
    QString text;
    text += "现在的时间是" + QString::number(single.alarm_hour) + ":00\n";
    text += tag_QString[single.event_tag] + " " + single.tip;


    QMessageBox msgBox = QMessageBox(QMessageBox::Warning, "您有一个闹钟", text);

    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    auto * yesButton = msgBox.button(QMessageBox::Save);
    yesButton->setText("跳转到导航");
    auto * noButton = msgBox.button(QMessageBox::Cancel);
    noButton->setText("OK");

    msgBox.exec();


    if (msgBox.clickedButton() == yesButton) {
        player->stop();
        delete player;
        delete audioOutput;
        emit jmp_to_guide(single.alarm_event.building);
    }
    else
    {
        player->stop();
        delete player;
        delete audioOutput;
    }


}

QString Form3::alarm_to_format_QString(Event &tmp)
{
    QString time;
    QString indextoword{"一二三四五六日"};

    time += tmp.name;
    time += " 周数:";
    if (tmp.Tag != 1 && tmp.Tag != 2)
    {
        for(auto tempweek:tmp.weeks)
        {
            time+=" ";
            time+=QString::number(tempweek);
        }
    }
    else
    {
        time += " 每周都有";
    }
    time +=" 周";
    time += indextoword[tmp.start.day()-1];
    time += " ";
    time += QString::number(tmp.start.hour());
    time +=":00~";
    time += QString::number(tmp.end.hour());
    time +=":00 ";
    time += "地点: ";
    time += tmp.building.name_();

    return time;
}

void Form3::on_deleteButton_clicked()
{
    QModelIndexList selectList = ui->AlarmTable->selectionModel()->selectedIndexes();
    if (!selectList.size())
        return;
    int row = selectList.at(0).row();

    int ID = model->item(row, 5)->data().toInt();
    int alarm_index = find_alarm_index(ID);
    auto single = all_alarm.begin()+alarm_index;

    qDebug()<<"删除为"<<single->tip<<"设置的闹钟";
    all_alarm.erase(all_alarm.begin()+alarm_index);


    model->removeRows(row, 1);
}


void Form3::show_log(int num)
{
    if(num == 0)
        ui->label_log->setText(current_user->log);
}
void Form3::set_time(const QString &tmp)
{
    ui->cb_week->setCurrentIndex(ti->week()-1);
    ui->label_time->setText(tmp);
    if(ti->is_continue()==1)
        ui->bt_pause->setStyleSheet("border-image: url(:/picture/continue_white.png);background-color: rgba(229, 229, 229, 0);");
    else
        ui->bt_pause->setStyleSheet("border-image: url(:/picture/pause_white.png);background-color: rgba(229, 229, 229, 0);");
}
void Form3::timeUpdate()
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
void Form3::time_pause()
{
    if(ti->is_continue()==0)
    {
        ti->time_continue();
    ui->bt_pause->setStyleSheet("border-image: url(:/picture/continue_white.png);color: rgba(255, 255, 255, 0);");
    }
    else
    {
        ti->time_suspend();
    ui->bt_pause->setStyleSheet("border-image: url(:/picture/pause_white.png);color: rgba(255, 255, 255, 0);");
    }
}
void Form3::FF_hour()
{
    ti->time_now();
    ti->time_set(ti->week(),ti->day(),ti->hour()+1);
    timeUpdate();
}
void Form3::FF_day()
{
    ti->time_now();
    ti->time_set(ti->week(),ti->day()+1,ti->hour());
    timeUpdate();
}
void Form3::set_week()
{
    if(ti->is_init()==1)
    {
    ti->time_set(ui->cb_week->currentIndex()+1,1,0);
    timeUpdate();
    }
}

void Form3::show_one_day_event()
{
    QString information;
    _Time a;
    ti->time_now();
    int week =ti->week();
    int now_hour = ti->hour();

    if(now_hour<20)
    {
        ui->label_title->setText("今日事务");
        int day= ti->day();
        for(int hour = 6;hour<22;hour++)
        {
            vector<int> search_outcome = current_user->find_index(week,day,hour);
            if(search_outcome.size()!=0)//该时间是否有事件
            {
                information.append(QString::number(hour)).append(":00 ~ ").append(QString::number(hour+1)).append(":00\t");
                for(auto a:search_outcome)
                {
                    Event temp = current_user->perEvents[day-1][hour-6][a];
                    information.append(temp.name).append("  ").append(temp.building.name_());
                }
                information.append("\n");
            }
        }
        ui->label_one_day_event->setText(information);
    }
    else
    {
        ui->label_title->setText("明日事务");
        int day= ti->day()+1;
        for(int hour = 6;hour<22;hour++)
        {
            vector<int> search_outcome = current_user->find_index(week,day,hour);
            if(search_outcome.size()!=0)//该时间是否有事件
            {
                information.append(QString::number(hour)).append(":00 ~ ").append(QString::number(hour+1)).append(":00\t");
                for(auto a:search_outcome)
                {
                    Event temp = current_user->perEvents[day-1][hour-6][a];
                    information.append(temp.name).append("  ").append(temp.building.name_());
                }
                information.append("\n");
            }
        }
        ui->label_one_day_event->setText(information);
    }


}


void Form3::keysearch()
{
    ui->tableWidget_outcome->clearContents();
    ui->tableWidget_outcome->setRowCount(1);
    ui->label_foundation->setText("关键词检索");
    int tag = ui->comboBox_choose_tag->currentIndex();
    int hour = ui->comboBox_choose_hour->currentIndex();
    int day = ui->comboBox_choose_day->currentIndex();
    int hour_end;
    int day_end;
    int hour_begin;
    int day_begin;
    int line =0;

    if(hour == 0)
    {
        hour_end = HOURS;
        hour_begin= 0;
    }
    else
    {
        hour_end = hour;
        hour_begin = hour-1;
    }
    if(day == 0)
    {
        day_end = DAY;
        day_begin =0;
    }
    else
    {
        day_end = day;
        day_begin=day-1;
    }

    for(int count = day_begin;count< day_end;count++)
        for(int i = hour_begin;i<hour_end;i++ )
        {
            for(auto temp:current_user->perEvents[count][i])
            {
                if(temp.Tag == tag ||tag ==0)
                {
                    QString type;
                    QString time;
                    QString week;
                    QString address;
                    QString tip;

                    switch (temp.Tag)
                    {
                        case 1:if(temp.name.endsWith("考试"))
                            type.append("必修课考试");
                        else
                            type.append("必修课");
                        break;
                        case 2:if(temp.name.endsWith("考试"))
                            type.append("选修课考试");
                        else
                            type.append("选修课");
                        break;
                        case 3:type.append("集体事务");break;
                        case 4:type.append("个人事务");break;
                        case 5:type.append("临时事务");break;
                    }

                    type.append("--").append(temp.name);

                    time += number_to_week(temp.start.day());
                    time+=" ";
                    time+=QString::number(temp.start.hour());
                    time+=":00~";
                    time+=QString::number(temp.end.hour());
                    time+=":00";

                    if((temp.Tag==1 || temp.Tag ==2)&&!(temp.name.endsWith("考试")))
                        week+="每周都有";
                    else
                    {
                        for(auto tempweek:temp.weeks)
                        {
                            week+=QString::number(tempweek);
                            week+=" ";
                        }
                    }

                    address =temp.building.name_();

                    if(temp.Tag ==1||temp.Tag ==2)
                     {
                        QString exam_name = temp.name +"考试";
                        if(current_user->namequeue.find(exam_name)!=current_user->namequeue.end())
                            tip.append("已发布考试");
                      }
                    else if(temp.Tag == 3)
                    {
                        tip.append("参加学生：");
                        for(auto tempID:temp.ID)
                        {
                            tip.append(QString::number(tempID)).append(" ");
                        }
                    }

                    ui->tableWidget_outcome->setItem(line,0,new QTableWidgetItem(type));
                    ui->tableWidget_outcome->item(line,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                    ui->tableWidget_outcome->setItem(line,1,new QTableWidgetItem(time));
                    ui->tableWidget_outcome->item(line,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                    ui->tableWidget_outcome->setItem(line,2,new QTableWidgetItem(week));
                    ui->tableWidget_outcome->item(line,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                    ui->tableWidget_outcome->setItem(line,3,new QTableWidgetItem(address));
                    ui->tableWidget_outcome->item(line,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                    ui->tableWidget_outcome->setItem(line,4,new QTableWidgetItem(tip));
                    ui->tableWidget_outcome->item(line,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                    line++;
                    ui->tableWidget_outcome->insertRow(line);
                }
            }
        }

}




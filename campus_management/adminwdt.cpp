#include "adminwdt.h"
#include "ui_adminwdt.h"
#include"QDebug"
#include"QModelIndex"
#include <QListView>
#include <QListWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QCheckBox>
#include <QCompleter>

static Map * Bupt_map = new Map;

static QStringList local_QStringList = {"北邮科技酒店", "青年公寓", "学十三公寓", "邮局", "移动营业厅",
"学十一公寓","学九公寓", "学十公寓", "留学生公寓", "综合食堂",
"学五公寓", "学八公寓",
"学三公寓", "学四公寓", "学一公寓", "学二公寓", "教四楼",
"教三楼", "校医院", "时光咖啡", "南区超市",
"电信营业厅","经管楼", "学生活动中心", "学六公寓","澡堂", "水房", "教工餐厅", "图书馆",
"财务处", "行政办公楼", "教一楼", "主楼", "教二楼", "中门邮局", "科研大楼", "学生食堂",
"保卫处","篮球场", "网球场","学29公寓", "体育馆", "游泳馆", "科学会堂", "通信中心", "体育场", "西门", "北门",
"中门","东北门", "东门"};

adminwdt::adminwdt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminwdt)
{
    ui->setupUi(this);
    refresh = 0;
    positioning_tag =0;
    event_position.count = -1;
    Bupt_map->get_Map();

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
    QVBoxLayout *name_layout = new QVBoxLayout();
    ui->name_wdt->setLayout(name_layout);
    init_name_wdt(ADD);
    QVBoxLayout *local_layout = new QVBoxLayout();
    ui->local_wdt->setLayout(local_layout);
    init_local_wdt(OFFLINE);
    ui->offline_Button->setChecked(true);
}

bool adminwdt::add_event(Event & insert_event)
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
            return false;
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
            for (int i = insert_event.start.hour()-6; i != insert_event.end.hour()-6; i ++)
                current_user->perEvents[insert_event.start.day()-1][i].push_back(insert_event);
            if(current_user->namequeue.find(insert_event.name)==current_user->namequeue.end())
                current_user->event_names.push_back(insert_event.name);
            current_user->namequeue[insert_event.name].push_back({insert_event.start.day()-1,insert_event.start.hour()-6,(int)current_user->perEvents[insert_event.start.day()-1][insert_event.start.hour()-6].size()});
        }//未找到属性一致的事件，新增事件

        refresh=1;
        return true;
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
            return false;
    }

}


void adminwdt::delete_event()
{
    qDebug()<<"delete";
    QMessageBox msgBox;
    Event event_tmp = current_user->perEvents[event_position.first_index][event_position.second_index][event_position.count-1];

    for (int i = event_tmp.start.hour()-6; i != event_tmp.end.hour()-6; i ++)
        current_user->perEvents[event_position.first_index][i].erase(current_user->perEvents[event_position.first_index][i].begin() + event_position.count - 1);

    if ((int)current_user->namequeue[event_tmp.name].size() > 1)
    {
        auto vector_tmp = current_user->namequeue[event_tmp.name];
        vector_tmp.erase(std::remove(vector_tmp.begin(), vector_tmp.end(), event_position), vector_tmp.end());
    }
    else
        current_user->namequeue.erase(event_tmp.name);


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
    if (student_ID.size())
        if (*it == 88888888)
            it ++;

    QListWidget *ID_sel_listwdt = new QListWidget;
    for (int i = 0; i <= 9; ++i) {
        QListWidgetItem* pItem = new QListWidgetItem();// 增加listwidget的item
        pItem->setData(Qt::UserRole, i+2021210);

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


void adminwdt::init_name_wdt (int status, vector<QString> Event_names)
{
    QLayout * name_layout = ui->name_wdt->layout();
    if (name_layout)
        delete name_layout;
    name_layout = new QVBoxLayout();
    ui->name_wdt->setLayout(name_layout);

    if (status ==  ADD)
    {
        QLineEdit * name_lineedit = new QLineEdit;
        name_lineedit->setPlaceholderText("在此输入要添加的事件名称");
        name_layout->addWidget(name_lineedit);
    }
    else if (status == CHANGE)
    {
        QComboBox * name_sel_combo = new QComboBox;
        for (auto single : Event_names)
            name_sel_combo->addItem(single);
        name_layout->addWidget(name_sel_combo);
        connect(name_sel_combo, &QComboBox::currentIndexChanged, this, &adminwdt::Show_index_index_class);
    }
}


void adminwdt::init_local_wdt (int status, QString building_name)
{
    QLayout * local_layout = ui->local_wdt->layout();
    if (local_layout)
        delete local_layout;
    local_layout = new QVBoxLayout();
    ui->local_wdt->setLayout(local_layout);


    QLineEdit * local_lineedit;
    if (status == ONLINE)
    {
        local_lineedit = new QLineEdit;
        local_lineedit->setPlaceholderText("在此输入线上上课网址");
        local_layout->addWidget(local_lineedit);
    }
    else if (status == OFFLINE)
    {
        QComboBox * local_sel_combo = new QComboBox;
        local_sel_combo->addItems(local_QStringList);
        local_lineedit = new QLineEdit;
        QCompleter *local_infor = new QCompleter(local_QStringList);
        local_lineedit->setCompleter(local_infor);
        local_infor->setFilterMode(Qt::MatchFlag::MatchContains);
        local_sel_combo->setLineEdit(local_lineedit);
        local_sel_combo->setInsertPolicy(QComboBox::NoInsert);
        local_layout->addWidget(local_sel_combo);
    }

    if (!building_name.isEmpty())
        local_lineedit->setText(building_name);
}


void adminwdt::on_online_Button_clicked()
{
    init_local_wdt(ONLINE);
}


void adminwdt::on_offline_Button_clicked()
{
    init_local_wdt(OFFLINE);
}



void adminwdt::on_tableWidget_cellClicked(int row, int column)
{
    event_position.first_index = column;
    event_position.second_index = row;
    event_position.count = 1;

    Show_index_class(current_user->perEvents[column][row]);
}


void adminwdt::Show_index_class (vector<Event> curriculum)
{
    if (curriculum.empty())
    {
        init_name_wdt(ADD);
        ui->Tag_sel_combo->setCurrentIndex(0);
        init_local_wdt(OFFLINE);
        ui->offline_Button->setChecked(true);
        ui->day_sel_combo->setCurrentIndex(event_position.first_index);
        ui->start_time_sel_combo->setCurrentIndex(event_position.second_index);
        ui->end_time_sel_combo->setCurrentIndex(event_position.second_index);
        init_week_sel_combo({});
        init_ID_sel_combo({});
        return;
    }

    vector<QString> event_names;
    for (auto single : curriculum)
        event_names.push_back(single.name);

    init_name_wdt(CHANGE, event_names);

    Show_index_index_class(0);
}


void adminwdt::Show_index_index_class (int index)
{
    event_position.count = index+1;
    Event tmp = current_user->perEvents[event_position.first_index][event_position.second_index][index];

    int Tag_to_index[] = {-1, 0, 1, 2};
    ui->Tag_sel_combo->setCurrentIndex(Tag_to_index[tmp.Tag]);

    ui->offline_Button->setChecked(tmp.building.id_() >= 134);
    ui->online_Button->setChecked(tmp.building.id_() >= 134);
    init_local_wdt(tmp.building.id_() < 134, tmp.building.name_());

    ui->day_sel_combo->setCurrentIndex(tmp.start.day()-1);
    ui->start_time_sel_combo->setCurrentIndex(tmp.start.hour()-6);
    ui->end_time_sel_combo->setCurrentIndex(tmp.end.hour()-7);
    if (tmp.Tag == 1 || tmp.Tag == 2)
        init_week_sel_combo({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});
    else
        init_week_sel_combo(tmp.weeks);
    init_ID_sel_combo(tmp.ID);
}

QString adminwdt::Event_to_format_QString (Event &single)
{
    QString text;
    vector<QString> Tag_to_QString = {"", "必修课", "选修课", "集体事物"};
    vector<QString> week_to_QString = {"", "周一", "周二", "周三", "周四", "周五", "周六", "周日"};
    text += "事件名称: " + single.name + "\n";
    text += "事件类型: " + Tag_to_QString[single.Tag] + "\n";
    text += "事件时间: " + week_to_QString[single.start.day()] + " " + QString::number(single.start.hour()) + ":00 ~ " + QString::number(single.end.hour()) + ":00\n";
    text += "事件地点: " + single.building.name_() + "\n";

    text += "事件周数: ";
    if (single.Tag == 1 || single.Tag == 2)
        text += "每周都有\n";
    else
    {
        auto p = single.weeks.begin();
        text += "第" + QString::number(*p) + "周";
        for ( ; p != single.weeks.end(); p ++)
            text += ", 第" + QString::number(*p) + "周";
        text += "\n";
    }

    text += "事件参与人数: ";
    if (single.Tag == 1)
        text += "每人都有\n";
    else
    {
        auto p = single.ID.begin();
        text += QString::number(*p);
        for ( ; p != single.ID.end(); p ++)
            text += ", " + QString::number(*p);
        text += "\n";
    }

    return text;
}

void adminwdt::on_delete_Button_clicked()
{
    if (ui->name_wdt->layout()->itemAt(0)->widget()->inherits("QLineEdit"))
    {
        QMessageBox::information(this,
                                 tr("警告"), tr("您当前为输入模式，不能删除！"),
                                 QMessageBox::Ok , QMessageBox::Ok);
        return;
    }

    Event tmp = current_user->perEvents[event_position.first_index][event_position.second_index][event_position.count-1];
    QString text = "您当前选择的事件如下:\n\n";
    text += Event_to_format_QString(tmp);
    text += "\n是否删除?";

    QMessageBox msgBox = QMessageBox(QMessageBox::Warning, "删除确认", text);

    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    auto * yesButton = msgBox.button(QMessageBox::Save);
    yesButton->setText("确认删除");
    auto * noButton = msgBox.button(QMessageBox::Cancel);
    noButton->setText("取消删除");

    msgBox.exec();

    if (msgBox.clickedButton() == yesButton)
    {
        delete_event();
        show_percurriculum();
        Show_index_class(current_user->perEvents[event_position.first_index][event_position.second_index]);
        QMessageBox::information(this,
                                 tr("提示"), tr("删除成功"),
                                 QMessageBox::Ok , QMessageBox::Ok);
    }
}

Event adminwdt::handle_evevt (void)
{
    Event ret;

    if (ui->name_wdt->layout()->itemAt(0)->widget()->inherits("QLineEdit"))
        ret.name = ((QLineEdit*)ui->name_wdt->layout()->itemAt(0)->widget())->text();
    else
        ret.name = ((QComboBox*)ui->name_wdt->layout()->itemAt(0)->widget())->currentText();

    ret.Tag = ui->Tag_sel_combo->currentIndex() + 1;
    ret.start.day() = ret.end.day() = ui->day_sel_combo->currentIndex() + 1;
    ret.start.hour() = ui->start_time_sel_combo->currentIndex() + 6;
    ret.end.hour() = ui->end_time_sel_combo->currentIndex() + 7;

    QWidget * l_wdt = ui->local_wdt->layout()->itemAt(0)->widget();
    if (ui->offline_Button->isCheckable())
    {
        int id = Bupt_map->findBuilding(((QComboBox *) l_wdt)->currentText());
        ret.building = Bupt_map->Get_i_Building(id);
    }
    else if (ui->online_Button->isCheckable())
    {
        Bupt_map->save_netBuilding(((QLineEdit*) l_wdt)->text());
        int id = Bupt_map->findBuilding(((QLineEdit*) l_wdt)->text());
        ret.building = Bupt_map->Get_i_Building(id);
    }

    if (ret.Tag == 3)
    {
        ret.periodicity = 0;
        QListWidget *weel_sel_listwdt = (QListWidget *) (ui->week_sel_combo->view());

        int nCount = weel_sel_listwdt->count();
        for (int i = 0; i < nCount; ++i)
        {
            QListWidgetItem *pItem = weel_sel_listwdt->item(i);
            QWidget *pWidget = weel_sel_listwdt->itemWidget(pItem);
            QCheckBox *pCheckBox = (QCheckBox *)pWidget;
            if (pCheckBox->isChecked())
            {
                ret.weeks.push_back(pItem->data(Qt::UserRole).toInt());
                ret.periodicity ++;
            }
        }
    }

    QListWidget *ID_sel_listwdt = (QListWidget *) (ui->ID_sel_combo->view());


    int nCount = ID_sel_listwdt->count();
    for (int i = 0; i < nCount; ++i)
    {
        QListWidgetItem *pItem = ID_sel_listwdt->item(i);
        QWidget *pWidget = ID_sel_listwdt->itemWidget(pItem);
        QCheckBox *pCheckBox = (QCheckBox *)pWidget;
        if (pCheckBox->isChecked())
        {
            ret.ID.push_back(pItem->data(Qt::UserRole).toInt());
        }
    }

    return ret;
}


void adminwdt::on_change_Button_clicked()
{
    if (ui->name_wdt->layout()->itemAt(0)->widget()->inherits("QLineEdit"))
    {
        QMessageBox::information(this,
                                 tr("警告"), tr("您当前为输入模式，不能修改！"),
                                 QMessageBox::Ok , QMessageBox::Ok);
        return;
    }

    Event now = handle_evevt();
    Event tmp = current_user->perEvents[event_position.first_index][event_position.second_index][event_position.count-1];
    QString text = "您当前选择的事件如下:\n\n";
    text += Event_to_format_QString(tmp);
    text += "\n是否修改为以下事件?\n\n";
    text += Event_to_format_QString(now);


    QMessageBox msgBox = QMessageBox(QMessageBox::Warning, "修改确认", text);

    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    auto * yesButton = msgBox.button(QMessageBox::Save);
    yesButton->setText("确认修改");
    auto * noButton = msgBox.button(QMessageBox::Cancel);
    noButton->setText("取消修改");

    msgBox.exec();

    if (msgBox.clickedButton() == yesButton) {
        delete_event();
        if (add_event(now) == true)
        {
            show_percurriculum();
            Show_index_class(current_user->perEvents[event_position.first_index][event_position.second_index]);
            QMessageBox::information(this,
                                     tr("提示"), tr("修改成功"),
                                     QMessageBox::Ok , QMessageBox::Ok);
        }
        else
        {
            add_event(tmp);
            show_percurriculum();
            Show_index_class(current_user->perEvents[event_position.first_index][event_position.second_index]);
        }
    }
}


void adminwdt::on_add_Button_clicked()
{
    if (ui->name_wdt->layout()->itemAt(0)->widget()->inherits("QComboBox"))
    {
        init_name_wdt(ADD);
        QMessageBox::information(this,
                                 tr("提示"), tr("当前已改为输入模式，请输入课程"),
                                 QMessageBox::Ok , QMessageBox::Ok);
        return;
    }

    Event now = handle_evevt();
    QString text = "您当前添加的事件如下:\n\n";
    text += Event_to_format_QString(now);
    text += "\n是否添加?";


    QMessageBox msgBox = QMessageBox(QMessageBox::Warning, "添加确认", text);

    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    auto * yesButton = msgBox.button(QMessageBox::Save);
    yesButton->setText("确认添加");
    auto * noButton = msgBox.button(QMessageBox::Cancel);
    noButton->setText("取消添加");

    msgBox.exec();

    if (msgBox.clickedButton() == yesButton) {
        if (add_event(now) == true)
        {
            show_percurriculum();
            Show_index_class(current_user->perEvents[now.start.day()-1][now.start.hour()-6]);
            QMessageBox::information(this,
                                     tr("提示"), tr("添加成功"),
                                     QMessageBox::Ok , QMessageBox::Ok);
        }
    }
}


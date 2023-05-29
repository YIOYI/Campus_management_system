#include "insert_event.h"
#include "ui_insert_event.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->widget->show();
    setWindowTitle("加入事件");
    connect(ui->comboBox,&QComboBox::currentIndexChanged,this,&Dialog::wideget_control);
    connect(ui->pushButton_ID,&QPushButton::clicked,this,&Dialog::insert_ID);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::insert_ID()
{
    int buffer_ID = ui->comboBox_ID->currentText().toInt();
    qDebug()<<buffer_ID<<current_ID;
    if(buffer_ID==current_ID)
        return;
    else
    {
        for(auto a:ID)
            if(a ==buffer_ID)
                return ;

        ID.push_back(buffer_ID);
        label_ID.append(ui->comboBox_ID->currentText()).append(" ");
    }
    if(ID.size()%4==0)
        label_ID.append("\n");
    ui->label_ID->setText(label_ID);
}

void Dialog::wideget_control()
{
    if(ui->comboBox->currentIndex()==0)
        ui->widget->show();
    else
        ui->widget->hide();
}



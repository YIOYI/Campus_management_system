#include "form3.h"
#include "ui_form3.h"

Form3::Form3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form3)
{
    ui->setupUi(this);
    QImage img (":/picture/mkim1.png");
    //img = (img.scaled(0.5*img->width(),0.5*img->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->label->setPixmap(QPixmap::fromImage(img));

    QAction * searchAction = new QAction(ui->lineEdit);
    searchAction->setIcon(QIcon(":/picture/search.png"));
    ui->lineEdit->addAction(searchAction,QLineEdit::LeadingPosition);
}

Form3::~Form3()
{
    delete ui;
}

void Form3::init_form3(Person *a)
{
    current_user =a;
    ui->label_name->setText(current_user->getname());
    ui->label_ID->setText(QString::number(current_user->getID()));
    QString address =":/picture/";
    address +=QString::number(current_user->getID());
    address +=".png";
    QImage image(address);
    ui->label_image->setPixmap(QPixmap::fromImage(image));
    //ui->tableWidget->hide();
}

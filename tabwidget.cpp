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
    delete ui;
}

void TabWidget::init(Person* user_information)
{
    current_user = user_information;
    page1->init_form1(current_user);
    page3->init_form3(current_user);
    show();
}

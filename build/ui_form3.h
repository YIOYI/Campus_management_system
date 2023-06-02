/********************************************************************************
** Form generated from reading UI file 'form3.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM3_H
#define UI_FORM3_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *label_foundation_2;
    QTableView *AlarmTable;
    QPushButton *pushButton;
    QPushButton *deleteButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label_log;
    QLabel *label_foundation_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QLabel *label_one_day_event;
    QLabel *label_title;
    QLabel *label_5;
    QTableWidget *tableWidget_search;
    QLabel *label_image;
    QLabel *label_foundation;
    QTableWidget *tableWidget_outcome;
    QLabel *label_name;
    QLabel *label_college;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_major;
    QLabel *label_ID;
    QLabel *label_xuehao;
    QLabel *label_4;
    QLabel *label_xinming;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton_quit;
    QPushButton *pushButton_correct;
    QFrame *frame_time;
    QPushButton *bt_day;
    QPushButton *bt_hour;
    QComboBox *cb_week;
    QLabel *label_time;
    QPushButton *bt_pause;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName("Form3");
        Form3->resize(1578, 900);
        QFont font;
        font.setPointSize(13);
        Form3->setFont(font);
        Form3->setStyleSheet(QString::fromUtf8(""));
        lineEdit = new QLineEdit(Form3);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(390, 70, 751, 51));
        QFont font1;
        font1.setPointSize(14);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"border-radius: 20px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"padding: 0 8px;/*\345\246\202\346\236\234\346\262\241\346\234\211\345\206\205\345\256\271\345\205\211\346\240\207\345\234\250\345\274\200\345\247\213\345\276\200\345\220\216\347\247\273\345\212\2500.8\345\203\217\347\264\240\347\202\271*/\n"
"selection-background-color: darkgray;\n"
"background-color: rgb(229, 229, 229);\n"
"\n"
""));
        label = new QLabel(Form3);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 1581, 401));
        label->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(Form3);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 430, 1581, 461));
        groupBox->setStyleSheet(QString::fromUtf8("border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"background-color: rgba(255, 170, 127, 150);\n"
""));
        label_foundation_2 = new QLabel(groupBox);
        label_foundation_2->setObjectName("label_foundation_2");
        label_foundation_2->setGeometry(QRect(1020, 40, 464, 40));
        label_foundation_2->setFont(font1);
        label_foundation_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"border-top-left-radius: 20px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"border-top-right-radius: 20px\n"
""));
        label_foundation_2->setAlignment(Qt::AlignCenter);
        AlarmTable = new QTableView(groupBox);
        AlarmTable->setObjectName("AlarmTable");
        AlarmTable->setGeometry(QRect(1020, 80, 464, 251));
        AlarmTable->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1160, 350, 50, 50));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-bottom-right-radius: 25px;\n"
"border-bottom-left-radius: 25px;\n"
"border-top-left-radius: 25px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"border-top-right-radius: 25px\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/picture/add_alarm.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(56, 56));
        deleteButton = new QPushButton(groupBox);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(1310, 350, 48, 48));
        deleteButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-bottom-right-radius: 24px;\n"
"border-bottom-left-radius: 24px;\n"
"border-top-left-radius: 24px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"border-top-right-radius: 24px\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/picture/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);
        deleteButton->setIconSize(QSize(56, 56));
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(40, 60, 441, 391));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 439, 389));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName("gridLayout");
        label_log = new QLabel(scrollAreaWidgetContents);
        label_log->setObjectName("label_log");
        QFont font2;
        font2.setPointSize(12);
        label_log->setFont(font2);
        label_log->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"border-radius: 20px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/"));
        label_log->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_log, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        label_foundation_3 = new QLabel(groupBox);
        label_foundation_3->setObjectName("label_foundation_3");
        label_foundation_3->setGeometry(QRect(40, 20, 441, 40));
        label_foundation_3->setFont(font1);
        label_foundation_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"border-top-left-radius: 20px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"border-top-right-radius: 20px\n"
""));
        label_foundation_3->setAlignment(Qt::AlignCenter);
        scrollArea_2 = new QScrollArea(groupBox);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(500, 60, 491, 391));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 489, 389));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setObjectName("gridLayout_2");
        label_one_day_event = new QLabel(scrollAreaWidgetContents_2);
        label_one_day_event->setObjectName("label_one_day_event");
        label_one_day_event->setFont(font2);
        label_one_day_event->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_one_day_event->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(label_one_day_event, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        label_title = new QLabel(groupBox);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(500, 20, 491, 40));
        label_title->setFont(font1);
        label_title->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"border-top-left-radius: 20px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"border-top-right-radius: 20px\n"
""));
        label_title->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(Form3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 80, 301, 311));
        QFont font3;
        font3.setPointSize(18);
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"background-color: rgba(229, 229, 229, 100);\n"
"border-radius: 20px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/"));
        label_5->setAlignment(Qt::AlignCenter);
        tableWidget_search = new QTableWidget(Form3);
        tableWidget_search->setObjectName("tableWidget_search");
        tableWidget_search->setGeometry(QRect(390, 71, 751, 291));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font4.setPointSize(11);
        tableWidget_search->setFont(font4);
        tableWidget_search->setStyleSheet(QString::fromUtf8("background-color: rgba(74, 74, 74, 100);\n"
"selection-background-color: rgba(255, 170, 0, 100);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 20px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"padding: 0 8px;/*\345\246\202\346\236\234\346\262\241\346\234\211\345\206\205\345\256\271\345\205\211\346\240\207\345\234\250\345\274\200\345\247\213\345\276\200\345\220\216\347\247\273\345\212\2500.8\345\203\217\347\264\240\347\202\271*/"));
        tableWidget_search->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_search->horizontalHeader()->setVisible(false);
        tableWidget_search->horizontalHeader()->setDefaultSectionSize(730);
        tableWidget_search->verticalHeader()->setDefaultSectionSize(51);
        label_image = new QLabel(Form3);
        label_image->setObjectName("label_image");
        label_image->setGeometry(QRect(50, 100, 110, 110));
        label_image->setFont(font);
        label_image->setAlignment(Qt::AlignCenter);
        label_foundation = new QLabel(Form3);
        label_foundation->setObjectName("label_foundation");
        label_foundation->setGeometry(QRect(1180, 90, 381, 51));
        QFont font5;
        font5.setPointSize(10);
        label_foundation->setFont(font5);
        label_foundation->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"border-top-left-radius: 20px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"border-top-right-radius: 20px"));
        label_foundation->setAlignment(Qt::AlignCenter);
        tableWidget_outcome = new QTableWidget(Form3);
        if (tableWidget_outcome->columnCount() < 5)
            tableWidget_outcome->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_outcome->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_outcome->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_outcome->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_outcome->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_outcome->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget_outcome->setObjectName("tableWidget_outcome");
        tableWidget_outcome->setGeometry(QRect(1180, 140, 381, 241));
        tableWidget_outcome->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"verticalHeader::section{rgba(255, 255, 255, 0);};"));
        tableWidget_outcome->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_outcome->horizontalHeader()->setVisible(true);
        tableWidget_outcome->horizontalHeader()->setDefaultSectionSize(129);
        tableWidget_outcome->verticalHeader()->setVisible(false);
        label_name = new QLabel(Form3);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(140, 220, 121, 28));
        label_name->setFont(font);
        label_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_college = new QLabel(Form3);
        label_college->setObjectName("label_college");
        label_college->setGeometry(QRect(140, 300, 151, 28));
        label_college->setFont(font);
        label_college->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_7 = new QLabel(Form3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(82, 300, 54, 28));
        label_7->setMinimumSize(QSize(54, 0));
        label_7->setMaximumSize(QSize(54, 16777215));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_8 = new QLabel(Form3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(82, 340, 54, 28));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_major = new QLabel(Form3);
        label_major->setObjectName("label_major");
        label_major->setGeometry(QRect(140, 340, 176, 28));
        label_major->setFont(font);
        label_major->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_ID = new QLabel(Form3);
        label_ID->setObjectName("label_ID");
        label_ID->setGeometry(QRect(140, 260, 161, 28));
        label_ID->setFont(font);
        label_ID->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_xuehao = new QLabel(Form3);
        label_xuehao->setObjectName("label_xuehao");
        label_xuehao->setGeometry(QRect(82, 260, 54, 28));
        label_xuehao->setMinimumSize(QSize(54, 0));
        label_xuehao->setMaximumSize(QSize(54, 16777215));
        label_xuehao->setFont(font);
        label_xuehao->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_4 = new QLabel(Form3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(272, 220, 32, 32));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/picture/girl.png")));
        label_xinming = new QLabel(Form3);
        label_xinming->setObjectName("label_xinming");
        label_xinming->setGeometry(QRect(82, 220, 54, 28));
        label_xinming->setMinimumSize(QSize(54, 0));
        label_xinming->setMaximumSize(QSize(54, 16777215));
        label_xinming->setBaseSize(QSize(0, 0));
        label_xinming->setFont(font);
        label_xinming->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_6 = new QLabel(Form3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(43, 217, 32, 32));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/picture/name.png")));
        label_9 = new QLabel(Form3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(43, 257, 32, 32));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/picture/id_card.png")));
        label_10 = new QLabel(Form3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(43, 297, 32, 32));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/picture/college.png")));
        label_11 = new QLabel(Form3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(43, 337, 32, 32));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/picture/major.png")));
        pushButton_quit = new QPushButton(Form3);
        pushButton_quit->setObjectName("pushButton_quit");
        pushButton_quit->setGeometry(QRect(190, 110, 111, 41));
        pushButton_quit->setFont(font);
        pushButton_quit->setStyleSheet(QString::fromUtf8("border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"border-radius: 15px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"background-color: rgba(34, 204, 254,100);"));
        pushButton_correct = new QPushButton(Form3);
        pushButton_correct->setObjectName("pushButton_correct");
        pushButton_correct->setGeometry(QRect(190, 160, 111, 41));
        pushButton_correct->setFont(font);
        pushButton_correct->setStyleSheet(QString::fromUtf8("border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"background-color: rgba(34, 204, 254,100);\n"
"border-radius: 15px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/"));
        frame_time = new QFrame(Form3);
        frame_time->setObjectName("frame_time");
        frame_time->setGeometry(QRect(1070, 10, 491, 171));
        frame_time->setFrameShape(QFrame::StyledPanel);
        frame_time->setFrameShadow(QFrame::Raised);
        bt_day = new QPushButton(frame_time);
        bt_day->setObjectName("bt_day");
        bt_day->setGeometry(QRect(440, 20, 31, 31));
        bt_day->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/day_white.png);\n"
"background-color: rgba(229, 229, 229, 0);"));
        bt_hour = new QPushButton(frame_time);
        bt_hour->setObjectName("bt_hour");
        bt_hour->setGeometry(QRect(390, 20, 31, 31));
        bt_hour->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/hour_white.png);\n"
"background-color: rgba(229, 229, 229, 0);"));
        cb_week = new QComboBox(frame_time);
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->addItem(QString());
        cb_week->setObjectName("cb_week");
        cb_week->setGeometry(QRect(120, 20, 91, 31));
        cb_week->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Microsoft YaHei UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"\n"
""));
        cb_week->setFrame(false);
        label_time = new QLabel(frame_time);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(210, 10, 121, 51));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setItalic(false);
        label_time->setFont(font6);
        label_time->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Microsoft YaHei UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(229, 229, 229, 0);\n"
""));
        label_time->setAlignment(Qt::AlignCenter);
        bt_pause = new QPushButton(frame_time);
        bt_pause->setObjectName("bt_pause");
        bt_pause->setGeometry(QRect(340, 20, 31, 31));
        bt_pause->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/continue_white.png);\n"
"background-color: rgba(229, 229, 229, 0);"));
        label_time->raise();
        bt_day->raise();
        bt_hour->raise();
        cb_week->raise();
        bt_pause->raise();
        label->raise();
        label_5->raise();
        label_college->raise();
        label_7->raise();
        label_8->raise();
        label_major->raise();
        label_ID->raise();
        label_xuehao->raise();
        groupBox->raise();
        tableWidget_search->raise();
        lineEdit->raise();
        label_image->raise();
        label_foundation->raise();
        tableWidget_outcome->raise();
        label_4->raise();
        label_xinming->raise();
        label_name->raise();
        label_6->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        pushButton_quit->raise();
        pushButton_correct->raise();
        frame_time->raise();
        QWidget::setTabOrder(tableWidget_search, lineEdit);
        QWidget::setTabOrder(lineEdit, tableWidget_outcome);

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QCoreApplication::translate("Form3", "Form", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Form3", "\350\276\223\345\205\245\350\246\201\346\220\234\347\264\242\347\232\204\344\272\213\345\212\241\344\277\241\346\201\257", nullptr));
        label->setText(QString());
        groupBox->setTitle(QString());
        label_foundation_2->setText(QCoreApplication::translate("Form3", "\351\227\271\351\222\237", nullptr));
        pushButton->setText(QString());
        deleteButton->setText(QString());
        label_log->setText(QCoreApplication::translate("Form3", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_foundation_3->setText(QCoreApplication::translate("Form3", "\346\266\210\346\201\257\351\200\232\347\237\245", nullptr));
        label_one_day_event->setText(QString());
        label_title->setText(QCoreApplication::translate("Form3", "\346\230\216\346\227\245\344\272\213\345\212\241", nullptr));
        label_5->setText(QString());
        label_image->setText(QCoreApplication::translate("Form3", "\345\233\276\347\211\207", nullptr));
        label_foundation->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget_outcome->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Form3", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_outcome->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Form3", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_outcome->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Form3", "\345\221\250\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_outcome->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Form3", "\345\234\260\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_outcome->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Form3", "\345\244\207\346\263\250", nullptr));
        label_name->setText(QString());
        label_college->setText(QCoreApplication::translate("Form3", "\350\256\241\347\256\227\346\234\272\345\255\246\351\231\242", nullptr));
        label_7->setText(QCoreApplication::translate("Form3", "\345\255\246\351\231\242:", nullptr));
        label_8->setText(QCoreApplication::translate("Form3", "\344\270\223\344\270\232:", nullptr));
        label_major->setText(QCoreApplication::translate("Form3", "\350\256\241\347\256\227\346\234\272\347\247\221\345\255\246\344\270\216\346\212\200\346\234\257", nullptr));
        label_ID->setText(QString());
        label_xuehao->setText(QCoreApplication::translate("Form3", "\345\255\246\345\217\267:", nullptr));
        label_4->setText(QString());
        label_xinming->setText(QCoreApplication::translate("Form3", "\345\247\223\345\220\215:", nullptr));
        label_6->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        pushButton_quit->setText(QCoreApplication::translate("Form3", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        pushButton_correct->setText(QCoreApplication::translate("Form3", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        bt_day->setText(QString());
        bt_hour->setText(QString());
        cb_week->setItemText(0, QCoreApplication::translate("Form3", "\347\254\254\344\270\200\345\221\250", nullptr));
        cb_week->setItemText(1, QCoreApplication::translate("Form3", "\347\254\254\344\272\214\345\221\250", nullptr));
        cb_week->setItemText(2, QCoreApplication::translate("Form3", "\347\254\254\344\270\211\345\221\250", nullptr));
        cb_week->setItemText(3, QCoreApplication::translate("Form3", "\347\254\254\345\233\233\345\221\250", nullptr));
        cb_week->setItemText(4, QCoreApplication::translate("Form3", "\347\254\254\344\272\224\345\221\250", nullptr));
        cb_week->setItemText(5, QCoreApplication::translate("Form3", "\347\254\254\345\205\255\345\221\250", nullptr));
        cb_week->setItemText(6, QCoreApplication::translate("Form3", "\347\254\254\344\270\203\345\221\250", nullptr));
        cb_week->setItemText(7, QCoreApplication::translate("Form3", "\347\254\254\345\205\253\345\221\250", nullptr));
        cb_week->setItemText(8, QCoreApplication::translate("Form3", "\347\254\254\344\271\235\345\221\250", nullptr));
        cb_week->setItemText(9, QCoreApplication::translate("Form3", "\347\254\254\345\215\201\345\221\250", nullptr));
        cb_week->setItemText(10, QCoreApplication::translate("Form3", "\347\254\254\345\215\201\344\270\200\345\221\250", nullptr));
        cb_week->setItemText(11, QCoreApplication::translate("Form3", "\347\254\254\345\215\201\344\272\214\345\221\250", nullptr));
        cb_week->setItemText(12, QCoreApplication::translate("Form3", "\347\254\254\345\215\201\344\270\211\345\221\250", nullptr));
        cb_week->setItemText(13, QCoreApplication::translate("Form3", "\347\254\254\345\215\201\345\233\233\345\221\250", nullptr));
        cb_week->setItemText(14, QCoreApplication::translate("Form3", "\347\254\254\345\215\201\344\272\224\345\221\250", nullptr));
        cb_week->setItemText(15, QCoreApplication::translate("Form3", "\347\254\254\345\215\201\345\205\255\345\221\250", nullptr));

        cb_week->setPlaceholderText(QString());
        label_time->setText(QString());
        bt_pause->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM3_H

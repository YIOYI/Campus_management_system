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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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
    QLabel *label_2;
    QLabel *label_foundation_2;
    QTableView *AlarmTable;
    QPushButton *pushButton;
    QPushButton *deleteButton;
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
        groupBox->setGeometry(QRect(20, 430, 1581, 471));
        groupBox->setStyleSheet(QString::fromUtf8("border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"background-color: rgba(66, 66, 66, 100);\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 40, 441, 301));
        QFont font2;
        font2.setPointSize(20);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"border-radius: 20px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/"));
        label_2->setAlignment(Qt::AlignCenter);
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
        deleteButton->setGeometry(QRect(1310, 350, 41, 51));
        deleteButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/picture/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);
        deleteButton->setIconSize(QSize(56, 56));
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
        if (tableWidget_outcome->columnCount() < 3)
            tableWidget_outcome->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_outcome->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_outcome->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_outcome->setHorizontalHeaderItem(2, __qtablewidgetitem2);
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
        label_2->setText(QCoreApplication::translate("Form3", "\346\266\210\346\201\257\351\200\232\347\237\245", nullptr));
        label_foundation_2->setText(QCoreApplication::translate("Form3", "\351\227\271\351\222\237", nullptr));
        pushButton->setText(QString());
        deleteButton->setText(QString());
        label_5->setText(QString());
        label_image->setText(QCoreApplication::translate("Form3", "\345\233\276\347\211\207", nullptr));
        label_foundation->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget_outcome->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Form3", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_outcome->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Form3", "\345\221\250\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_outcome->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Form3", "\345\234\260\347\202\271", nullptr));
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
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM3_H

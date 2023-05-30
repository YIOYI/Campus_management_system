/********************************************************************************
** Form generated from reading UI file 'form2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM2_H
#define UI_FORM2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form2
{
public:
    QScrollArea *sa_map;
    QWidget *scrollAreaWidgetContents;
    QLineEdit *search_tar;
    QLineEdit *search_src;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *frame;
    QFrame *frame_back;
    QPushButton *bt_guide;
    QPushButton *bt_clear;
    QLabel *label;
    QFrame *frame_2;
    QFrame *frame_time;
    QPushButton *bt_day;
    QPushButton *bt_hour;
    QComboBox *cb_week;
    QLabel *label_time;
    QPushButton *bt_pause;
    QLineEdit *plan_src;
    QFrame *frame_3;
    QLabel *label_event;
    QLabel *label_guide_text;
    QLabel *label_guide_title;
    QLabel *label_event_title;
    QLabel *label_event_text;
    QComboBox *plan_day;
    QComboBox *plan_hour;
    QComboBox *plan_week;

    void setupUi(QWidget *Form2)
    {
        if (Form2->objectName().isEmpty())
            Form2->setObjectName("Form2");
        Form2->resize(1600, 900);
        Form2->setMinimumSize(QSize(1600, 900));
        Form2->setMaximumSize(QSize(1600, 900));
        Form2->setStyleSheet(QString::fromUtf8(""));
        sa_map = new QScrollArea(Form2);
        sa_map->setObjectName("sa_map");
        sa_map->setGeometry(QRect(30, 210, 1191, 661));
        sa_map->setMinimumSize(QSize(0, 0));
        sa_map->setMaximumSize(QSize(10000, 10000));
        sa_map->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 245, 250);"));
        sa_map->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1189, 659));
        sa_map->setWidget(scrollAreaWidgetContents);
        search_tar = new QLineEdit(Form2);
        search_tar->setObjectName("search_tar");
        search_tar->setGeometry(QRect(460, 40, 191, 31));
        search_tar->setStyleSheet(QString::fromUtf8("border: 1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"border-radius: 10px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"font: 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(255, 255, 255);"));
        search_tar->setClearButtonEnabled(true);
        search_src = new QLineEdit(Form2);
        search_src->setObjectName("search_src");
        search_src->setGeometry(QRect(180, 40, 191, 31));
        search_src->setStyleSheet(QString::fromUtf8("border: 1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"border-radius: 10px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"font: 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(255, 255, 255);"));
        search_src->setClearButtonEnabled(true);
        label_2 = new QLabel(Form2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 40, 41, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_3 = new QLabel(Form2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 90, 121, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        frame = new QFrame(Form2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(390, 30, 61, 51));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/arrow.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_back = new QFrame(Form2);
        frame_back->setObjectName("frame_back");
        frame_back->setGeometry(QRect(-1, -1, 1601, 901));
        frame_back->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 238, 77);"));
        frame_back->setFrameShape(QFrame::StyledPanel);
        frame_back->setFrameShadow(QFrame::Raised);
        bt_guide = new QPushButton(frame_back);
        bt_guide->setObjectName("bt_guide");
        bt_guide->setGeometry(QRect(40, 160, 41, 41));
        bt_guide->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/guide.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"font: 16pt \"Microsoft YaHei UI\";"));
        bt_clear = new QPushButton(frame_back);
        bt_clear->setObjectName("bt_clear");
        bt_clear->setGeometry(QRect(120, 160, 41, 41));
        bt_clear->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/clear.png);\n"
"font: 16pt \"Microsoft YaHei UI\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        label = new QLabel(frame_back);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 160, 81, 20));
        frame_2 = new QFrame(frame_back);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(750, 20, 431, 251));
        frame_2->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/happy.jpg);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_time = new QFrame(frame_back);
        frame_time->setObjectName("frame_time");
        frame_time->setGeometry(QRect(1190, 10, 391, 171));
        frame_time->setFrameShape(QFrame::StyledPanel);
        frame_time->setFrameShadow(QFrame::Raised);
        bt_day = new QPushButton(frame_time);
        bt_day->setObjectName("bt_day");
        bt_day->setGeometry(QRect(260, 100, 31, 31));
        bt_day->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/week.png);\n"
"background-color: rgba(229, 229, 229, 0);"));
        bt_hour = new QPushButton(frame_time);
        bt_hour->setObjectName("bt_hour");
        bt_hour->setGeometry(QRect(200, 100, 31, 31));
        bt_hour->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/hour.png);\n"
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
        cb_week->setGeometry(QRect(90, 40, 91, 31));
        cb_week->setStyleSheet(QString::fromUtf8("border: 0px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"font: 700 10pt \"Microsoft YaHei UI\";\n"
"border-radius: 10px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"background-color: rgb(243, 235, 137);\n"
""));
        cb_week->setFrame(false);
        label_time = new QLabel(frame_time);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(60, 30, 321, 111));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        label_time->setFont(font);
        label_time->setStyleSheet(QString::fromUtf8("border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"font: 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgba(229, 229, 229, 100);\n"
"border-radius: 20px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/"));
        label_time->setAlignment(Qt::AlignCenter);
        bt_pause = new QPushButton(frame_time);
        bt_pause->setObjectName("bt_pause");
        bt_pause->setGeometry(QRect(130, 100, 31, 31));
        bt_pause->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/continue.png);\n"
"background-color: rgba(229, 229, 229, 0);"));
        label_time->raise();
        bt_day->raise();
        bt_hour->raise();
        cb_week->raise();
        bt_pause->raise();
        plan_src = new QLineEdit(frame_back);
        plan_src->setObjectName("plan_src");
        plan_src->setGeometry(QRect(180, 90, 191, 31));
        plan_src->setStyleSheet(QString::fromUtf8("border: 1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"border-radius: 10px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"font: 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(255, 255, 255);"));
        plan_src->setClearButtonEnabled(true);
        frame_3 = new QFrame(frame_back);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(1240, 200, 341, 681));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_event = new QLabel(frame_3);
        label_event->setObjectName("label_event");
        label_event->setGeometry(QRect(10, 10, 321, 661));
        QFont font1;
        font1.setPointSize(18);
        label_event->setFont(font1);
        label_event->setStyleSheet(QString::fromUtf8("border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"background-color: rgba(229, 229, 229, 100);\n"
"border-radius: 20px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/"));
        label_event->setAlignment(Qt::AlignCenter);
        label_guide_text = new QLabel(frame_3);
        label_guide_text->setObjectName("label_guide_text");
        label_guide_text->setGeometry(QRect(30, 320, 281, 331));
        label_guide_text->setStyleSheet(QString::fromUtf8("border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"background-color: rgba(255, 255, 255, 255);\n"
"border-radius: 5px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/"));
        label_guide_title = new QLabel(frame_3);
        label_guide_title->setObjectName("label_guide_title");
        label_guide_title->setGeometry(QRect(30, 270, 161, 41));
        label_guide_title->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Microsoft YaHei UI\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_event_title = new QLabel(frame_3);
        label_event_title->setObjectName("label_event_title");
        label_event_title->setGeometry(QRect(30, 30, 161, 41));
        label_event_title->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Microsoft YaHei UI\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_event_text = new QLabel(frame_3);
        label_event_text->setObjectName("label_event_text");
        label_event_text->setGeometry(QRect(30, 90, 281, 161));
        label_event_text->setStyleSheet(QString::fromUtf8("border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"background-color: rgba(255, 255, 255, 255);\n"
"border-radius: 5px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/"));
        plan_day = new QComboBox(frame_back);
        plan_day->addItem(QString());
        plan_day->addItem(QString());
        plan_day->addItem(QString());
        plan_day->addItem(QString());
        plan_day->addItem(QString());
        plan_day->addItem(QString());
        plan_day->addItem(QString());
        plan_day->setObjectName("plan_day");
        plan_day->setGeometry(QRect(500, 90, 81, 31));
        plan_day->setStyleSheet(QString::fromUtf8("border: 1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"border-radius: 10px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"font: 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(255, 255, 255);"));
        plan_hour = new QComboBox(frame_back);
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->addItem(QString());
        plan_hour->setObjectName("plan_hour");
        plan_hour->setGeometry(QRect(600, 90, 151, 31));
        plan_hour->setStyleSheet(QString::fromUtf8("border: 1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"border-radius: 10px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"font: 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(255, 255, 255);"));
        plan_week = new QComboBox(frame_back);
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->addItem(QString());
        plan_week->setObjectName("plan_week");
        plan_week->setGeometry(QRect(390, 90, 91, 31));
        plan_week->setStyleSheet(QString::fromUtf8("border: 1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"border-radius: 10px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/\n"
"font: 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(255, 255, 255);\n"
""));
        plan_week->setFrame(false);
        frame_back->raise();
        search_tar->raise();
        search_src->raise();
        label_2->raise();
        label_3->raise();
        frame->raise();
        sa_map->raise();

        retranslateUi(Form2);

        QMetaObject::connectSlotsByName(Form2);
    } // setupUi

    void retranslateUi(QWidget *Form2)
    {
        Form2->setWindowTitle(QCoreApplication::translate("Form2", "Form", nullptr));
        search_tar->setText(QString());
        search_tar->setPlaceholderText(QCoreApplication::translate("Form2", "\350\257\267\350\276\223\345\205\245\347\233\256\347\232\204\345\234\260\347\202\271...", nullptr));
        search_src->setPlaceholderText(QCoreApplication::translate("Form2", "\350\257\267\350\276\223\345\205\245\345\207\272\345\217\221\345\234\260\347\202\271...", nullptr));
        label_2->setText(QCoreApplication::translate("Form2", "<html><head/><body><p><span style=\" font-weight:700;\">\345\257\274\350\210\252</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Form2", "<html><head/><body><p><span style=\" font-weight:700;\">\345\244\232\344\272\213\345\212\241\350\247\204\345\210\222</span></p></body></html>", nullptr));
        bt_guide->setText(QString());
        bt_clear->setText(QString());
        label->setText(QCoreApplication::translate("Form2", "TextLabel", nullptr));
        bt_day->setText(QString());
        bt_hour->setText(QString());
        cb_week->setItemText(0, QCoreApplication::translate("Form2", "\347\254\254\344\270\200\345\221\250", nullptr));
        cb_week->setItemText(1, QCoreApplication::translate("Form2", "\347\254\254\344\272\214\345\221\250", nullptr));
        cb_week->setItemText(2, QCoreApplication::translate("Form2", "\347\254\254\344\270\211\345\221\250", nullptr));
        cb_week->setItemText(3, QCoreApplication::translate("Form2", "\347\254\254\345\233\233\345\221\250", nullptr));
        cb_week->setItemText(4, QCoreApplication::translate("Form2", "\347\254\254\344\272\224\345\221\250", nullptr));
        cb_week->setItemText(5, QCoreApplication::translate("Form2", "\347\254\254\345\205\255\345\221\250", nullptr));
        cb_week->setItemText(6, QCoreApplication::translate("Form2", "\347\254\254\344\270\203\345\221\250", nullptr));
        cb_week->setItemText(7, QCoreApplication::translate("Form2", "\347\254\254\345\205\253\345\221\250", nullptr));
        cb_week->setItemText(8, QCoreApplication::translate("Form2", "\347\254\254\344\271\235\345\221\250", nullptr));
        cb_week->setItemText(9, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\345\221\250", nullptr));
        cb_week->setItemText(10, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\344\270\200\345\221\250", nullptr));
        cb_week->setItemText(11, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\344\272\214\345\221\250", nullptr));
        cb_week->setItemText(12, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\344\270\211\345\221\250", nullptr));
        cb_week->setItemText(13, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\345\233\233\345\221\250", nullptr));
        cb_week->setItemText(14, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\344\272\224\345\221\250", nullptr));
        cb_week->setItemText(15, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\345\205\255\345\221\250", nullptr));

        cb_week->setPlaceholderText(QString());
        label_time->setText(QString());
        bt_pause->setText(QString());
        plan_src->setPlaceholderText(QCoreApplication::translate("Form2", "\350\257\267\350\276\223\345\205\245\345\207\272\345\217\221\345\234\260\347\202\271...", nullptr));
        label_event->setText(QString());
        label_guide_text->setText(QString());
        label_guide_title->setText(QCoreApplication::translate("Form2", "\345\257\274\350\210\252\344\277\241\346\201\257", nullptr));
        label_event_title->setText(QCoreApplication::translate("Form2", "\346\227\266\346\256\265\344\272\213\344\273\266\344\277\241\346\201\257", nullptr));
        label_event_text->setText(QString());
        plan_day->setItemText(0, QCoreApplication::translate("Form2", "\345\221\250\344\270\200", nullptr));
        plan_day->setItemText(1, QCoreApplication::translate("Form2", "\345\221\250\344\272\214", nullptr));
        plan_day->setItemText(2, QCoreApplication::translate("Form2", "\345\221\250\344\270\211", nullptr));
        plan_day->setItemText(3, QCoreApplication::translate("Form2", "\345\221\250\345\233\233", nullptr));
        plan_day->setItemText(4, QCoreApplication::translate("Form2", "\345\221\250\344\272\224", nullptr));
        plan_day->setItemText(5, QCoreApplication::translate("Form2", "\345\221\250\345\205\255", nullptr));
        plan_day->setItemText(6, QCoreApplication::translate("Form2", "\345\221\250\346\227\245", nullptr));

        plan_day->setPlaceholderText(QString());
        plan_hour->setItemText(0, QCoreApplication::translate("Form2", "\350\257\267\351\200\211\346\213\251\346\227\266\351\227\264", nullptr));
        plan_hour->setItemText(1, QCoreApplication::translate("Form2", "6\347\202\271--7\347\202\271", nullptr));
        plan_hour->setItemText(2, QCoreApplication::translate("Form2", "7\347\202\271--8\347\202\271", nullptr));
        plan_hour->setItemText(3, QCoreApplication::translate("Form2", "8\347\202\271--9\347\202\271", nullptr));
        plan_hour->setItemText(4, QCoreApplication::translate("Form2", "9\347\202\271--10\347\202\271", nullptr));
        plan_hour->setItemText(5, QCoreApplication::translate("Form2", "10\347\202\271--11\347\202\271", nullptr));
        plan_hour->setItemText(6, QCoreApplication::translate("Form2", "11\347\202\271--12\347\202\271", nullptr));
        plan_hour->setItemText(7, QCoreApplication::translate("Form2", "12\347\202\271--13\347\202\271", nullptr));
        plan_hour->setItemText(8, QCoreApplication::translate("Form2", "13\347\202\271--14\347\202\271", nullptr));
        plan_hour->setItemText(9, QCoreApplication::translate("Form2", "14\347\202\271--15\347\202\271", nullptr));
        plan_hour->setItemText(10, QCoreApplication::translate("Form2", "15\347\202\271--16\347\202\271", nullptr));
        plan_hour->setItemText(11, QCoreApplication::translate("Form2", "16\347\202\271--17\347\202\271", nullptr));
        plan_hour->setItemText(12, QCoreApplication::translate("Form2", "17\347\202\271--18\347\202\271", nullptr));
        plan_hour->setItemText(13, QCoreApplication::translate("Form2", "18\347\202\271--19\347\202\271", nullptr));
        plan_hour->setItemText(14, QCoreApplication::translate("Form2", "19\347\202\271--20\347\202\271", nullptr));
        plan_hour->setItemText(15, QCoreApplication::translate("Form2", "20\347\202\271--21\347\202\271", nullptr));
        plan_hour->setItemText(16, QCoreApplication::translate("Form2", "21\347\202\271--22\347\202\271", nullptr));

        plan_hour->setPlaceholderText(QString());
        plan_week->setItemText(0, QCoreApplication::translate("Form2", "\347\254\254\344\270\200\345\221\250", nullptr));
        plan_week->setItemText(1, QCoreApplication::translate("Form2", "\347\254\254\344\272\214\345\221\250", nullptr));
        plan_week->setItemText(2, QCoreApplication::translate("Form2", "\347\254\254\344\270\211\345\221\250", nullptr));
        plan_week->setItemText(3, QCoreApplication::translate("Form2", "\347\254\254\345\233\233\345\221\250", nullptr));
        plan_week->setItemText(4, QCoreApplication::translate("Form2", "\347\254\254\344\272\224\345\221\250", nullptr));
        plan_week->setItemText(5, QCoreApplication::translate("Form2", "\347\254\254\345\205\255\345\221\250", nullptr));
        plan_week->setItemText(6, QCoreApplication::translate("Form2", "\347\254\254\344\270\203\345\221\250", nullptr));
        plan_week->setItemText(7, QCoreApplication::translate("Form2", "\347\254\254\345\205\253\345\221\250", nullptr));
        plan_week->setItemText(8, QCoreApplication::translate("Form2", "\347\254\254\344\271\235\345\221\250", nullptr));
        plan_week->setItemText(9, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\345\221\250", nullptr));
        plan_week->setItemText(10, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\344\270\200\345\221\250", nullptr));
        plan_week->setItemText(11, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\344\272\214\345\221\250", nullptr));
        plan_week->setItemText(12, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\344\270\211\345\221\250", nullptr));
        plan_week->setItemText(13, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\345\233\233\345\221\250", nullptr));
        plan_week->setItemText(14, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\344\272\224\345\221\250", nullptr));
        plan_week->setItemText(15, QCoreApplication::translate("Form2", "\347\254\254\345\215\201\345\205\255\345\221\250", nullptr));

        plan_week->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form2: public Ui_Form2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM2_H

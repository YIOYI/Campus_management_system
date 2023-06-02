/********************************************************************************
** Form generated from reading UI file 'form1.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM1_H
#define UI_FORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_events
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QComboBox *select_week;
    QTableWidget *tableWidget;
    QFrame *frame_2;
    QWidget *layoutWidget_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_26;
    QCheckBox *checkBox_week1;
    QCheckBox *checkBox_week2;
    QCheckBox *checkBox_week3;
    QCheckBox *checkBox_week4;
    QHBoxLayout *horizontalLayout_27;
    QCheckBox *checkBox_week5;
    QCheckBox *checkBox_week6;
    QCheckBox *checkBox_week7;
    QCheckBox *checkBox_week8;
    QHBoxLayout *horizontalLayout_28;
    QCheckBox *checkBox_week9;
    QCheckBox *checkBox_week10;
    QCheckBox *checkBox_week11;
    QCheckBox *checkBox_week12;
    QHBoxLayout *horizontalLayout_29;
    QCheckBox *checkBox_week13;
    QCheckBox *checkBox_week14;
    QCheckBox *checkBox_week15;
    QCheckBox *checkBox_week16;
    QLabel *label_18;
    QLabel *label_17;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_21;
    QRadioButton *radioButton_event3;
    QRadioButton *radioButton_event4;
    QRadioButton *radioButton_event5;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_24;
    QHBoxLayout *horizontalLayout_31;
    QRadioButton *radioButton_add;
    QRadioButton *radioButton_revise;
    QRadioButton *radioButton_delete;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_21;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit_address;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_22;
    QComboBox *comboBox_day;
    QComboBox *comboBox_start_time;
    QLabel *label_23;
    QComboBox *comboBox_end_time;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_getevent;
    QPushButton *pushButton_clean;
    QLabel *label_5;
    QFrame *frame_3;
    QLabel *label_3;
    QLabel *label_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *event_detial;
    QPushButton *pushButton_refresh;
    QWidget *widget;
    QLabel *label_ID;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QComboBox *comboBox_ID;
    QPushButton *pushButton_getID;
    QLabel *label_2;
    QFrame *frame_time;
    QPushButton *bt_day;
    QPushButton *bt_hour;
    QComboBox *cb_week;
    QLabel *label_time;
    QPushButton *bt_pause;

    void setupUi(QWidget *Form_events)
    {
        if (Form_events->objectName().isEmpty())
            Form_events->setObjectName("Form_events");
        Form_events->resize(1600, 900);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form_events->sizePolicy().hasHeightForWidth());
        Form_events->setSizePolicy(sizePolicy);
        Form_events->setMinimumSize(QSize(1600, 900));
        Form_events->setMaximumSize(QSize(1600, 900));
        QFont font;
        font.setPointSize(8);
        Form_events->setFont(font);
        Form_events->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Form_events);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(Form_events);
        frame->setObjectName("frame");
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 31));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        select_week = new QComboBox(frame);
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->addItem(QString());
        select_week->setObjectName("select_week");
        select_week->setGeometry(QRect(20, 80, 131, 60));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(15);
        select_week->setFont(font1);
        tableWidget = new QTableWidget(frame);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        __qtablewidgetitem->setBackground(QColor(0, 0, 0, 0));
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font2);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font2);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font2);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget->rowCount() < 16)
            tableWidget->setRowCount(16);
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font3);
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font3);
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font3);
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font3);
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font3);
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font3);
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font3);
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font3);
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem14);
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setItalic(false);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font4);
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font3);
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font3);
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font3);
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font3);
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font3);
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font3);
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font3);
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem22);
        QFont font5;
        font5.setBold(true);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem23->setFont(font5);
        tableWidget->setItem(0, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 2, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 3, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 4, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 5, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 6, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 3, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 4, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 5, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 6, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 1, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 2, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 3, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 4, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 5, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 6, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 2, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 3, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        __qtablewidgetitem48->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 4, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        __qtablewidgetitem49->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 5, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        __qtablewidgetitem50->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 6, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        __qtablewidgetitem51->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(4, 0, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        __qtablewidgetitem52->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(4, 1, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        __qtablewidgetitem53->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(4, 2, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        __qtablewidgetitem54->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(4, 3, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        __qtablewidgetitem55->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(4, 4, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        __qtablewidgetitem56->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(4, 5, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        __qtablewidgetitem57->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(4, 6, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        __qtablewidgetitem58->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(5, 0, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        __qtablewidgetitem59->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(5, 1, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        __qtablewidgetitem60->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(5, 2, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        __qtablewidgetitem61->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(5, 3, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        __qtablewidgetitem62->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(5, 4, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        __qtablewidgetitem63->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(5, 5, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        __qtablewidgetitem64->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(5, 6, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        __qtablewidgetitem65->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(6, 0, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        __qtablewidgetitem66->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(6, 1, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        __qtablewidgetitem67->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(6, 2, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        __qtablewidgetitem68->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(6, 3, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        __qtablewidgetitem69->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(6, 4, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        __qtablewidgetitem70->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(6, 5, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        __qtablewidgetitem71->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(6, 6, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        __qtablewidgetitem72->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(7, 0, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        __qtablewidgetitem73->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(7, 1, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        __qtablewidgetitem74->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(7, 2, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        __qtablewidgetitem75->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(7, 3, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        __qtablewidgetitem76->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(7, 4, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        __qtablewidgetitem77->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(7, 5, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        __qtablewidgetitem78->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(7, 6, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        __qtablewidgetitem79->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(8, 0, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        __qtablewidgetitem80->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(8, 1, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        __qtablewidgetitem81->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(8, 2, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        __qtablewidgetitem82->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(8, 3, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        __qtablewidgetitem83->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(8, 4, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        __qtablewidgetitem84->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(8, 5, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        __qtablewidgetitem85->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(8, 6, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        __qtablewidgetitem86->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(9, 0, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        __qtablewidgetitem87->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(9, 1, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        __qtablewidgetitem88->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(9, 2, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        __qtablewidgetitem89->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(9, 3, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        __qtablewidgetitem90->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(9, 4, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        __qtablewidgetitem91->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(9, 5, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        __qtablewidgetitem92->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(9, 6, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        __qtablewidgetitem93->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(10, 0, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        __qtablewidgetitem94->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(10, 1, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        __qtablewidgetitem95->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(10, 2, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        __qtablewidgetitem96->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(10, 3, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        __qtablewidgetitem97->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(10, 4, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        __qtablewidgetitem98->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(10, 5, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        __qtablewidgetitem99->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(10, 6, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        __qtablewidgetitem100->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(11, 0, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        __qtablewidgetitem101->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(11, 1, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        __qtablewidgetitem102->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(11, 2, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        __qtablewidgetitem103->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(11, 3, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        __qtablewidgetitem104->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(11, 4, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        __qtablewidgetitem105->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(11, 5, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        __qtablewidgetitem106->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(11, 6, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        __qtablewidgetitem107->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(12, 0, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        __qtablewidgetitem108->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(12, 1, __qtablewidgetitem108);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        __qtablewidgetitem109->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(12, 2, __qtablewidgetitem109);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        __qtablewidgetitem110->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(12, 3, __qtablewidgetitem110);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        __qtablewidgetitem111->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(12, 4, __qtablewidgetitem111);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        __qtablewidgetitem112->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(12, 5, __qtablewidgetitem112);
        QTableWidgetItem *__qtablewidgetitem113 = new QTableWidgetItem();
        __qtablewidgetitem113->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(12, 6, __qtablewidgetitem113);
        QTableWidgetItem *__qtablewidgetitem114 = new QTableWidgetItem();
        __qtablewidgetitem114->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(13, 0, __qtablewidgetitem114);
        QTableWidgetItem *__qtablewidgetitem115 = new QTableWidgetItem();
        __qtablewidgetitem115->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(13, 1, __qtablewidgetitem115);
        QTableWidgetItem *__qtablewidgetitem116 = new QTableWidgetItem();
        __qtablewidgetitem116->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(13, 2, __qtablewidgetitem116);
        QTableWidgetItem *__qtablewidgetitem117 = new QTableWidgetItem();
        __qtablewidgetitem117->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(13, 3, __qtablewidgetitem117);
        QTableWidgetItem *__qtablewidgetitem118 = new QTableWidgetItem();
        __qtablewidgetitem118->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(13, 4, __qtablewidgetitem118);
        QTableWidgetItem *__qtablewidgetitem119 = new QTableWidgetItem();
        __qtablewidgetitem119->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(13, 5, __qtablewidgetitem119);
        QTableWidgetItem *__qtablewidgetitem120 = new QTableWidgetItem();
        __qtablewidgetitem120->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(13, 6, __qtablewidgetitem120);
        QTableWidgetItem *__qtablewidgetitem121 = new QTableWidgetItem();
        __qtablewidgetitem121->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(14, 0, __qtablewidgetitem121);
        QTableWidgetItem *__qtablewidgetitem122 = new QTableWidgetItem();
        __qtablewidgetitem122->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(14, 1, __qtablewidgetitem122);
        QTableWidgetItem *__qtablewidgetitem123 = new QTableWidgetItem();
        __qtablewidgetitem123->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(14, 2, __qtablewidgetitem123);
        QTableWidgetItem *__qtablewidgetitem124 = new QTableWidgetItem();
        __qtablewidgetitem124->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(14, 3, __qtablewidgetitem124);
        QTableWidgetItem *__qtablewidgetitem125 = new QTableWidgetItem();
        __qtablewidgetitem125->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(14, 4, __qtablewidgetitem125);
        QTableWidgetItem *__qtablewidgetitem126 = new QTableWidgetItem();
        __qtablewidgetitem126->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(14, 5, __qtablewidgetitem126);
        QTableWidgetItem *__qtablewidgetitem127 = new QTableWidgetItem();
        __qtablewidgetitem127->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(14, 6, __qtablewidgetitem127);
        QTableWidgetItem *__qtablewidgetitem128 = new QTableWidgetItem();
        __qtablewidgetitem128->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(15, 0, __qtablewidgetitem128);
        QTableWidgetItem *__qtablewidgetitem129 = new QTableWidgetItem();
        __qtablewidgetitem129->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(15, 1, __qtablewidgetitem129);
        QTableWidgetItem *__qtablewidgetitem130 = new QTableWidgetItem();
        __qtablewidgetitem130->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(15, 2, __qtablewidgetitem130);
        QTableWidgetItem *__qtablewidgetitem131 = new QTableWidgetItem();
        __qtablewidgetitem131->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(15, 3, __qtablewidgetitem131);
        QTableWidgetItem *__qtablewidgetitem132 = new QTableWidgetItem();
        __qtablewidgetitem132->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(15, 4, __qtablewidgetitem132);
        QTableWidgetItem *__qtablewidgetitem133 = new QTableWidgetItem();
        __qtablewidgetitem133->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(15, 5, __qtablewidgetitem133);
        QTableWidgetItem *__qtablewidgetitem134 = new QTableWidgetItem();
        __qtablewidgetitem134->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(15, 6, __qtablewidgetitem134);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 80, 1041, 731));
        tableWidget->setMinimumSize(QSize(0, 0));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font6.setPointSize(10);
        font6.setBold(true);
        tableWidget->setFont(font6);
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(127);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(100);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(1070, 370, 481, 361));
        frame_2->setMinimumSize(QSize(0, 28));
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        layoutWidget_7 = new QWidget(frame_2);
        layoutWidget_7->setObjectName("layoutWidget_7");
        layoutWidget_7->setGeometry(QRect(100, 220, 365, 127));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_7);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        checkBox_week1 = new QCheckBox(layoutWidget_7);
        checkBox_week1->setObjectName("checkBox_week1");
        checkBox_week1->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_26->addWidget(checkBox_week1);

        checkBox_week2 = new QCheckBox(layoutWidget_7);
        checkBox_week2->setObjectName("checkBox_week2");
        checkBox_week2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_26->addWidget(checkBox_week2);

        checkBox_week3 = new QCheckBox(layoutWidget_7);
        checkBox_week3->setObjectName("checkBox_week3");
        checkBox_week3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_26->addWidget(checkBox_week3);

        checkBox_week4 = new QCheckBox(layoutWidget_7);
        checkBox_week4->setObjectName("checkBox_week4");
        checkBox_week4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_26->addWidget(checkBox_week4);


        verticalLayout_6->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName("horizontalLayout_27");
        checkBox_week5 = new QCheckBox(layoutWidget_7);
        checkBox_week5->setObjectName("checkBox_week5");
        checkBox_week5->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_27->addWidget(checkBox_week5);

        checkBox_week6 = new QCheckBox(layoutWidget_7);
        checkBox_week6->setObjectName("checkBox_week6");
        checkBox_week6->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_27->addWidget(checkBox_week6);

        checkBox_week7 = new QCheckBox(layoutWidget_7);
        checkBox_week7->setObjectName("checkBox_week7");
        checkBox_week7->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_27->addWidget(checkBox_week7);

        checkBox_week8 = new QCheckBox(layoutWidget_7);
        checkBox_week8->setObjectName("checkBox_week8");
        checkBox_week8->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_27->addWidget(checkBox_week8);


        verticalLayout_6->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName("horizontalLayout_28");
        checkBox_week9 = new QCheckBox(layoutWidget_7);
        checkBox_week9->setObjectName("checkBox_week9");
        checkBox_week9->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_28->addWidget(checkBox_week9);

        checkBox_week10 = new QCheckBox(layoutWidget_7);
        checkBox_week10->setObjectName("checkBox_week10");
        checkBox_week10->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_28->addWidget(checkBox_week10);

        checkBox_week11 = new QCheckBox(layoutWidget_7);
        checkBox_week11->setObjectName("checkBox_week11");
        checkBox_week11->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_28->addWidget(checkBox_week11);

        checkBox_week12 = new QCheckBox(layoutWidget_7);
        checkBox_week12->setObjectName("checkBox_week12");
        checkBox_week12->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_28->addWidget(checkBox_week12);


        verticalLayout_6->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName("horizontalLayout_29");
        checkBox_week13 = new QCheckBox(layoutWidget_7);
        checkBox_week13->setObjectName("checkBox_week13");
        checkBox_week13->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_29->addWidget(checkBox_week13);

        checkBox_week14 = new QCheckBox(layoutWidget_7);
        checkBox_week14->setObjectName("checkBox_week14");
        checkBox_week14->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_29->addWidget(checkBox_week14);

        checkBox_week15 = new QCheckBox(layoutWidget_7);
        checkBox_week15->setObjectName("checkBox_week15");
        checkBox_week15->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_29->addWidget(checkBox_week15);

        checkBox_week16 = new QCheckBox(layoutWidget_7);
        checkBox_week16->setObjectName("checkBox_week16");
        checkBox_week16->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_29->addWidget(checkBox_week16);


        verticalLayout_6->addLayout(horizontalLayout_29);

        label_18 = new QLabel(frame_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 220, 85, 31));
        QFont font7;
        font7.setPointSize(10);
        label_18->setFont(font7);
        label_18->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        label_17 = new QLabel(frame_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 10, 100, 32));
        QFont font8;
        font8.setPointSize(15);
        font8.setBold(true);
        label_17->setFont(font8);
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        label_17->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(frame_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 40, 459, 172));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setMinimumSize(QSize(0, 31));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 0, 449, 32));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(layoutWidget1);
        label_19->setObjectName("label_19");
        label_19->setMinimumSize(QSize(106, 28));
        label_19->setMaximumSize(QSize(106, 16777215));
        label_19->setFont(font7);
        label_19->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_10->addWidget(label_19);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        radioButton_event3 = new QRadioButton(layoutWidget1);
        radioButton_event3->setObjectName("radioButton_event3");
        radioButton_event3->setMinimumSize(QSize(106, 28));
        radioButton_event3->setFont(font7);
        radioButton_event3->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_21->addWidget(radioButton_event3);

        radioButton_event4 = new QRadioButton(layoutWidget1);
        radioButton_event4->setObjectName("radioButton_event4");
        radioButton_event4->setMinimumSize(QSize(106, 28));
        radioButton_event4->setFont(font7);
        radioButton_event4->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_21->addWidget(radioButton_event4);

        radioButton_event5 = new QRadioButton(layoutWidget1);
        radioButton_event5->setObjectName("radioButton_event5");
        radioButton_event5->setMinimumSize(QSize(106, 28));
        radioButton_event5->setFont(font7);
        radioButton_event5->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_21->addWidget(radioButton_event5);


        horizontalLayout_10->addLayout(horizontalLayout_21);


        verticalLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(0, 31));
        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(0, 0, 449, 32));
        horizontalLayout_30 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_30->setObjectName("horizontalLayout_30");
        horizontalLayout_30->setContentsMargins(0, 0, 0, 0);
        label_24 = new QLabel(layoutWidget2);
        label_24->setObjectName("label_24");
        label_24->setMinimumSize(QSize(0, 28));
        label_24->setMaximumSize(QSize(106, 16777215));
        label_24->setFont(font7);
        label_24->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_30->addWidget(label_24);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName("horizontalLayout_31");
        radioButton_add = new QRadioButton(layoutWidget2);
        radioButton_add->setObjectName("radioButton_add");
        radioButton_add->setMinimumSize(QSize(106, 28));
        radioButton_add->setFont(font7);
        radioButton_add->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_31->addWidget(radioButton_add);

        radioButton_revise = new QRadioButton(layoutWidget2);
        radioButton_revise->setObjectName("radioButton_revise");
        radioButton_revise->setMinimumSize(QSize(106, 0));
        radioButton_revise->setFont(font7);
        radioButton_revise->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_31->addWidget(radioButton_revise);

        radioButton_delete = new QRadioButton(layoutWidget2);
        radioButton_delete->setObjectName("radioButton_delete");
        radioButton_delete->setMinimumSize(QSize(106, 28));
        radioButton_delete->setFont(font7);
        radioButton_delete->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_31->addWidget(radioButton_delete);


        horizontalLayout_30->addLayout(horizontalLayout_31);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        label_21 = new QLabel(layoutWidget);
        label_21->setObjectName("label_21");
        label_21->setFont(font7);
        label_21->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_24->addWidget(label_21);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName("lineEdit_name");
        QFont font9;
        font9.setPointSize(9);
        lineEdit_name->setFont(font9);
        lineEdit_name->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_24->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout_24);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(106, 24));
        label_6->setMaximumSize(QSize(106, 24));
        label_6->setFont(font7);

        horizontalLayout_2->addWidget(label_6);

        lineEdit_address = new QLineEdit(layoutWidget);
        lineEdit_address->setObjectName("lineEdit_address");
        lineEdit_address->setFont(font9);
        lineEdit_address->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_2->addWidget(lineEdit_address);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName("label_22");
        label_22->setMaximumSize(QSize(106, 16777215));
        label_22->setFont(font7);
        label_22->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_25->addWidget(label_22);

        comboBox_day = new QComboBox(layoutWidget);
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->setObjectName("comboBox_day");
        QFont font10;
        font10.setPointSize(9);
        font10.setBold(true);
        comboBox_day->setFont(font10);

        horizontalLayout_25->addWidget(comboBox_day);

        comboBox_start_time = new QComboBox(layoutWidget);
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->addItem(QString());
        comboBox_start_time->setObjectName("comboBox_start_time");
        comboBox_start_time->setFont(font10);
        comboBox_start_time->setLayoutDirection(Qt::LeftToRight);
        comboBox_start_time->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_25->addWidget(comboBox_start_time);

        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName("label_23");
        label_23->setMaximumSize(QSize(12, 16777215));
        label_23->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_25->addWidget(label_23);

        comboBox_end_time = new QComboBox(layoutWidget);
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->addItem(QString());
        comboBox_end_time->setObjectName("comboBox_end_time");
        comboBox_end_time->setFont(font10);
        comboBox_end_time->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_25->addWidget(comboBox_end_time);


        verticalLayout->addLayout(horizontalLayout_25);

        layoutWidget3 = new QWidget(frame_2);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(140, 10, 295, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_ok = new QPushButton(layoutWidget3);
        pushButton_ok->setObjectName("pushButton_ok");

        horizontalLayout->addWidget(pushButton_ok);

        pushButton_getevent = new QPushButton(layoutWidget3);
        pushButton_getevent->setObjectName("pushButton_getevent");

        horizontalLayout->addWidget(pushButton_getevent);

        pushButton_clean = new QPushButton(layoutWidget3);
        pushButton_clean->setObjectName("pushButton_clean");

        horizontalLayout->addWidget(pushButton_clean);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 240, 81, 131));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_5->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(1070, 120, 481, 231));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 101, 41));
        label_3->setFont(font8);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        label_4 = new QLabel(frame_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 481, 231));
        label_4->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid rgb(255, 255, 127)"));
        scrollArea = new QScrollArea(frame_3);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 50, 461, 171));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 459, 169));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName("gridLayout_2");
        event_detial = new QLabel(scrollAreaWidgetContents);
        event_detial->setObjectName("event_detial");
        QFont font11;
        font11.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font11.setPointSize(11);
        font11.setBold(true);
        event_detial->setFont(font11);
        event_detial->setStyleSheet(QString::fromUtf8(""));
        event_detial->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(event_detial, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        label_4->raise();
        label_3->raise();
        scrollArea->raise();
        pushButton_refresh = new QPushButton(frame);
        pushButton_refresh->setObjectName("pushButton_refresh");
        pushButton_refresh->setGeometry(QRect(960, 30, 101, 41));
        QFont font12;
        font12.setPointSize(14);
        pushButton_refresh->setFont(font12);
        pushButton_refresh->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(frame);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(1070, 740, 481, 131));
        label_ID = new QLabel(widget);
        label_ID->setObjectName("label_ID");
        label_ID->setGeometry(QRect(20, 50, 421, 71));
        label_ID->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid rgb(0,0, 0)"));
        label_ID->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        layoutWidget4 = new QWidget(widget);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(9, 0, 441, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget4);
        label_7->setObjectName("label_7");
        label_7->setFont(font7);

        horizontalLayout_3->addWidget(label_7);

        comboBox_ID = new QComboBox(layoutWidget4);
        comboBox_ID->addItem(QString());
        comboBox_ID->addItem(QString());
        comboBox_ID->addItem(QString());
        comboBox_ID->addItem(QString());
        comboBox_ID->addItem(QString());
        comboBox_ID->addItem(QString());
        comboBox_ID->addItem(QString());
        comboBox_ID->addItem(QString());
        comboBox_ID->addItem(QString());
        comboBox_ID->addItem(QString());
        comboBox_ID->setObjectName("comboBox_ID");
        comboBox_ID->setFont(font7);

        horizontalLayout_3->addWidget(comboBox_ID);

        pushButton_getID = new QPushButton(layoutWidget4);
        pushButton_getID->setObjectName("pushButton_getID");
        pushButton_getID->setFont(font7);

        horizontalLayout_3->addWidget(pushButton_getID);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1074, 363, 481, 511));
        label_2->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid rgb(255, 255, 127)"));
        frame_time = new QFrame(frame);
        frame_time->setObjectName("frame_time");
        frame_time->setGeometry(QRect(1180, 10, 381, 131));
        frame_time->setFrameShape(QFrame::StyledPanel);
        frame_time->setFrameShadow(QFrame::Raised);
        bt_day = new QPushButton(frame_time);
        bt_day->setObjectName("bt_day");
        bt_day->setGeometry(QRect(300, 60, 31, 31));
        bt_day->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/week.png);\n"
"color: rgba(255, 255, 255, 0);"));
        bt_hour = new QPushButton(frame_time);
        bt_hour->setObjectName("bt_hour");
        bt_hour->setGeometry(QRect(220, 60, 31, 31));
        bt_hour->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/hour.png);\n"
"color: rgba(255, 255, 255, 0);"));
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
        cb_week->setGeometry(QRect(110, 10, 91, 31));
        cb_week->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(179, 212, 213);\n"
""));
        cb_week->setFrame(false);
        label_time = new QLabel(frame_time);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(100, 0, 271, 101));
        QFont font13;
        font13.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font13.setPointSize(12);
        font13.setBold(true);
        font13.setItalic(false);
        label_time->setFont(font13);
        label_time->setStyleSheet(QString::fromUtf8("border:1px solid gray;/*\350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\347\262\227\347\273\206\357\274\214\344\273\245\345\217\212\351\242\234\350\211\262*/\n"
"font: 700 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgba(229, 229, 229, 100);\n"
"border-radius: 20px;/*\350\256\276\347\275\256\345\234\206\350\247\222\347\232\204\345\244\247\345\260\217*/"));
        label_time->setAlignment(Qt::AlignCenter);
        bt_pause = new QPushButton(frame_time);
        bt_pause->setObjectName("bt_pause");
        bt_pause->setGeometry(QRect(140, 60, 31, 31));
        bt_pause->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/pause.png);\n"
"color: rgba(255, 255, 255, 0);"));
        label_time->raise();
        bt_day->raise();
        bt_hour->raise();
        cb_week->raise();
        bt_pause->raise();
        label_2->raise();
        frame_2->raise();
        frame_3->raise();
        tableWidget->raise();
        select_week->raise();
        pushButton_refresh->raise();
        widget->raise();
        frame_time->raise();

        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(Form_events);

        QMetaObject::connectSlotsByName(Form_events);
    } // setupUi

    void retranslateUi(QWidget *Form_events)
    {
        Form_events->setWindowTitle(QCoreApplication::translate("Form_events", "Form", nullptr));
        select_week->setItemText(0, QCoreApplication::translate("Form_events", "   \347\254\2541\345\221\250", nullptr));
        select_week->setItemText(1, QCoreApplication::translate("Form_events", "   \347\254\2542\345\221\250", nullptr));
        select_week->setItemText(2, QCoreApplication::translate("Form_events", "   \347\254\2543\345\221\250", nullptr));
        select_week->setItemText(3, QCoreApplication::translate("Form_events", "   \347\254\2544\345\221\250", nullptr));
        select_week->setItemText(4, QCoreApplication::translate("Form_events", "   \347\254\2545\345\221\250", nullptr));
        select_week->setItemText(5, QCoreApplication::translate("Form_events", "   \347\254\2546\345\221\250", nullptr));
        select_week->setItemText(6, QCoreApplication::translate("Form_events", "   \347\254\2547\345\221\250", nullptr));
        select_week->setItemText(7, QCoreApplication::translate("Form_events", "   \347\254\2548\345\221\250", nullptr));
        select_week->setItemText(8, QCoreApplication::translate("Form_events", "   \347\254\2549\345\221\250", nullptr));
        select_week->setItemText(9, QCoreApplication::translate("Form_events", "   \347\254\25410\345\221\250", nullptr));
        select_week->setItemText(10, QCoreApplication::translate("Form_events", "   \347\254\25411\345\221\250", nullptr));
        select_week->setItemText(11, QCoreApplication::translate("Form_events", "   \347\254\25412\345\221\250", nullptr));
        select_week->setItemText(12, QCoreApplication::translate("Form_events", "   \347\254\25413\345\221\250", nullptr));
        select_week->setItemText(13, QCoreApplication::translate("Form_events", "   \347\254\25414\345\221\250", nullptr));
        select_week->setItemText(14, QCoreApplication::translate("Form_events", "   \347\254\25415\345\221\250", nullptr));
        select_week->setItemText(15, QCoreApplication::translate("Form_events", "   \347\254\25416\345\221\250", nullptr));

#if QT_CONFIG(tooltip)
        select_week->setToolTip(QCoreApplication::translate("Form_events", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        select_week->setWhatsThis(QCoreApplication::translate("Form_events", "<html><head/><body><p>qr</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Form_events", "\345\221\250\344\270\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Form_events", "\345\221\250\344\272\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Form_events", "\345\221\250\344\270\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Form_events", "\345\221\250\345\233\233", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Form_events", "\345\221\250\344\272\224", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Form_events", "\345\221\250\345\205\255", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Form_events", "\345\221\250\346\227\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Form_events", "        1 \345\260\217\350\212\202\n"
"  06:00~07:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Form_events", "        2 \345\260\217\350\212\202\n"
"  07:00~08:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Form_events", "        3 \345\260\217\350\212\202\n"
"  08:00~09:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Form_events", "        4 \345\260\217\350\212\202\n"
"  09:00~10:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Form_events", "        5 \345\260\217\350\212\202\n"
"  10:00~11:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Form_events", "        6 \345\260\217\350\212\202\n"
"  11:00~12:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Form_events", "       7 \345\260\217\350\212\202\n"
"  12:00~13:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Form_events", "        8 \345\260\217\350\212\202\n"
"  13:00~14:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Form_events", "        9 \345\260\217\350\212\202\n"
"  14:00~15:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Form_events", "       10 \345\260\217\350\212\202\n"
"  15:00~16:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("Form_events", "       11 \345\260\217\350\212\202\n"
"  16:00~17:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("Form_events", "       12 \345\260\217\350\212\202\n"
"  17:00~18:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("Form_events", "       13 \345\260\217\350\212\202\n"
"  18:00~19:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("Form_events", "       14 \345\260\217\350\212\202\n"
"  19:00~20:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("Form_events", "       15 \345\260\217\350\212\202\n"
"  20:00~21:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("Form_events", "       16 \345\260\217\350\212\202\n"
"  21:00~22:00", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

#if QT_CONFIG(tooltip)
        tableWidget->setToolTip(QCoreApplication::translate("Form_events", "<html><head/><body><p>\350\277\231\346\230\257\350\257\276\350\241\250</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBox_week1->setText(QCoreApplication::translate("Form_events", "\347\254\2541\345\221\250", nullptr));
        checkBox_week2->setText(QCoreApplication::translate("Form_events", "\347\254\2542\345\221\250", nullptr));
        checkBox_week3->setText(QCoreApplication::translate("Form_events", "\347\254\2543\345\221\250", nullptr));
        checkBox_week4->setText(QCoreApplication::translate("Form_events", "\347\254\2544\345\221\250", nullptr));
        checkBox_week5->setText(QCoreApplication::translate("Form_events", "\347\254\2545\345\221\250", nullptr));
        checkBox_week6->setText(QCoreApplication::translate("Form_events", "\347\254\2546\345\221\250", nullptr));
        checkBox_week7->setText(QCoreApplication::translate("Form_events", "\347\254\2547\345\221\250", nullptr));
        checkBox_week8->setText(QCoreApplication::translate("Form_events", "\347\254\2548\345\221\250", nullptr));
        checkBox_week9->setText(QCoreApplication::translate("Form_events", "\347\254\2549\345\221\250", nullptr));
        checkBox_week10->setText(QCoreApplication::translate("Form_events", "\347\254\25410\345\221\250", nullptr));
        checkBox_week11->setText(QCoreApplication::translate("Form_events", "\347\254\25411\345\221\250", nullptr));
        checkBox_week12->setText(QCoreApplication::translate("Form_events", "\347\254\25412\345\221\250", nullptr));
        checkBox_week13->setText(QCoreApplication::translate("Form_events", "\347\254\25413\345\221\250", nullptr));
        checkBox_week14->setText(QCoreApplication::translate("Form_events", "\347\254\25414\345\221\250", nullptr));
        checkBox_week15->setText(QCoreApplication::translate("Form_events", "\347\254\25415\345\221\250", nullptr));
        checkBox_week16->setText(QCoreApplication::translate("Form_events", "\347\254\25416\345\221\250", nullptr));
        label_18->setText(QCoreApplication::translate("Form_events", "<html><head/><body><p>\350\276\223\345\205\245\345\221\250\346\225\260\357\274\232</p><p><br/></p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("Form_events", "\344\272\213\344\273\266\345\242\236\345\210\240", nullptr));
        groupBox_3->setTitle(QString());
        label_19->setText(QCoreApplication::translate("Form_events", "\351\200\211\346\213\251\344\272\213\345\212\241\357\274\232", nullptr));
        radioButton_event3->setText(QCoreApplication::translate("Form_events", "\351\233\206\344\275\223\344\272\213\345\212\241", nullptr));
        radioButton_event4->setText(QCoreApplication::translate("Form_events", "\344\270\252\344\272\272\344\272\213\345\212\241", nullptr));
        radioButton_event5->setText(QCoreApplication::translate("Form_events", "\344\270\264\346\227\266\344\272\213\345\212\241", nullptr));
        groupBox_2->setTitle(QString());
        label_24->setText(QCoreApplication::translate("Form_events", "\351\200\211\346\213\251\346\223\215\344\275\234:", nullptr));
        radioButton_add->setText(QCoreApplication::translate("Form_events", "\345\242\236\345\212\240\344\272\213\344\273\266", nullptr));
        radioButton_revise->setText(QCoreApplication::translate("Form_events", "\344\277\256\346\224\271\344\272\213\344\273\266", nullptr));
        radioButton_delete->setText(QCoreApplication::translate("Form_events", "\345\210\240\351\231\244\344\272\213\344\273\266", nullptr));
        label_21->setText(QCoreApplication::translate("Form_events", "\350\276\223\345\205\245\344\272\213\344\273\266\345\220\215\347\247\260:", nullptr));
        lineEdit_name->setPlaceholderText(QCoreApplication::translate("Form_events", "\350\257\267\344\277\235\350\257\201\350\276\223\345\205\245\346\255\243\347\241\256\347\232\204\344\272\213\344\273\266\345\220\215\347\247\260", nullptr));
        label_6->setText(QCoreApplication::translate("Form_events", "\350\276\223\345\205\245\344\272\213\344\273\266\345\234\260\347\202\271:", nullptr));
        lineEdit_address->setPlaceholderText(QCoreApplication::translate("Form_events", "\350\257\267\347\241\256\344\277\235\350\276\223\345\205\245\346\255\243\347\241\256\347\232\204\344\272\213\344\273\266\345\234\260\347\202\271", nullptr));
        label_22->setText(QCoreApplication::translate("Form_events", "\350\276\223\345\205\245\345\205\267\344\275\223\346\227\266\351\227\264:", nullptr));
        comboBox_day->setItemText(0, QCoreApplication::translate("Form_events", "    \345\221\250\344\270\200", nullptr));
        comboBox_day->setItemText(1, QCoreApplication::translate("Form_events", "    \345\221\250\344\272\214", nullptr));
        comboBox_day->setItemText(2, QCoreApplication::translate("Form_events", "    \345\221\250\344\270\211", nullptr));
        comboBox_day->setItemText(3, QCoreApplication::translate("Form_events", "    \345\221\250\345\233\233", nullptr));
        comboBox_day->setItemText(4, QCoreApplication::translate("Form_events", "    \345\221\250\344\272\224", nullptr));
        comboBox_day->setItemText(5, QCoreApplication::translate("Form_events", "    \345\221\250\345\205\255", nullptr));
        comboBox_day->setItemText(6, QCoreApplication::translate("Form_events", "    \345\221\250\346\227\245", nullptr));

        comboBox_start_time->setItemText(0, QCoreApplication::translate("Form_events", "       06:00", nullptr));
        comboBox_start_time->setItemText(1, QCoreApplication::translate("Form_events", "       07:00", nullptr));
        comboBox_start_time->setItemText(2, QCoreApplication::translate("Form_events", "       08:00", nullptr));
        comboBox_start_time->setItemText(3, QCoreApplication::translate("Form_events", "       09:00", nullptr));
        comboBox_start_time->setItemText(4, QCoreApplication::translate("Form_events", "       10:00", nullptr));
        comboBox_start_time->setItemText(5, QCoreApplication::translate("Form_events", "       11:00", nullptr));
        comboBox_start_time->setItemText(6, QCoreApplication::translate("Form_events", "       12:00", nullptr));
        comboBox_start_time->setItemText(7, QCoreApplication::translate("Form_events", "       13:00", nullptr));
        comboBox_start_time->setItemText(8, QCoreApplication::translate("Form_events", "       14:00", nullptr));
        comboBox_start_time->setItemText(9, QCoreApplication::translate("Form_events", "       15:00", nullptr));
        comboBox_start_time->setItemText(10, QCoreApplication::translate("Form_events", "       16:00", nullptr));
        comboBox_start_time->setItemText(11, QCoreApplication::translate("Form_events", "       17:00", nullptr));
        comboBox_start_time->setItemText(12, QCoreApplication::translate("Form_events", "       18:00", nullptr));
        comboBox_start_time->setItemText(13, QCoreApplication::translate("Form_events", "       19:00", nullptr));
        comboBox_start_time->setItemText(14, QCoreApplication::translate("Form_events", "       20:00", nullptr));
        comboBox_start_time->setItemText(15, QCoreApplication::translate("Form_events", "       21:00", nullptr));

        label_23->setText(QCoreApplication::translate("Form_events", "~", nullptr));
        comboBox_end_time->setItemText(0, QCoreApplication::translate("Form_events", "       07:00", nullptr));
        comboBox_end_time->setItemText(1, QCoreApplication::translate("Form_events", "       08:00", nullptr));
        comboBox_end_time->setItemText(2, QCoreApplication::translate("Form_events", "       09:00", nullptr));
        comboBox_end_time->setItemText(3, QCoreApplication::translate("Form_events", "       10:00", nullptr));
        comboBox_end_time->setItemText(4, QCoreApplication::translate("Form_events", "       11:00", nullptr));
        comboBox_end_time->setItemText(5, QCoreApplication::translate("Form_events", "       12:00", nullptr));
        comboBox_end_time->setItemText(6, QCoreApplication::translate("Form_events", "       13:00", nullptr));
        comboBox_end_time->setItemText(7, QCoreApplication::translate("Form_events", "       14:00", nullptr));
        comboBox_end_time->setItemText(8, QCoreApplication::translate("Form_events", "       15:00", nullptr));
        comboBox_end_time->setItemText(9, QCoreApplication::translate("Form_events", "       16:00", nullptr));
        comboBox_end_time->setItemText(10, QCoreApplication::translate("Form_events", "       17:00", nullptr));
        comboBox_end_time->setItemText(11, QCoreApplication::translate("Form_events", "       18:00", nullptr));
        comboBox_end_time->setItemText(12, QCoreApplication::translate("Form_events", "       19:00", nullptr));
        comboBox_end_time->setItemText(13, QCoreApplication::translate("Form_events", "       20:00", nullptr));
        comboBox_end_time->setItemText(14, QCoreApplication::translate("Form_events", "       21:00", nullptr));
        comboBox_end_time->setItemText(15, QCoreApplication::translate("Form_events", "       22:00", nullptr));

        pushButton_ok->setText(QCoreApplication::translate("Form_events", "\347\241\256\345\256\232", nullptr));
        pushButton_getevent->setText(QCoreApplication::translate("Form_events", "\345\256\232\344\275\215\344\272\213\344\273\266", nullptr));
        pushButton_clean->setText(QCoreApplication::translate("Form_events", "\346\270\205\347\251\272", nullptr));
        label_5->setText(QCoreApplication::translate("Form_events", "<html><head/><body><p>\346\263\250\357\274\232\345\210\240\351\231\244\344\272\213</p><p>\344\273\266\346\227\266\344\270\215\345\213\276\351\200\211</p><p>\344\277\256\346\224\271\344\272\213\344\273\266\345\217\252</p><p>\350\203\275\344\277\256\346\224\271\345\221\250\346\225\260</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Form_events", "\344\272\213\344\273\266\344\277\241\346\201\257", nullptr));
        label_4->setText(QString());
        event_detial->setText(QString());
        pushButton_refresh->setText(QCoreApplication::translate("Form_events", "\345\210\267\346\226\260", nullptr));
        label_ID->setText(QString());
        label_7->setText(QCoreApplication::translate("Form_events", "\351\200\211\346\213\251\345\217\202\345\212\240\345\255\246\347\224\237\345\255\246\345\217\267\357\274\232", nullptr));
        comboBox_ID->setItemText(0, QCoreApplication::translate("Form_events", "2021210", nullptr));
        comboBox_ID->setItemText(1, QCoreApplication::translate("Form_events", "2021211", nullptr));
        comboBox_ID->setItemText(2, QCoreApplication::translate("Form_events", "2021212", nullptr));
        comboBox_ID->setItemText(3, QCoreApplication::translate("Form_events", "2021213", nullptr));
        comboBox_ID->setItemText(4, QCoreApplication::translate("Form_events", "2021214", nullptr));
        comboBox_ID->setItemText(5, QCoreApplication::translate("Form_events", "2021215", nullptr));
        comboBox_ID->setItemText(6, QCoreApplication::translate("Form_events", "2021216", nullptr));
        comboBox_ID->setItemText(7, QCoreApplication::translate("Form_events", "2021217", nullptr));
        comboBox_ID->setItemText(8, QCoreApplication::translate("Form_events", "2021218", nullptr));
        comboBox_ID->setItemText(9, QCoreApplication::translate("Form_events", "2021219", nullptr));

        pushButton_getID->setText(QCoreApplication::translate("Form_events", "\347\241\256\345\256\232", nullptr));
        label_2->setText(QString());
        bt_day->setText(QString());
        bt_hour->setText(QString());
        cb_week->setItemText(0, QCoreApplication::translate("Form_events", "\347\254\254\344\270\200\345\221\250", nullptr));
        cb_week->setItemText(1, QCoreApplication::translate("Form_events", "\347\254\254\344\272\214\345\221\250", nullptr));
        cb_week->setItemText(2, QCoreApplication::translate("Form_events", "\347\254\254\344\270\211\345\221\250", nullptr));
        cb_week->setItemText(3, QCoreApplication::translate("Form_events", "\347\254\254\345\233\233\345\221\250", nullptr));
        cb_week->setItemText(4, QCoreApplication::translate("Form_events", "\347\254\254\344\272\224\345\221\250", nullptr));
        cb_week->setItemText(5, QCoreApplication::translate("Form_events", "\347\254\254\345\205\255\345\221\250", nullptr));
        cb_week->setItemText(6, QCoreApplication::translate("Form_events", "\347\254\254\344\270\203\345\221\250", nullptr));
        cb_week->setItemText(7, QCoreApplication::translate("Form_events", "\347\254\254\345\205\253\345\221\250", nullptr));
        cb_week->setItemText(8, QCoreApplication::translate("Form_events", "\347\254\254\344\271\235\345\221\250", nullptr));
        cb_week->setItemText(9, QCoreApplication::translate("Form_events", "\347\254\254\345\215\201\345\221\250", nullptr));
        cb_week->setItemText(10, QCoreApplication::translate("Form_events", "\347\254\254\345\215\201\344\270\200\345\221\250", nullptr));
        cb_week->setItemText(11, QCoreApplication::translate("Form_events", "\347\254\254\345\215\201\344\272\214\345\221\250", nullptr));
        cb_week->setItemText(12, QCoreApplication::translate("Form_events", "\347\254\254\345\215\201\344\270\211\345\221\250", nullptr));
        cb_week->setItemText(13, QCoreApplication::translate("Form_events", "\347\254\254\345\215\201\345\233\233\345\221\250", nullptr));
        cb_week->setItemText(14, QCoreApplication::translate("Form_events", "\347\254\254\345\215\201\344\272\224\345\221\250", nullptr));
        cb_week->setItemText(15, QCoreApplication::translate("Form_events", "\347\254\254\345\215\201\345\205\255\345\221\250", nullptr));

        cb_week->setPlaceholderText(QString());
        label_time->setText(QString());
        bt_pause->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form_events: public Ui_Form_events {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM1_H

/********************************************************************************
** Form generated from reading UI file 'adminwdt.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWDT_H
#define UI_ADMINWDT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminwdt
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QComboBox *select_week;
    QTableWidget *tableWidget;
    QPushButton *pushButton_refresh;
    QLabel *label;
    QComboBox *week_sel_combo;
    QLabel *label_2;
    QComboBox *ID_sel_combo;

    void setupUi(QWidget *adminwdt)
    {
        if (adminwdt->objectName().isEmpty())
            adminwdt->setObjectName("adminwdt");
        adminwdt->resize(1600, 900);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(adminwdt->sizePolicy().hasHeightForWidth());
        adminwdt->setSizePolicy(sizePolicy);
        adminwdt->setMinimumSize(QSize(1600, 900));
        adminwdt->setMaximumSize(QSize(1600, 900));
        QFont font;
        font.setPointSize(8);
        adminwdt->setFont(font);
        adminwdt->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(adminwdt);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(adminwdt);
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
        pushButton_refresh = new QPushButton(frame);
        pushButton_refresh->setObjectName("pushButton_refresh");
        pushButton_refresh->setGeometry(QRect(960, 30, 101, 41));
        QFont font7;
        font7.setPointSize(14);
        pushButton_refresh->setFont(font7);
        pushButton_refresh->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(1120, 630, 101, 16));
        QFont font8;
        font8.setPointSize(10);
        label->setFont(font8);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        week_sel_combo = new QComboBox(frame);
        week_sel_combo->setObjectName("week_sel_combo");
        week_sel_combo->setGeometry(QRect(1120, 650, 231, 22));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1120, 710, 151, 16));
        label_2->setFont(font8);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        ID_sel_combo = new QComboBox(frame);
        ID_sel_combo->setObjectName("ID_sel_combo");
        ID_sel_combo->setGeometry(QRect(1120, 730, 231, 22));
        tableWidget->raise();
        select_week->raise();
        pushButton_refresh->raise();
        label->raise();
        week_sel_combo->raise();
        label_2->raise();
        ID_sel_combo->raise();

        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(adminwdt);

        QMetaObject::connectSlotsByName(adminwdt);
    } // setupUi

    void retranslateUi(QWidget *adminwdt)
    {
        adminwdt->setWindowTitle(QCoreApplication::translate("adminwdt", "Form", nullptr));
        select_week->setItemText(0, QCoreApplication::translate("adminwdt", "   \347\254\2541\345\221\250", nullptr));
        select_week->setItemText(1, QCoreApplication::translate("adminwdt", "   \347\254\2542\345\221\250", nullptr));
        select_week->setItemText(2, QCoreApplication::translate("adminwdt", "   \347\254\2543\345\221\250", nullptr));
        select_week->setItemText(3, QCoreApplication::translate("adminwdt", "   \347\254\2544\345\221\250", nullptr));
        select_week->setItemText(4, QCoreApplication::translate("adminwdt", "   \347\254\2545\345\221\250", nullptr));
        select_week->setItemText(5, QCoreApplication::translate("adminwdt", "   \347\254\2546\345\221\250", nullptr));
        select_week->setItemText(6, QCoreApplication::translate("adminwdt", "   \347\254\2547\345\221\250", nullptr));
        select_week->setItemText(7, QCoreApplication::translate("adminwdt", "   \347\254\2548\345\221\250", nullptr));
        select_week->setItemText(8, QCoreApplication::translate("adminwdt", "   \347\254\2549\345\221\250", nullptr));
        select_week->setItemText(9, QCoreApplication::translate("adminwdt", "   \347\254\25410\345\221\250", nullptr));
        select_week->setItemText(10, QCoreApplication::translate("adminwdt", "   \347\254\25411\345\221\250", nullptr));
        select_week->setItemText(11, QCoreApplication::translate("adminwdt", "   \347\254\25412\345\221\250", nullptr));
        select_week->setItemText(12, QCoreApplication::translate("adminwdt", "   \347\254\25413\345\221\250", nullptr));
        select_week->setItemText(13, QCoreApplication::translate("adminwdt", "   \347\254\25414\345\221\250", nullptr));
        select_week->setItemText(14, QCoreApplication::translate("adminwdt", "   \347\254\25415\345\221\250", nullptr));
        select_week->setItemText(15, QCoreApplication::translate("adminwdt", "   \347\254\25416\345\221\250", nullptr));

#if QT_CONFIG(tooltip)
        select_week->setToolTip(QCoreApplication::translate("adminwdt", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        select_week->setWhatsThis(QCoreApplication::translate("adminwdt", "<html><head/><body><p>qr</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("adminwdt", "\345\221\250\344\270\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("adminwdt", "\345\221\250\344\272\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("adminwdt", "\345\221\250\344\270\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("adminwdt", "\345\221\250\345\233\233", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("adminwdt", "\345\221\250\344\272\224", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("adminwdt", "\345\221\250\345\205\255", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("adminwdt", "\345\221\250\346\227\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("adminwdt", "        1 \345\260\217\350\212\202\n"
"  06:00~07:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("adminwdt", "        2 \345\260\217\350\212\202\n"
"  07:00~08:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("adminwdt", "        3 \345\260\217\350\212\202\n"
"  08:00~09:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("adminwdt", "        4 \345\260\217\350\212\202\n"
"  09:00~10:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("adminwdt", "        5 \345\260\217\350\212\202\n"
"  10:00~11:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("adminwdt", "        6 \345\260\217\350\212\202\n"
"  11:00~12:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("adminwdt", "       7 \345\260\217\350\212\202\n"
"  12:00~13:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("adminwdt", "        8 \345\260\217\350\212\202\n"
"  13:00~14:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("adminwdt", "        9 \345\260\217\350\212\202\n"
"  14:00~15:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("adminwdt", "       10 \345\260\217\350\212\202\n"
"  15:00~16:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("adminwdt", "       11 \345\260\217\350\212\202\n"
"  16:00~17:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("adminwdt", "       12 \345\260\217\350\212\202\n"
"  17:00~18:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("adminwdt", "       13 \345\260\217\350\212\202\n"
"  18:00~19:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("adminwdt", "       14 \345\260\217\350\212\202\n"
"  19:00~20:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("adminwdt", "       15 \345\260\217\350\212\202\n"
"  20:00~21:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("adminwdt", "       16 \345\260\217\350\212\202\n"
"  21:00~22:00", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

#if QT_CONFIG(tooltip)
        tableWidget->setToolTip(QCoreApplication::translate("adminwdt", "<html><head/><body><p>\350\277\231\346\230\257\350\257\276\350\241\250</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_refresh->setText(QCoreApplication::translate("adminwdt", "\345\210\267\346\226\260", nullptr));
        label->setText(QCoreApplication::translate("adminwdt", "\350\276\223\345\205\245\345\221\250\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("adminwdt", "\351\200\211\346\213\251\345\217\202\345\212\240\345\255\246\347\224\237\345\255\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminwdt: public Ui_adminwdt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWDT_H

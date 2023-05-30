/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QLabel *head_sculpture;
    QGroupBox *groupBox;
    QLabel *up_background;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QComboBox *select_ID;
    QLineEdit *code_lineedit;
    QHBoxLayout *horizontalLayout;
    QCheckBox *auto_logon;
    QCheckBox *remeber_code;
    QLabel *forget_code;
    QPushButton *log_on;
    QLabel *down_background;
    QLabel *label_wrong;
    QStatusBar *statusbar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(962, 690);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(200000, 200000));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMaximumSize(QSize(721, 571));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        head_sculpture = new QLabel(groupBox_2);
        head_sculpture->setObjectName("head_sculpture");
        head_sculpture->setGeometry(QRect(300, 170, 110, 110));
        head_sculpture->setMinimumSize(QSize(110, 110));
        head_sculpture->setMaximumSize(QSize(110, 110));
        head_sculpture->setStyleSheet(QString::fromUtf8(""));
        head_sculpture->setPixmap(QPixmap(QString::fromUtf8(":/picture/2021210.png")));
        head_sculpture->setScaledContents(true);
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 721, 221));
        up_background = new QLabel(groupBox);
        up_background->setObjectName("up_background");
        up_background->setGeometry(QRect(0, 0, 721, 221));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(up_background->sizePolicy().hasHeightForWidth());
        up_background->setSizePolicy(sizePolicy1);
        up_background->setMaximumSize(QSize(721, 221));
        up_background->setStyleSheet(QString::fromUtf8(""));
        up_background->setTextFormat(Qt::AutoText);
        up_background->setPixmap(QPixmap(QString::fromUtf8(":/picture/lucy.jpg")));
        up_background->setScaledContents(false);
        up_background->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(groupBox_2);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(150, 310, 421, 191));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        select_ID = new QComboBox(gridLayoutWidget);
        select_ID->addItem(QString());
        select_ID->addItem(QString());
        select_ID->addItem(QString());
        select_ID->addItem(QString());
        select_ID->addItem(QString());
        select_ID->addItem(QString());
        select_ID->addItem(QString());
        select_ID->addItem(QString());
        select_ID->addItem(QString());
        select_ID->addItem(QString());
        select_ID->setObjectName("select_ID");
        sizePolicy1.setHeightForWidth(select_ID->sizePolicy().hasHeightForWidth());
        select_ID->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(true);
        select_ID->setFont(font);
        select_ID->setStyleSheet(QString::fromUtf8("padding-left: 6px"));

        verticalLayout->addWidget(select_ID);

        code_lineedit = new QLineEdit(gridLayoutWidget);
        code_lineedit->setObjectName("code_lineedit");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(code_lineedit->sizePolicy().hasHeightForWidth());
        code_lineedit->setSizePolicy(sizePolicy2);
        code_lineedit->setStyleSheet(QString::fromUtf8("padding-left: 6px"));
        code_lineedit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(code_lineedit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        auto_logon = new QCheckBox(gridLayoutWidget);
        auto_logon->setObjectName("auto_logon");

        horizontalLayout->addWidget(auto_logon);

        remeber_code = new QCheckBox(gridLayoutWidget);
        remeber_code->setObjectName("remeber_code");

        horizontalLayout->addWidget(remeber_code);

        forget_code = new QLabel(gridLayoutWidget);
        forget_code->setObjectName("forget_code");

        horizontalLayout->addWidget(forget_code);


        verticalLayout->addLayout(horizontalLayout);

        log_on = new QPushButton(gridLayoutWidget);
        log_on->setObjectName("log_on");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(log_on->sizePolicy().hasHeightForWidth());
        log_on->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\344\273\277\345\256\213")});
        font1.setPointSize(12);
        font1.setBold(false);
        log_on->setFont(font1);
        log_on->setMouseTracking(false);
        log_on->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 202, 254);"));

        verticalLayout->addWidget(log_on);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        down_background = new QLabel(groupBox_2);
        down_background->setObjectName("down_background");
        down_background->setGeometry(QRect(0, 230, 721, 341));
        down_background->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_wrong = new QLabel(groupBox_2);
        label_wrong->setObjectName("label_wrong");
        label_wrong->setGeometry(QRect(220, 520, 271, 41));
        QFont font2;
        font2.setPointSize(10);
        label_wrong->setFont(font2);
        label_wrong->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_wrong->setAlignment(Qt::AlignCenter);
        down_background->raise();
        groupBox->raise();
        gridLayoutWidget->raise();
        head_sculpture->raise();
        label_wrong->raise();

        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 962, 26));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QString());
        head_sculpture->setText(QString());
        groupBox->setTitle(QString());
        up_background->setText(QString());
        select_ID->setItemText(0, QCoreApplication::translate("MainWindow", "2021210", nullptr));
        select_ID->setItemText(1, QCoreApplication::translate("MainWindow", "2021211", nullptr));
        select_ID->setItemText(2, QCoreApplication::translate("MainWindow", "2021212", nullptr));
        select_ID->setItemText(3, QCoreApplication::translate("MainWindow", "2021213", nullptr));
        select_ID->setItemText(4, QCoreApplication::translate("MainWindow", "2021214", nullptr));
        select_ID->setItemText(5, QCoreApplication::translate("MainWindow", "2021215", nullptr));
        select_ID->setItemText(6, QCoreApplication::translate("MainWindow", "2021216", nullptr));
        select_ID->setItemText(7, QCoreApplication::translate("MainWindow", "2021217", nullptr));
        select_ID->setItemText(8, QCoreApplication::translate("MainWindow", "2021218", nullptr));
        select_ID->setItemText(9, QCoreApplication::translate("MainWindow", "2021219", nullptr));

        code_lineedit->setText(QString());
        code_lineedit->setPlaceholderText(QCoreApplication::translate("MainWindow", "  \345\257\206\347\240\201", nullptr));
        auto_logon->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        remeber_code->setText(QCoreApplication::translate("MainWindow", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        forget_code->setText(QCoreApplication::translate("MainWindow", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        log_on->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        down_background->setText(QString());
        label_wrong->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

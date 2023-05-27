/********************************************************************************
** Form generated from reading UI file 'insert_event.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERT_EVENT_H
#define UI_INSERT_EVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QWidget *widget;
    QLabel *label_ID;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QComboBox *comboBox_ID;
    QPushButton *pushButton_ID;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(516, 326);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(150, 280, 191, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(110, 20, 279, 107));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(layoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setFont(font);

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        widget = new QWidget(Dialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 130, 481, 131));
        label_ID = new QLabel(widget);
        label_ID->setObjectName("label_ID");
        label_ID->setGeometry(QRect(20, 50, 421, 71));
        label_ID->setFont(font);
        label_ID->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid rgb(0,0, 0)"));
        label_ID->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        layoutWidget_2 = new QWidget(widget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(9, 0, 441, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName("label_7");
        QFont font1;
        font1.setPointSize(10);
        label_7->setFont(font1);

        horizontalLayout_4->addWidget(label_7);

        comboBox_ID = new QComboBox(layoutWidget_2);
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
        comboBox_ID->setFont(font1);

        horizontalLayout_4->addWidget(comboBox_ID);

        pushButton_ID = new QPushButton(layoutWidget_2);
        pushButton_ID->setObjectName("pushButton_ID");

        horizontalLayout_4->addWidget(pushButton_ID);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\351\200\211\346\213\251\344\272\213\344\273\266\347\261\273\345\236\213\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Dialog", "\351\233\206\344\275\223\344\272\213\345\212\241", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Dialog", "\344\270\252\344\272\272\344\272\213\345\212\241", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Dialog", "\344\270\264\346\227\266\344\272\213\345\212\241", nullptr));

        label_2->setText(QCoreApplication::translate("Dialog", "\344\272\213\344\273\266\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\344\272\213\344\273\266\345\234\260\347\202\271\357\274\232", nullptr));
        label_ID->setText(QString());
        label_7->setText(QCoreApplication::translate("Dialog", "\350\276\223\345\205\245\345\217\202\345\212\240\345\255\246\347\224\237\345\255\246\345\217\267\357\274\232", nullptr));
        comboBox_ID->setItemText(0, QCoreApplication::translate("Dialog", "2021210", nullptr));
        comboBox_ID->setItemText(1, QCoreApplication::translate("Dialog", "2021211", nullptr));
        comboBox_ID->setItemText(2, QCoreApplication::translate("Dialog", "2021212", nullptr));
        comboBox_ID->setItemText(3, QCoreApplication::translate("Dialog", "2021213", nullptr));
        comboBox_ID->setItemText(4, QCoreApplication::translate("Dialog", "2021214", nullptr));
        comboBox_ID->setItemText(5, QCoreApplication::translate("Dialog", "2021215", nullptr));
        comboBox_ID->setItemText(6, QCoreApplication::translate("Dialog", "2021216", nullptr));
        comboBox_ID->setItemText(7, QCoreApplication::translate("Dialog", "2021217", nullptr));
        comboBox_ID->setItemText(8, QCoreApplication::translate("Dialog", "2021218", nullptr));
        comboBox_ID->setItemText(9, QCoreApplication::translate("Dialog", "2021219", nullptr));

        pushButton_ID->setText(QCoreApplication::translate("Dialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERT_EVENT_H

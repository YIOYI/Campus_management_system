#ifndef FORM3_H
#define FORM3_H

#include <QWidget>
#include "ui_form3.h"
#include<QImage>
#include"Person.h"

namespace Ui {
class Form3;
}

class Form3 : public QWidget
{
    Q_OBJECT

public:
    explicit Form3(QWidget *parent = nullptr);
    ~Form3();
    void init_form3(Person *);
private:
    Person* current_user;  //目前正在登录的学生
    Ui::Form3 *ui;
};

#endif // FORM3_H

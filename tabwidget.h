#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include"form1.h"
#include"form2.h"
#include"form3.h"

namespace Ui {
class TabWidget;
}



class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit TabWidget(QWidget *parent = nullptr);
    ~TabWidget();
    void init(Person *);

private:
    Form1 *page1;
    Form2 *page2;
    Form3 *page3;
    Person *current_user;
    Ui::TabWidget *ui;
};


#endif // TABWIDGET_H

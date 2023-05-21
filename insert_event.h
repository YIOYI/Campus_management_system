#ifndef INSERT_EVENT_H
#define INSERT_EVENT_H

#include <QDialog>
#include "ui_insert_event.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    int row; //存储单元格所在行
    int line; //存储单元格所在列
    ~Dialog();
    Ui::Dialog *ui;
};

#endif // INSERT_EVENT_H

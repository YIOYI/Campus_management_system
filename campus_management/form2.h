#ifndef FORM2_H
#define FORM2_H

#include <QWidget>
#include "ui_form2.h"
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QMouseEvent>
#include <QMessageBox>
#include <QPainter>
#include <QTime>
#include <QCompleter>
#include <QString>
#include <QPoint>
#include <cmath>
#include <QWheelEvent>
#include <QTimer>
#include <QScrollBar>
#include"Person.h"
#include"Event.h"

#include "Building.h"

namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT
public slots:
    void guide();
    void clear_map();
    void set_time(const QString &tmp);
    void timeUpdate();
    void time_pause();
    void FF_hour();
    void FF_day();
    void set_week();
    void show_event_info();
public:
    explicit Form2(QWidget *parent = nullptr);
    ~Form2();

    _Time *ti;
    Map *m;      //地图数据
    QImage *map_img; //地图图片
    QImage *guide_img; //导航图片
    QImage *change_img; //缩放图片
    QImage *anime_img; //动画图片
    QImage *saber;   //动画图标
    Person* current_user;  //目前正在登录的学生
    int guide_break=0;
    int paint_over=1;
    float ratio = 1.0;      //地图缩放比例  

    void init_form2(Person *,_Time *);
    void guide_anime(deque<int> &a);
    void plan_anime(deque<int> &a);

protected:
    virtual void wheelEvent(QWheelEvent *event) override;


    friend class StackedWidget;
private:
    Ui::Form2 *ui;
};

#endif // FORM2_H

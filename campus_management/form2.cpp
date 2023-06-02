#include "form2.h"
#include "ui_form2.h"

#define saber_size 48

Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);



    connect(ui->bt_guide,&QPushButton::clicked,this,&Form2::guide);
    connect(ui->bt_clear,&QPushButton::clicked,this,&Form2::clear_map);

    connect(ui->bt_pause,&QPushButton::clicked,this,&Form2::time_pause);
    connect(ui->bt_hour,&QPushButton::clicked,this,&Form2::FF_hour);
    connect(ui->bt_day,&QPushButton::clicked,this,&Form2::FF_day);
    connect(ui->cb_week,&QComboBox::currentIndexChanged,this,&Form2::set_week);

    connect(ui->plan_hour,&QComboBox::currentIndexChanged,this,&Form2::show_event_info);
    connect(ui->plan_day,&QComboBox::currentIndexChanged,this,&Form2::show_event_info);
    connect(ui->plan_week,&QComboBox::currentIndexChanged,this,&Form2::show_event_info);


    m=new Map;
    m->get_Map(); //获取地图

    QStringList word_list;

    for(int i=36;i<87;i++)
        word_list<<m->Buildings_()[i].name_();
    QCompleter *MyInfor = new QCompleter(word_list);
    MyInfor->setFilterMode(Qt::MatchFlag::MatchContains);
    ui->search_src->setCompleter(MyInfor);
    ui->search_tar->setCompleter(MyInfor);
    ui->plan_src->setCompleter(MyInfor);

    map_img=new QImage;
    map_img->load(":/picture/buptmap.jpg");

    guide_img=new QImage(*map_img);
    change_img=new QImage(*guide_img);
    ui->label->setPixmap(QPixmap::fromImage(*map_img));
    ui->label->adjustSize();
    ui->sa_map->setWidget(ui->label);
}

Form2::~Form2()
{
    clear_map();
    delete ui;
    delete m;
    delete map_img;
    delete guide_img;
    delete change_img;
    delete saber;
}
void Form2::guide()
{
    guide_break=0;
    if(ui->plan_hour->currentIndex()==0)
    {
        if(ui->search_src->text().isEmpty()||ui->search_tar->text().isEmpty())
            QMessageBox::information(this,
                                     tr("提示"), tr("出发地点或目的地点为空！"),
                                     QMessageBox::Ok , QMessageBox::Ok);
        else if(m->findBuilding(ui->search_src->text())==-1)
            QMessageBox::information(this,
                                     tr("提示"), tr("出发地点不存在！"),
                                     QMessageBox::Ok , QMessageBox::Ok);
        else if(m->findBuilding(ui->search_tar->text())==-1)
            QMessageBox::information(this,
                                     tr("提示"), tr("目的地点不存在！"),
                                     QMessageBox::Ok , QMessageBox::Ok);
        else if(ui->search_src->text()==ui->search_tar->text())
            QMessageBox::information(this, tr("提示"), tr("您已在目的地！"),
                                     QMessageBox::Ok , QMessageBox::Ok);
        else
        {
            guide_img=new QImage(*map_img);
            ti->time_suspend();

            QString src = ui->search_src->text();
            QString dst = ui->search_tar->text();

            int isrc = m->findBuilding(src);
            int idst = m->findBuilding(dst);

            Building bsrc;
            bsrc = m->Get_i_Building(isrc);

            deque<int> a = bsrc.ShortestPath(idst, *m); //路径点数
            guide_anime(a);
        }
    }
    else
    {
        if(ui->plan_src->text().isEmpty())
            QMessageBox::information(this,tr("提示"), tr("出发地点或目的地点为空！"),
                                     QMessageBox::Ok , QMessageBox::Ok);
        else if(m->findBuilding(ui->plan_src->text())==-1)
            QMessageBox::information(this,tr("提示"), tr("出发地点不存在！"),
                                     QMessageBox::Ok , QMessageBox::Ok);
        else
        {
            guide_img=new QImage(*map_img);
            ti->time_suspend();
            QString src = ui->plan_src->text();
            int isrc = m->findBuilding(src);
            vector<int> b;

            b.push_back(isrc);
            for(auto iter:current_user->perEvents[ui->plan_day->currentIndex()][ui->plan_hour->currentIndex()-1])
            {
                int k=0;
                for(auto j:iter.weeks)
                {
                    if(j==ui->plan_week->currentIndex()+1)
                        k=1;
                }
                if(iter.Tag==1||iter.Tag==2)
                    k=1;
                if(k==1)
                    b.push_back(iter.building.id_());
            }
            b.push_back(isrc);

            Building bsrc;
            bsrc = m->Get_i_Building(isrc);
            deque<int> a = bsrc.ShortestPath(b, *m);
            plan_anime(a);
        }

    }
}
void Form2::wheelEvent(QWheelEvent *event)
{
    if(event->angleDelta().ry()>0)
        ratio = ratio*1.2;
    else if(event->angleDelta().ry()<0)
        ratio = ratio*0.8;
    else
    {
        ratio = ratio*1;//在当前的比例不变
    }
    int w = ratio*guide_img->width();
    int h = ratio*guide_img->height();
    if(paint_over==1)
        ui->label->setPixmap(QPixmap::fromImage(change_img->scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation)));

}
void Form2::clear_map()
{
    //ti->time_suspend();
    ui->label_event_text->clear();
    ui->label_guide_text->clear();
    ui->plan_week->setCurrentIndex(0);
    guide_break=1;
    paint_over=1;
    qDebug("清空导航界面");
    guide_img=new QImage(*map_img);
    int w = ratio*guide_img->width();
    int h = ratio*guide_img->height();
    change_img=new QImage(*guide_img);
    ui->label->setPixmap(QPixmap::fromImage(change_img->scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation)));
}
void Form2::init_form2(Person*a,_Time *ti)
{
    this->ti=ti;
    current_user = a;
    saber=new QImage;
    QString tmp;
    tmp=":/picture/"+QString("%1.png").arg(a->getID());
    saber->load(tmp);
    saber=new QImage(saber->scaled(saber_size,saber_size,Qt::KeepAspectRatio,Qt::SmoothTransformation));
}
void Form2::guide_anime(deque<int> &a)
{
    paint_over=0;
    qDebug("使用导航");
    QPainter painter(guide_img);
    painter.setPen(QPen(Qt::red,3,Qt::SolidLine,Qt::RoundCap));
    QImage *last_img = nullptr;
    for(size_t i = 0; i < a.size()-1; i ++)
    {
        if(guide_break==1)
            break;

        int x1=m->Buildings_()[a[i]].point_().x_()*1500/685;
        int y1=m->Buildings_()[a[i]].point_().y_()*2100/960;
        int x2=m->Buildings_()[a[i+1]].point_().x_()*1500/685;
        int y2=m->Buildings_()[a[i+1]].point_().y_()*2100/960;
        int ny = ui->sa_map->height();
        int nx = ui->sa_map->width();
        int step_x=0,step_y=0;  //x y步长
        if(x1-x2==0)
            step_x=0;
        else step_x=x2>x1?1:-1;
        if(y1-y2==0)
            step_y=0;
        else step_y=y2>y1?1:-1;

        int dis=(x2-x1)*step_x+(y2-y1)*step_y;
        int w ; //显示宽度
        int h ; //显示高度

        vector<QImage*> anime;

        int show_time=50;  //单张图片展示时间/毫秒
        int pen_length=5;
        while(dis>pen_length)
        {
            if(guide_break==1)
                break;
            ui->sa_map->verticalScrollBar()->setSliderPosition(y1*ratio-ny/2);
            ui->sa_map->horizontalScrollBar()->setSliderPosition(x1*ratio-nx/2);
            painter.drawLine(QPoint(x1, y1),
                             QPoint(x1+pen_length*step_x, y1+pen_length*step_y));
            change_img=new QImage(*guide_img);
            QPainter pa(change_img);
            pa.drawImage(x1-saber_size/2,y1-saber_size/2,*saber);
            pa.end();

            w = ratio*guide_img->width();
            h = ratio*guide_img->height();
            ui->label->setPixmap(QPixmap::fromImage((change_img)->scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation)));
            delete last_img;
            last_img=change_img;
            int t_start=QTime::currentTime().msec();
            int t_end=QTime::currentTime().msec();
            while((t_end-t_start>=0&&t_end-t_start<=show_time)
                   || (t_end-t_start<0&&t_end-t_start<=show_time-1000))
            {
                t_end=QTime::currentTime().msec();
                QCoreApplication::processEvents();
            }

            x1+=pen_length*step_x;
            y1+=pen_length*step_y;
            dis=(x2-x1)*step_x+(y2-y1)*step_y;
        }
        if(guide_break==1)
            break;
        ui->sa_map->verticalScrollBar()->setSliderPosition(y2*ratio-ny/2);
        ui->sa_map->horizontalScrollBar()->setSliderPosition(x2*ratio-nx/2);

        painter.drawLine(QPoint(x1, y1),
                         QPoint(x2, y2));

        change_img=new QImage(*guide_img);
        QPainter pa(change_img);
        pa.drawImage(x2-saber_size/2,y2-saber_size/2,*saber);
        pa.end();
        w = ratio*guide_img->width();
        h = ratio*guide_img->height();
        ui->label->setPixmap(QPixmap::fromImage((change_img)->scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation)));
        delete last_img;
        last_img=change_img;
        int t_start=QTime::currentTime().msec();
        int t_end=QTime::currentTime().msec();
        while((t_end-t_start>=0&&t_end-t_start<=show_time)
               || (t_end-t_start<0&&t_end-t_start<=show_time-1000))
        {
            t_end=QTime::currentTime().msec();
            QCoreApplication::processEvents();
        }
    }
    paint_over=1;
    painter.end();
}
void Form2::plan_anime(deque<int> &a)
{
    qDebug("使用多事务规划");
    ui->label_guide_text->clear();
    ui->label_guide_text->setText("开始导航\n");
    QPainter painter(guide_img);
    painter.setPen(QPen(Qt::red,3,Qt::SolidLine,Qt::RoundCap));
    for(size_t i = 0; i < a.size()-1; i ++)
    {
        if(guide_break==1)
            break;

        int x1=m->Buildings_()[a[i]].point_().x_()*1500/685;
        int y1=m->Buildings_()[a[i]].point_().y_()*2100/960;
        int x2=m->Buildings_()[a[i+1]].point_().x_()*1500/685;
        int y2=m->Buildings_()[a[i+1]].point_().y_()*2100/960;
        int ny = ui->sa_map->height();
        int nx = ui->sa_map->width();
        int step_x=0,step_y=0;  //x y步长
        if(x1-x2==0)
            step_x=0;
        else step_x=x2>x1?1:-1;
        if(y1-y2==0)
            step_y=0;
        else step_y=y2>y1?1:-1;

        int dis=(x2-x1)*step_x+(y2-y1)*step_y;
        int w ; //显示宽度
        int h ; //显示高度


        paint_over=0;

        QImage *last_img = nullptr;
        int show_time=50;  //单张图片展示时间/毫秒
        int pen_length=5;
        while(dis>pen_length)
        {
            if(guide_break==1)
                break;
            ui->sa_map->verticalScrollBar()->setSliderPosition(y1*ratio-ny/2);
            ui->sa_map->horizontalScrollBar()->setSliderPosition(x1*ratio-nx/2);
            painter.drawLine(QPoint(x1, y1),
                             QPoint(x1+pen_length*step_x, y1+pen_length*step_y));
            change_img=new QImage(*guide_img);
            QPainter pa(change_img);
            pa.drawImage(x1-saber_size/2,y1-saber_size/2,*saber);
            pa.end();

            w = ratio*guide_img->width();
            h = ratio*guide_img->height();
            ui->label->setPixmap(QPixmap::fromImage((change_img)->scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation)));
            delete last_img;
            last_img=change_img;
            int t_start=QTime::currentTime().msec();
            int t_end=QTime::currentTime().msec();
            while((t_end-t_start>=0&&t_end-t_start<=show_time)
                   || (t_end-t_start<0&&t_end-t_start<=show_time-1000))
            {
                t_end=QTime::currentTime().msec();
                QCoreApplication::processEvents();
            }

            x1+=pen_length*step_x;
            y1+=pen_length*step_y;
            dis=(x2-x1)*step_x+(y2-y1)*step_y;
        }
        if(guide_break==1)
            break;

        ui->sa_map->verticalScrollBar()->setSliderPosition(y2*ratio-ny/2);
        ui->sa_map->horizontalScrollBar()->setSliderPosition(x2*ratio-nx/2);
        painter.drawLine(QPoint(x1, y1),
                         QPoint(x2, y2));

        change_img=new QImage(*guide_img);
        QPainter pa(change_img);
        pa.drawImage(x2-saber_size/2,y2-saber_size/2,*saber);
        pa.end();
        w = ratio*guide_img->width();
        h = ratio*guide_img->height();
        ui->label->setPixmap(QPixmap::fromImage((change_img)->scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation)));
        delete last_img;
        last_img=change_img;
        int t_start=QTime::currentTime().msec();
        int t_end=QTime::currentTime().msec();
        while((t_end-t_start>=0&&t_end-t_start<=show_time)
               || (t_end-t_start<0&&t_end-t_start<=show_time-1000))
        {
            t_end=QTime::currentTime().msec();
            QCoreApplication::processEvents();
        }

        paint_over=1;
        for(auto iter:current_user->perEvents[ui->plan_day->currentIndex()][ui->plan_hour->currentIndex()-1])
        {
            int k=0;
            for(auto j:iter.weeks)
            {
                if(j==ui->plan_week->currentIndex()+1)
                    k=1;
            }
            if(iter.Tag==1||iter.Tag==2)
                k=1;
            if(k==1&&iter.building.id_()==a[i])
            {
                QString tmp=ui->label_guide_text->text();
                if(iter.Tag==1||iter.Tag==2)
                    tmp+="到达上课地点："+iter.building.name_()+"\n完成课程："+iter.name+"\n";
                else
                    tmp+="到达："+iter.building.name_()+"\n完成事务："+iter.name+"\n";
                ui->label_guide_text->setText(tmp);
            }
        }
    }
    painter.end();
    QString tmp=ui->label_guide_text->text();
    tmp+="回到出发地点 导航结束";
    ui->label_guide_text->setText(tmp);
}
void Form2::set_time(const QString &tmp)
{
    ui->cb_week->setCurrentIndex(ti->week()-1);
    ui->label_time->setText(tmp);
    if(ti->is_continue()==1)
        ui->bt_pause->setStyleSheet("border-image: url(:/picture/continue.png);background-color: rgba(229, 229, 229, 0);");
    else
        ui->bt_pause->setStyleSheet("border-image: url(:/picture/pause.png);background-color: rgba(229, 229, 229, 0);");
}
void Form2::timeUpdate()
{
    QString tmp;
    QString day;
    ti->time_now();
    switch (ti->day())
    {
    case 1: day="周一"; break;
    case 2: day="周二"; break;
    case 3: day="周三"; break;
    case 4: day="周四"; break;
    case 5: day="周五"; break;
    case 6: day="周六"; break;
    case 7: day="周日"; break;
    }
    tmp=day+QString("/%1点").arg(ti->hour());
    ui->label_time->setText(tmp);
    ui->cb_week->setCurrentIndex(ti->week()-1);
}
void Form2::time_pause()
{
    if(ti->is_continue()==0)
    {
        ti->time_continue();
    ui->bt_pause->setStyleSheet("border-image: url(:/picture/continue.png);color: rgba(255, 255, 255, 0);");
    }
    else
    {
        ti->time_suspend();
    ui->bt_pause->setStyleSheet("border-image: url(:/picture/pause.png);color: rgba(255, 255, 255, 0);");
    }
}
void Form2::FF_hour()
{
    ti->time_now();
    ti->time_set(ti->week(),ti->day(),ti->hour()+1);
    timeUpdate();
}
void Form2::FF_day()
{
    ti->time_now();
    ti->time_set(ti->week(),ti->day()+1,ti->hour());
    timeUpdate();
}
void Form2::set_week()
{
    if(ti->is_init()==1)
    {
        ti->time_set(ui->cb_week->currentIndex()+1,1,0);
        timeUpdate();
    }
}
void Form2::show_event_info()
{
    if(ui->plan_hour->currentIndex()!=0)
    {
    ui->label_event_text->clear();
    QString tmp;
    for(auto &iter:current_user->perEvents[ui->plan_day->currentIndex()][ui->plan_hour->currentIndex()-1])
    {
            int k=0;
            for(auto j:iter.weeks)
            {
                if(j==ui->plan_week->currentIndex()+1)
                    k=1;
            }
            if(iter.Tag==1||iter.Tag==2)
                k=1;
            if(k==1)
            {
                tmp+="事务："+iter.name+"  地点："+iter.building.name_()+"\n";
                ui->label_event_text->setText(tmp);
            }
    }
    }

}
void Form2::guide_for_alarm(Building dest)
{
    guide_break=0;
    guide_img=new QImage(*map_img);

    Building bsrc;
    int idst = dest.id_();
    int event_num=0;

    ti->time_now();
    int d=ti->day();
    int h=ti->hour();
    h=(h-6)%16;
    for(auto iter:current_user->perEvents[d-1][h])
    {
        int k=0;
        for(auto j:iter.weeks)
        {
            if(j==ui->plan_week->currentIndex()+1)
                k=1;
        }
        if(iter.Tag==1||iter.Tag==2)
            k=1;
        if(k==1)
        {
            bsrc=iter.building;
            event_num++;
        }
    }

    if(event_num!=1)
        bsrc=m->Get_i_Building(46);  //学五

    ui->search_src->setText(bsrc.name_());
    ui->search_tar->setText(dest.name_());

    if(bsrc.id_()==dest.id_())
    {
        clear_map();
        ui->label_guide_text->setText("已在目的地点");
    }
    else
    {
        deque<int> a = bsrc.ShortestPath(idst, *m); //路径点数
        guide_anime(a);
    }
}

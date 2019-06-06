#include "customsplash.h"
#include <QLabel>

CustomSplash::CustomSplash(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint
                         | Qt::WindowSystemMenuHint
                         | Qt::WindowMinMaxButtonsHint
                         | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    //this->setAttribute(Qt::WA_DeleteOnClose);
    this->resize(500,300);

    //设置动画背景
    movie = new QMovie();
    movie->setFileName("E:/1.gif");
    movie->setScaledSize(QSize(300,209));
    QLabel *blkPic = new QLabel(this);
    blkPic->setMovie(movie);
    blkPic->setFixedSize(500,300);

    //设置文字
    this->setSplashText("加载中……",RightTop);
    this->setSplashText("加载中……",LeftTop);
    this->setSplashText("加载中……",RightBottom);
    this->setSplashText("加载中……",LeftBottom);
    this->show();
}

CustomSplash::~CustomSplash()
{
    delete this;
}

void CustomSplash::setSplashBlcPic(QString pic)
{
    movie->setFileName(pic);
}

void CustomSplash::setSplashText(QString text, SplashTextOrientation Orientation)
{
    QLabel *blkPic = new QLabel(text,this);
    blkPic->raise();
    blkPic->setStyleSheet("color:red");

    if(Orientation == LeftTop)
    {
        blkPic->move(20,20);
        blkPic->resize(100,20);
    }
    if(Orientation == RightTop)
    {
        blkPic->move(this->width() - 100,20);
        blkPic->resize(100,20);
    }
    if(Orientation == LeftBottom)
    {
        blkPic->move(20,this->height() - 40);
        blkPic->resize(100,20);
    }
    if(Orientation == RightBottom)
    {
        blkPic->move(this->width() - 100,this->height() - 40);
        blkPic->resize(100,20);
    }
}

void CustomSplash::setSplashText(QString text,QRect rect)
{
    QLabel *blkPic = new QLabel(text,this);
    blkPic->raise();
    blkPic->setStyleSheet("color:red");
    blkPic->setGeometry(rect);
}

void CustomSplash::startSplash()
{
    movie->start();
}

void CustomSplash::stopSplash()
{
    movie->stop();
    this->close();
}

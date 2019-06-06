#ifndef CUSTOMSPLASH_H
#define CUSTOMSPLASH_H
#include <QWidget>
#include <QString>
#include <QMovie>

class CustomSplash : public QWidget
{
    Q_OBJECT

public:
    CustomSplash(QWidget *parent = 0);
    ~CustomSplash();
    enum SplashTextOrientation{LeftTop,RightTop,LeftBottom,RightBottom};
public:
    void startSplash(); //开启启动动画
    void stopSplash();  //停止启动动画
    //设置背景图片
    void setSplashBlcPic(QString pic);
    //设置背景文字
    void setSplashText(QString text, SplashTextOrientation Orientation);
    //设置背景文字
    void setSplashText(QString text, QRect rect);
private:
    QMovie *movie;
};
#endif // CUSTOMSPLASH_H

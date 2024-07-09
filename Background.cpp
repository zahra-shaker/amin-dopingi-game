#include "Background.h"
#include <QGraphicsScene>
#include <QPainter>

Background::Background(int screenWidth, int screenHeight, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    QPixmap pixmap (":/images/hills") ;
    pixmap = pixmap.scaled(pixmap.width(),screenHeight,Qt::KeepAspectRatioByExpanding) ;
    scaledImage = new QPixmap(pixmap);
    pixmap = pixmap.copy(0, 0, pixmap.width()/2, screenHeight) ;
    setPixmap(pixmap) ;

    setPos(0,0) ;

    moveTimer = new QTimer();
    moveTimer->setInterval(50);
    connect(moveTimer, &QTimer::timeout, this, &Background::moveBackground) ;
    moveTimer->start();
}

void Background::moveBackground() {
    currentX = (currentX+5) % scaledImage->width() ;

    QPixmap croppedImage;
    int remindingWidth = scaledImage->width() - currentX;
    if(currentX < scaledImage->width()/2)
        croppedImage = scaledImage->copy(currentX, 0, scaledImage->width()/2, scaledImage->height()) ;
    else{
        croppedImage = scaledImage->copy(currentX, 0, remindingWidth, scaledImage->height()) ;
    }

    QPixmap result(QSize(scaledImage->width()/2, scaledImage->height())) ;
    QPainter p(&result) ;
    p.drawPixmap(0, 0, croppedImage);

    if(currentX >= scaledImage->width()/2) {
        auto imageWidth = scaledImage->width()/2 - remindingWidth;
        auto image = scaledImage->copy(0, 0, imageWidth, scaledImage->height());
        p.drawPixmap(remindingWidth, 0, image) ;
    }

    setPixmap(result) ;
}
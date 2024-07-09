#include "Platform.h"
#include <QGraphicsScene>
#include <QPainter>

Platform::Platform(int screenwidth, int screenHeight, QGraphicsItem* parent) : QGraphicsPixmapItem(parent) {
    QPixmap pixmap (":/images/platform");
    pixmap = pixmap.scaled(2100, 200, Qt::KeepAspectRatioByExpanding);
    platformImage = new QPixmap(pixmap);
    pixmap = pixmap.copy(0, 0, pixmap.width()/2, screenHeight);
    setPixmap(pixmap);

    setPos(0, 680);

    moveTimer = new QTimer();
    moveTimer->setInterval(50);
    connect(moveTimer, &QTimer::timeout, this, &Platform::movePlatform);
    moveTimer->start();
}

void Platform::movePlatform() {
    currentX = (currentX+5) % platformImage->width();
    QPixmap croppedImage;
    int remindingWidth = platformImage->width() - currentX;
    if(currentX < platformImage->width()/2)
        croppedImage = platformImage->copy(currentX, 0, platformImage->width()/2, platformImage->height());
    else{
        croppedImage = platformImage->copy(currentX, 0, remindingWidth, platformImage->height());
    }

    QPixmap result(QSize(platformImage->width()/2, platformImage->height()));
    QPainter p(&result);
    p.drawPixmap(0, 0, croppedImage);

    if(currentX >= platformImage->width()/2) {
        auto imageWidth = platformImage->width()/2 - remindingWidth;
        auto image = platformImage->copy(0, 0, imageWidth, platformImage->height());
        p.drawPixmap(remindingWidth, 0, image) ;
    }
    setPixmap(result);
}

Platform::~Platform() {
    delete platformImage;
    delete moveTimer;
}
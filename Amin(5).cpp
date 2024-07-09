#include "Amin.h"
#include <QKeyEvent>

Amin::Amin(int sceneWidth, int sceneHeight, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {

    setFlags(GraphicsItemFlag::ItemIsFocusable);
    setFocus() ;

    auto pixmap = new QPixmap(":/images/right-1") ;
    auto scaledPixmap = pixmap->scaled(80,176) ;
    setPixmap(scaledPixmap) ;

    frames.append(new QPixmap(scaledPixmap)) ;
    pixmap = new QPixmap(":/images/right-2") ;
    scaledPixmap = pixmap->scaled(80,176) ;
    frames.append(new QPixmap(scaledPixmap)) ;

    runningTimer = new QTimer() ;
    runningTimer->setInterval(100) ;
    connect(runningTimer, &QTimer::timeout, this, &Amin::running) ;
    runningTimer->start() ;


    auto x = sceneWidth/2 - scaledPixmap.width()/2 ;
    auto y = sceneHeight/2 - scaledPixmap.height()/2 ;

    heightAnimator = new QPropertyAnimation(this, "height", this) ;
    heightAnimator->setStartValue(y) ;
    heightAnimator->setEndValue(y) ;
    heightAnimator->setDuration(500) ;
    heightAnimator->start() ;

    connect(heightAnimator, &QPropertyAnimation::finished, this, &Amin::gravity) ;

    groundY = sceneHeight - 360 ;

    setPos (x, y) ;
}

void Amin ::running() {
    setPixmap(*frames.at(frame)) ;
    frame = (frame+1) %2 ;
}

void Amin ::gravity() {
    heightAnimator->stop() ;
    heightAnimator->setStartValue(y()) ;
    heightAnimator->setEndValue(groundY) ;
    heightAnimator->setDuration(1000) ;
    heightAnimator->setEasingCurve(QEasingCurve::InQuad) ;
    heightAnimator->start() ;
}

void Amin ::jump() {
    heightAnimator->stop() ;
    heightAnimator->setStartValue(y()) ;
    heightAnimator->setEndValue(y()-100) ;
    heightAnimator->setDuration(500) ;
    heightAnimator->setEasingCurve(QEasingCurve::OutQuad) ;
    heightAnimator->start() ;
}

void Amin::keyPressEvent(QKeyEvent *event) {
    QGraphicsItem::keyPressEvent(event) ;
    if(event->key() == Qt::Key::Key_Up) {
        jump();
    }
    if(event->key()==Qt::Key::Key_Left) {
        if (pos().x() > 0) {
            setPos(x() - 20, y());
        }
    }
        else if(event->key()==Qt::Key::Key_Right){
            if(pos().x()<650) {
                setPos(x() + 20, y());
            }
        }
    };

Amin::~Amin() {
    delete runningTimer;
    delete heightAnimator;
    qDeleteAll(frames);
}
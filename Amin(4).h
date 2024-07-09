#ifndef AMIN_DOPINGI_AMIN_H
#define AMIN_DOPINGI_AMIN_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <QPropertyAnimation>
#include <QTimer>
#include <QObject>

class Amin : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    Q_PROPERTY(qreal height READ y WRITE setY)

private:
    QList<QPixmap*> frames{} ;
    int frame{};
    int groundY{};
    QTimer* runningTimer;
    QPropertyAnimation *heightAnimator;


public:
    Amin(int sceneWidth, int sceneHeight, QGraphicsItem* parent = nullptr ) ;
    ~Amin() ;
    void jump();

protected:
    void keyPressEvent(QKeyEvent *event) ;
public slots:
    void running() ;
    void gravity() ;

};


#endif //AMIN_DOPINGI_AMIN_H

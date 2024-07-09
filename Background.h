#ifndef AMIN_DOPINGI_BACKGROUND_H
#define AMIN_DOPINGI_BACKGROUND_H

#include <QTimer>
#include <QGraphicsPixmapItem>


class Background : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
private:
    int currentX;
    QPixmap* scaledImage;
    bool initialized{false};
    QTimer* moveTimer;

public:
    Background(int screenWidth, int screenHeight, QGraphicsItem* parent = nullptr) ;
public slots:
    void moveBackground() ;

};


#endif //AMIN_DOPINGI_BACKGROUND_H

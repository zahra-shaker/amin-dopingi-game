#ifndef AMIN_DOPINGI_PLATFORM_H
#define AMIN_DOPINGI_PLATFORM_H

#include <QTimer>
#include <QGraphicsPixmapItem>

class Platform : public QObject, public QGraphicsPixmapItem{
Q_OBJECT
private:
    int currentX;
    QPixmap* platformImage;
    bool initialized{false};
    QTimer* moveTimer;
public:
    Platform(int screenWidth, int screenHeight, QGraphicsItem* parent = nullptr);
    ~Platform();
public slots:
    void movePlatform();
};

#endif //AMIN_DOPINGI_PLATFORM_H
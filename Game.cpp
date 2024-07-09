//
// Created by AC30 on 7/7/2024.
//

#include "Game.h"
#include "views/Background.h"
#include "views/Amin.h"
#include "views/Platform.h"

Game::Game() {
    showFullScreen() ;
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff) ;
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff) ;

    auto playground = new QGraphicsView();
    playground->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff) ;
    playground->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff) ;
    playground->setFrameShape(QFrame::NoFrame);

    auto playgroundScene = new QGraphicsScene(playground);
    playground->setScene(playgroundScene);

    auto gameScene = new QGraphicsScene(this) ;
    gameScene->setSceneRect(0,0,width(),height()) ;

    auto background = new Background(width(), height()) ;
    playgroundScene->addItem(background) ;

    auto platform = new Platform(width(), height());
    playgroundScene->addItem(platform);

    playgroundScene->setSceneRect(0, 0, background->pixmap().width(), background->pixmap().height());
    playground->setFixedSize(background->pixmap().width(), background->pixmap().height());
    playground->move((width() - background->pixmap().width())/2, 0);

    auto amin = new Amin( playgroundScene->width(), playgroundScene->height()) ;
    playgroundScene->addItem(amin) ;

   gameScene->setBackgroundBrush(QBrush(QImage(":/images/background"))) ;

   gameScene->addWidget(playground);
   playground->setFocus();

    setScene(gameScene) ;

}






















#include "..\include\graph.h"
#include "..\..\actors\include\player.h"
#include "..\..\actors\include\wizard.h"
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QLabel>
#include <QGridLayout>
Graph::Graph(QWidget *parent) : QGraphicsView(parent)
{
    //scene Setup
    QGridLayout *mainScene = new QGridLayout(this);


    setWindowTitle("Serie 7 exercice 1");
    resize(500,600);


    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //mainScene->addLayout(statistics,0,0,Qt::AlignCenter);


    //gridLayout->addLayout()
    //Text
    /*
    QGraphicsSimpleTextItem *text = mainScene->addSimpleText("les différentes formes avec Qt et QGraphicsView");
    text->setPos(0,0);
    text->setBrush(QBrush(Qt::blue));

    //Ellipse
    QGraphicsEllipseItem *ellipse = mainScene->addEllipse(40,40,70,90, QPen(Qt::black), QBrush(Qt::blue));
    ellipse->setSpanAngle(140*16);
    ellipse->setStartAngle(20*16);
    QGraphicsSimpleTextItem *tEllipse = mainScene->addSimpleText("addEllipse");
    tEllipse->setPos(160,60);

    //Rectangle
    QGraphicsRectItem *rectangle = mainScene->addRect(40,120, 100, 80,QPen(Qt::black), QBrush(Qt::red));
    QGraphicsSimpleTextItem *tRectangle = mainScene->addSimpleText("addRectangle");
    tRectangle->setPos(160,160);

    //Polygon
    QPolygon polygon;
    polygon << QPoint(40, 270);
    polygon << QPoint(45, 224);
    polygon << QPoint(60, 254);
    polygon << QPoint(67, 224);

    QGraphicsPolygonItem *poly = mainScene->addPolygon(polygon);
    poly->setBrush(QBrush(Qt::yellow));

    QGraphicsSimpleTextItem *tPolygon = mainScene->addSimpleText("addPoly");
    tPolygon->setPos(160,240);

    //pixmap
    QPixmap pixmap("C:/DEV/HES_ETE_Projet/QT/Serie7_Ex1/img/Smiley.jpg");
    pixmap = pixmap.scaledToHeight(40);
    pixmap = pixmap.scaledToWidth(40);
    QGraphicsPixmapItem *pm = mainScene->addPixmap(pixmap);
    pm->setPos(40, 300);

    QGraphicsSimpleTextItem *tPixmap = mainScene->addSimpleText("addPixmap");
    tPixmap->setPos(160,320);

    //Line
    QLine ln;
    ln.setP1(QPoint(0,0));
    ln.setP2(QPoint(width(),height()));
    QGraphicsLineItem *line = mainScene->addLine(ln);
    line->setPen(QPen(Qt::green));
    QGraphicsSimpleTextItem *tLine = mainScene->addSimpleText("addline");
    tLine->setPos(350,400);

    //Round rectangle
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    QPainterPath path;
    path.addRoundedRect(QRectF(40, 370, 100, 50), 10, 10);
    QPen pen(Qt::black, 10);
    p.setPen(pen);
    p.fillPath(path, Qt::red);
    p.drawPath(path);

    QGraphicsPathItem *pathRect = mainScene->addPath(path,QPen(Qt::black),QBrush(Qt::yellow));
    QGraphicsSimpleTextItem *tRRect = mainScene->addSimpleText("addRoundRectangle");
    tRRect->setPos(160,375);


    //Ellipse
    QGraphicsEllipseItem *ellipse2 = mainScene->addEllipse(40,450,70,90, QPen(Qt::black), QBrush(Qt::green));
    QGraphicsSimpleTextItem *tEllipse2 = mainScene->addSimpleText("addEllipse");
    tEllipse2->setPos(160,450);

    //Drag and drop
    setAcceptDrops(true);
    ellipse->setFlag(QGraphicsItem::ItemIsMovable);
    ellipse2->setFlag(QGraphicsItem::ItemIsMovable);
    tEllipse->setFlag(QGraphicsItem::ItemIsMovable);
    tEllipse2->setFlag(QGraphicsItem::ItemIsMovable);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);
    tRectangle->setFlag(QGraphicsItem::ItemIsMovable);
    pm->setFlag(QGraphicsItem::ItemIsMovable);
    tPixmap->setFlag(QGraphicsItem::ItemIsMovable);
    poly->setFlag(QGraphicsItem::ItemIsMovable);
    tPolygon->setFlag(QGraphicsItem::ItemIsMovable);
    pathRect->setFlag(QGraphicsItem::ItemIsMovable);
    tRRect->setFlag(QGraphicsItem::ItemIsMovable);
    */

}



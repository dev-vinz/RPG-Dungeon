/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QWidget>
class Graph : public QGraphicsView
{
    Q_OBJECT
public:
    Graph(QWidget *parent = 0);
private:

};

#endif // GRAPH_H

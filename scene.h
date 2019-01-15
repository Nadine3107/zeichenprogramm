#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMoveEvent>
#include <QPoint>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

signals:
    void mouseClicked(QPoint newPoint);

public slots:
};

#endif // SCENE_H

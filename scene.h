#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMoveEvent>
#include <QPoint>
#include <QMouseEvent>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void mouseClicked(QPoint newPoint);
    void mouseMoved(QPoint newPoint);
    void mousePressed(QPoint startPoint);
    void mouseReleased(QPoint endPoint);

public slots:
};

#endif // SCENE_H

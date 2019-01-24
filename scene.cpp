#include "scene.h"


Scene::Scene(QObject *parent)
{

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit mouseClicked(event->scenePos().toPoint());
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit mouseMoved(event->scenePos().toPoint());
}

void Scene::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton) {
        emit mousePressed(event->screenPos().toPoint());
    }
}

void Scene::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton) {
        emit mouseReleased(event->screenPos().toPoint());
    }
}

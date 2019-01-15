#include "scene.h"


Scene::Scene(QObject *parent)
{

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit mouseClicked(event->scenePos().toPoint());
}

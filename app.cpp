#include "app.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QDebug>

App::App(QObject *parent) : QObject(parent)
{
    m_state = new AppState();
    m_scene = new Scene();
}

App::~App()
{
    delete m_state;
    delete m_scene;
}

Scene *App::scene() const
{
    return m_scene;
}

void App::setScene(Scene *scene)
{
    m_scene = scene;
}

AppState *App::state() const
{
    return m_state;
}

void App::setState(AppState *state)
{
    m_state = state;
}

void App::onCanvasClicked()
{
    //fügt das derzet in m_state ausgewählte Element aus und fügt es m_scene hinzu
    //Die Variablen rechnen bei der angegeben Höhe und Breite durch 2, damit das Element an deer Spitze des mauszeigers erscheint und nicht links davon

        if(m_state->selectedTool() == CIRCLE) {

            double mStateX = m_state->selectedPosition().rx() - m_state->selectedWidth() / 2;
            double mStateY = m_state->selectedPosition().ry() - m_state->selectedHeight() / 2;

            QAbstractGraphicsShapeItem *shape = new QGraphicsEllipseItem(mStateX, mStateY, m_state->selectedWidth(),m_state->selectedHeight());
            shape->setBrush(QBrush(m_state->selectedColor()));
            m_scene->addItem(shape);
            m_state->setSelectedShape(shape);
        } else if (m_state->selectedTool() == RECTANGLE) {

            double mStateX = m_state->selectedPosition().rx() - m_state->selectedWidth() / 2;
            double mStateY = m_state->selectedPosition().ry() - m_state->selectedHeight() / 2;

            QAbstractGraphicsShapeItem *shape = new QGraphicsRectItem(mStateX, mStateY, m_state->selectedWidth(),m_state->selectedHeight());
            shape->setBrush(QBrush(m_state->selectedColor()));
            m_scene->addItem(shape);
            m_state->setSelectedShape(shape);
        } else if (m_state->selectedTool() == SQUARE) {

            double mStateX = m_state->selectedPosition().rx() - m_state->selectedWidth() / 2;
            double mStateY = m_state->selectedPosition().ry() - m_state->selectedHeight() / 2;

            QAbstractGraphicsShapeItem *shape = new QGraphicsRectItem(mStateX, mStateY, m_state->selectedWidth(),m_state->selectedWidth());
            shape->setBrush(QBrush(m_state->selectedColor()));
            m_scene->addItem(shape);
            m_state->setSelectedShape(shape);
        } else if (m_state->selectedTool() == LINE) {
            if(m_lineStarted) {
                double mStateX = m_state->selectedPosition().rx() - m_state->selectedWidth() / 2;
                double mStateY = m_state->selectedPosition().ry() - m_state->selectedHeight() / 2;
                QBrush brush = QBrush(m_state->selectedColor());
                brush.setStyle(Qt::BrushStyle::SolidPattern);
                QPen pen = QPen(brush, m_state->selectedWidth(), Qt::PenStyle::SolidLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::RoundJoin);
                QGraphicsLineItem *shape = new QGraphicsLineItem(m_lineStartX, m_lineStartY, mStateX, mStateY, nullptr);
                shape->setPen(pen);
                m_scene->addItem(shape);
                m_lineStarted = false;
            } else {
                double mStateX = m_state->selectedPosition().rx() - m_state->selectedWidth() / 2;
                double mStateY = m_state->selectedPosition().ry() - m_state->selectedHeight() / 2;
                m_lineStartX = mStateX;
                m_lineStartY = mStateY;
                m_lineStarted = true;
            }
        }
}

void App::onCanvasMove(QPoint location)
{
    // TODO: qInfo() << "onCanvasMove";
}

void App::onSetStartPoint(QPoint start)
{
    qInfo() << "onCanvasStart";
}

void App::onSetEndPoint(QPoint end)
{
    qInfo() << "onCanvasEnd";
}

#include "appstate.h"
#include <QDebug>

AppState::AppState(QObject *parent) : QObject(parent)
{
    m_selectedWidth = 15;
    m_selectedHeight = 15;
}

AppState::~AppState()
{

}

Tool AppState::selectedTool() const
{
    return m_selectedTool;
}

void AppState::setSelectedTool(const QString &selectedTool)
{
    // setzt das Tool
    if(selectedTool == "Rectangle"){
        m_selectedTool = Tool::RECTANGLE;
    } else if(selectedTool == "Square"){
        m_selectedTool = Tool::SQUARE;
    } else if(selectedTool == "Circle"){
        m_selectedTool = Tool::CIRCLE;
    } else if(selectedTool == "Delete"){
        m_selectedTool = Tool::DELETE;
    } else if(selectedTool == "No Selection"){
        m_selectedTool = Tool::NO_SELECTION;
    }
}

QColor AppState::selectedColor() const
{
    return m_selectedColor;
}

void AppState::setSelectedColor(const QColor &selectedColor)
{
    m_selectedColor = selectedColor;
}

void AppState::setSelectedColor(const QString &selectedColor)
{
    if(selectedColor == "Black"){
        this->setSelectedColor(Qt::GlobalColor::black);
    } else if(selectedColor == "Red"){
        this->setSelectedColor(Qt::GlobalColor::red);
    } else if(selectedColor == "Orange"){
        this->setSelectedColor(QColor(255,165,0));
    } else if(selectedColor == "Yellow"){
        this->setSelectedColor(Qt::GlobalColor::yellow);
    } else if(selectedColor == "Green"){
        this->setSelectedColor(Qt::GlobalColor::green);
    } else if(selectedColor == "Blue"){
        this->setSelectedColor(Qt::GlobalColor::cyan);
    } else if(selectedColor == "Darker Blue"){
        this->setSelectedColor(Qt::GlobalColor::darkBlue);
    } else if(selectedColor == "Pink"){
        this->setSelectedColor(Qt::GlobalColor::magenta);
    } else if(selectedColor == "Brown"){
        this->setSelectedColor(QColor(139,69,19));
    } else{
        this->setSelectedColor(Qt::GlobalColor::white);
    }
}

qreal AppState::selectedWidth() const
{
    return m_selectedWidth;
}

void AppState::setSelectedWidth(const int &selectedWidth)
{
    m_selectedWidth = static_cast<qreal>(selectedWidth);
}

qreal AppState::selectedHeight() const
{
    return m_selectedHeight ;
}

void AppState::setSelectedHeight(const int &selectedHeight)
{
    m_selectedHeight = static_cast<qreal>(selectedHeight);
}

QPoint AppState::selectedPosition() const
{
    return m_selectedPosition;
}

void AppState::setSelectedPosition(const QPoint &selectedPosition)
{
    m_selectedPosition = selectedPosition;
}

void AppState::setStartPoint(const QPoint &start)
{
    if(leftMouseButtonDown)
        startPoint = start;
}

void AppState::setEndPoint(const QPoint &end)
{
    if(leftMouseButtonDown)
        endPoint = end;
}

QAbstractGraphicsShapeItem *AppState::selectedShape() const
{
    return m_selectedShape;
}

void AppState::setSelectedShape(QAbstractGraphicsShapeItem *selectedShape)
{
    m_selectedShape = selectedShape;
}

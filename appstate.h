#ifndef APPSTATE_H
#define APPSTATE_H

#include <QObject>
#include <QColor>
#include <QPoint>
#include <QAbstractGraphicsShapeItem>

/**
 * @brief The Tool enum
 * @details The Tool that is used on the Canvas
 * @param RECTANGLE
 * @param SQUARE
 * @param CIRCLE
 * @param DELETE
 * @param NO_SELECTION
 */
enum Tool {
    RECTANGLE, SQUARE, CIRCLE, DELETE, NO_SELECTION
};
/**
 * @brief The AppState class
 * @details The AppState class describes the current State of the App
 * @author Markus Kerkhoff
 * @date 12.12.2018
 */
class AppState : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Tool newTool MEMBER m_selectedTool NOTIFY toolChanged)
    Q_PROPERTY(QColor newColor MEMBER m_selectedColor NOTIFY colorChanged)
    Q_PROPERTY(qreal newWidth MEMBER m_selectedWidth NOTIFY widthChanged)
    Q_PROPERTY(qreal newHeight MEMBER m_selectedHeight NOTIFY heightChanged)


private:

    /**
     * @brief m_selectedTool
     */
    Tool m_selectedTool;

    /**
     * @brief m_selectedColor
     */
    QColor m_selectedColor;

    /**
     * @brief m_selectedWidth
     */
    qreal m_selectedWidth;

    /**
     * @brief m_selectedHeight
     */
    qreal m_selectedHeight;

    /**
     * @brief m_selectedPosition
     */
    QPoint m_selectedPosition;

    /**
     * @brief m_selectedShape
     */
    QAbstractGraphicsShapeItem* m_selectedShape;

    void setSelectedColor(const QColor &selectedColor);

public:
    explicit AppState(QObject *parent = nullptr);
    ~AppState();


    Tool selectedTool() const;
    QColor selectedColor() const;
    qreal selectedWidth() const;
    qreal selectedHeight() const;
    QPoint selectedPosition() const;
    QAbstractGraphicsShapeItem *selectedShape() const;

signals:
    void widthChanged(int newWidth);
    void heightChanged(int newHeight);
    void toolChanged(Tool newTool);
    void colorChanged(QColor newColor);

public slots:
    void setSelectedTool(const QString &selectedTool);
    void setSelectedColor(const QString &selectedColor);
    void setSelectedWidth(const int &selectedWidth);
    void setSelectedHeight(const int &selectedHeight);
    void setSelectedPosition(const QPoint &selectedPosition);
    void setSelectedShape(QAbstractGraphicsShapeItem *selectedShape);

};


#endif // APPSTATE_H

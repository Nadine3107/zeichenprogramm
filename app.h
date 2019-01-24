#ifndef APP_H
#define APP_H

#include <QObject>
#include "scene.h"
#include "appstate.h"

/**
 * @brief The App class
 * @details The App class consists of a Scene and an AppState<br>
 * The scene symbolises the canvas and the AppState saves the data about the current element.
 * @author Markus Kerkhoff
 * @date 12.12.2018
 */
class App : public QObject
{
Q_OBJECT

private:
     /**
     * @brief m_scene
     */
    Scene *m_scene;
    /**
     * @brief m_state
     */
    AppState *m_state;

    bool m_lineStarted = false;
    qreal m_lineStartX = -1;
    qreal m_lineStartY = -1;

public:
    /**
     * @brief App
     * @details Standard-constructor for an App.
     * A new AppState and a new QGraphicsScene is created. The parent of the object is nullptr;
     * @param parent
     */
    explicit App(QObject *parent = nullptr);
    ~App();

    Scene *scene() const;
    void setScene(Scene *scene);

    AppState *state() const;
    void setState(AppState *state);

signals:

public slots:
    /**
     * @brief onCanvasClicked
     * @details Adds a Shape-Object to the scene.
     */
    void onCanvasClicked();
    void onCanvasMove(QPoint location);
    void onSetStartPoint(QPoint start);
    void onSetEndPoint(QPoint end);

};

#endif // APP_H

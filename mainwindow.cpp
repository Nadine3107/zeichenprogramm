#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "app.h"
#include "appstate.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    App *app = new App;

    // Standardwerte
    app->state()->setSelectedWidth(100);
    app->state()->setSelectedHeight(100);
    app->state()->setSelectedTool("Rectangle");

    ui->canvas->setScene(app->scene());

    connect( ui->comboBox_tool, SIGNAL(currentTextChanged(QString)), app->state(), SLOT(setSelectedTool(QString)));
    connect(ui->comboBox_color, SIGNAL(currentTextChanged(QString)), app->state(), SLOT(setSelectedColor(QString)));
    connect( ui->spinBox_width, SIGNAL(valueChanged(int)), app->state(), SLOT(setSelectedWidth(int)));
    connect(app->state(), SIGNAL(widthChanged), ui->spinBox_width, SLOT(setValue(int)));
    connect( ui->spinBox_height, SIGNAL(valueChanged(int)), app->state(), SLOT(setSelectedHeight(int)));
    connect(app->state(), SIGNAL(heightChanged), ui->spinBox_height, SLOT(setValue(int)));
    connect(app->scene(), SIGNAL(mouseClicked(QPoint)), app->state(), SLOT(setSelectedPosition(QPoint)));
    connect(app->scene(), SIGNAL(mouseClicked(QPoint)), app, SLOT(onCanvasClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

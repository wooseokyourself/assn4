#include "widgets/mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

/*namespace as4::widgets
{

}*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /* Put your code here */
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

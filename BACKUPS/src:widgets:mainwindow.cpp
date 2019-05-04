#include "widgets/mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QLabel>

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


void MainWindow::on_pushButton_pressed()
{
    std::cout<<"더럽네요"<<std::endl;
    QLabel* lb1;
    lb1 = new QLabel(this);
    lb1->setText("포기했습니다");
    lb1->show();
}

void MainWindow::on_pushButton_clicked()
{
    exit(1);
}

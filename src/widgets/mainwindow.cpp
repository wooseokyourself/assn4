#include "widgets/mainwindow.h"
#include "ui_mainwindow.h"

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

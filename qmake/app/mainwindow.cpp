#include "mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    MelodyRoll = new ClickableLabel(ui->tab);
    DrumRoll = new ClickableLabel(ui->tab_2);
}

mainwindow::~mainwindow()
{
    delete ui;
    delete MelodyRoll;
    delete DrumRoll;
}

void mainwindow::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
}

void mainwindow::mouseMoveEvent(QMouseEvent* event)
{
    QWidget::mouseMoveEvent(event);
}


// slots
void mainwindow::PlaySong()
{

}

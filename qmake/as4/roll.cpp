#include "roll.h"
#include "ui_roll.h"

Roll::Roll(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Roll)
{
    ui->setupUi(this);
}

Roll::~Roll()
{
    delete ui;
}

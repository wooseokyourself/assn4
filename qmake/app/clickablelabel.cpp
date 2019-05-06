#include "clickablelabel.h"
#include <iostream>
using namespace std;

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    setPixmap(QPixmap(":/image/image/Pianoroll-main.png"));
}

ClickableLabel::~ClickableLabel()
{   }

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        PutNote(event->pos());
    }
    else if(event->button() == Qt::RightButton){
        RemoveNote(event->pos());
    }
}

void ClickableLabel::PutNote(QPoint pos)
{
    cout<<"left"<<endl;
    cout<<pos.x()<<endl;
    cout<<pos.y()<<endl;
}

void ClickableLabel::RemoveNote(QPoint pos)
{
    cout<<"right"<<endl;
    cout<<pos.x()<<endl;
    cout<<pos.y()<<endl;
}

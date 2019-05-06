#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    setPixmap(QPixmap(":/image/image/Pianoroll-main.png"));
}

ClickableLabel::~ClickableLabel()
{
}

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        emit Put(event->pos(), this);
    }
    else if(event->button() == Qt::RightButton){
        emit Remove(event->pos(), this);
    }
}

#include "visualnote.h"
#include <iostream>

VisualNote::VisualNote(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    setPixmap(QPixmap(":/image/image/bar.png"));
}

VisualNote::~VisualNote()
{
    std::cout<<"소멸자다 이새끼야!"<<std::endl;
}

int VisualNote::getX() const
{
    return x;
}

int VisualNote::getY() const
{
    return y;
}

void VisualNote::set(QPoint pos)
{
    x = pos.x()/24;
    x *= 24;
    x += 3;
    y = pos.y()/24;
    y *= 24;
    y += 4;
    setGeometry(x, y, 88, 22);
    show();
}

bool VisualNote::find(int x, int y)
{
    return(this->x == x && this->y == y);
}

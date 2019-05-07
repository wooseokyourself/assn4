#ifndef __AS4_CLICKABLELABEL_H_
#define __AS4_CLICKABLELABEL_H_

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>

#include <iostream>

using namespace std;

namespace Ui{
class ClickableLabel;
}

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel();

protected:
    void mousePressEvent(QMouseEvent* event);

signals:
    void Put(QPoint pos, ClickableLabel*);
    void Remove(QPoint pos, ClickableLabel*);
};

#endif // CLICKABLELABLE_H

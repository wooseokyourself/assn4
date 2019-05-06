#ifndef __AS4_CLICKABLELABEL_H_
#define __AS4_CLICKABLELABEL_H_

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <QPixmap>
#include <QMouseEvent>
#include <QPoint>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel();

protected:
    void mousePressEvent(QMouseEvent* event);
    void PutNote(QPoint pos);
    void RemoveNote(QPoint pos);
};

#endif // CLICKABLELABLE_H

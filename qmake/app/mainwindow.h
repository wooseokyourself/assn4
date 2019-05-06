#ifndef __AS4_WIDGETS_MAINWINDOW_H
#define __AS4_WIDGETS_MAINWINDOW_H


#include <QWidget>
#include <QPaintDevice>
#include <QMouseEvent>
#include "clickablelabel.h"
#include "visualnote.h"
#include <vector>

namespace Ui {
class mainwindow;
}

class mainwindow : public QWidget
{
    Q_OBJECT
public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

protected slots:
    void PutNote(QPoint pos, ClickableLabel* tab);
    void RemoveNote(QPoint pos, ClickableLabel* tab);

private:
    Ui::mainwindow *ui;
    ClickableLabel* MelodyRoll;
    ClickableLabel* DrumRoll;
    vector<VisualNote*> notes;
};

#endif

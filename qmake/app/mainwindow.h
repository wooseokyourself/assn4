#ifndef __AS4_WIDGETS_MAINWINDOW_H
#define __AS4_WIDGETS_MAINWINDOW_H


#include <QWidget>
#include <QPaintDevice>
#include <QMouseEvent>
#include "clickablelabel.h"
#include "visualnote.h"
#include <QVector>

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
    void PutMelodyNote(QPoint pos, ClickableLabel* tab);
    void PutDrumNote(QPoint pos, ClickableLabel* tab);
    void RemoveMelodyNote(QPoint pos, ClickableLabel* tab);
    void RemoveDrumNote(QPoint pos, ClickableLabel* tab);

private:
    Ui::mainwindow *ui;
    ClickableLabel* MelodyRoll;
    ClickableLabel* DrumRoll;
    QVector<VisualNote*> melody_notes;
    QVector<VisualNote*> drum_notes;
};

#endif

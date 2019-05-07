#ifndef __AS4_WIDGETS_MAINWINDOW_H
#define __AS4_WIDGETS_MAINWINDOW_H


#include <QWidget>
#include <QPaintDevice>
#include <QMouseEvent>
#include "clickablelabel.h"
#include "visualnote.h"
#include <QVector>

#include "io/seqio.h"
#include "io/songio.h"
#include "model/time.h"
#include "model/note.h"

using namespace as4::model;
using namespace as4::io;

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

signals: // 실제 구현되지 않음. 앞으로 구현해야 함.
    void PutInSequence(int start, int duration, int pitch, int octave);
    void PutInSequenceDrum(int start, int duration, int pitch, int octave);
    void RemoveFromSequenceMelody(int start, int duration, int pitch, int octave);
    void RemoveFromSequenceDrum(int start, int duration, int pitch, int octave);

protected slots:
    void PutMelodyNote(QPoint pos, ClickableLabel* tab);
    void PutDrumNote(QPoint pos, ClickableLabel* tab);
    void RemoveMelodyNote(QPoint pos, ClickableLabel* tab);
    void RemoveDrumNote(QPoint pos, ClickableLabel* tab);

private slots:
    void on_PlayButton_clicked();

private:
    Ui::mainwindow *ui;
    ClickableLabel* MelodyRoll;
    ClickableLabel* DrumRoll;
    QVector<VisualNote*> melody_notes;
    QVector<VisualNote*> drum_notes;
    Song *FullSong;
};

#endif

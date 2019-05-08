#ifndef __AS4_WIDGETS_MAINWINDOW_H
#define __AS4_WIDGETS_MAINWINDOW_H


#include <QWidget>
#include <QPaintDevice>
#include <QMouseEvent>
#include <QVector>

#include "clickablelabel.h"
#include "visualnote.h"
#include "playsong.h"

using namespace as4::model;

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

signals:
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

    void on_pushButton_clicked();

private:
    Ui::mainwindow *ui;
    ClickableLabel* MelodyRoll;
    ClickableLabel* DrumRoll;
    QVector<VisualNote*> melody_notes;
    QVector<VisualNote*> drum_notes;
    Song *FullSong;
    PlaySong Player;
};

#endif

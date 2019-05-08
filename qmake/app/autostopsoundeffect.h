#ifndef __AS4_AUTOSTOPSOUNDEFFECT_H_
#define __AS4_AUTOSTOPSOUNDEFFECT_H_

#include <QWidget>
#include <QTimer>
#include <QSoundEffect>

class AutoStopSoundEffect : public QSoundEffect
{
    Q_OBJECT
public:
    AutoStopSoundEffect(float duration);
    ~AutoStopSoundEffect();
    void play();

private:
    QTimer* timer;
    int convertedDuration;
};

#endif // AUTOSTOPSOUNDEFFECT_H

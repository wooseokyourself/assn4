#include "autostopsoundeffect.h"

AutoStopSoundEffect::AutoStopSoundEffect(float duration)
{
    convertedDuration = duration * 250;
}

AutoStopSoundEffect::~AutoStopSoundEffect()
{
    delete timer;
}

void AutoStopSoundEffect::play()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(stop()));
    QSoundEffect::play();
    timer->start(convertedDuration);
}

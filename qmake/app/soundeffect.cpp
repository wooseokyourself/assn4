#include "soundeffect.h"

DefaultSoundEffect::DefaultSoundEffect()
{

}

DefaultSoundEffect::~DefaultSoundEffect()
{

}

void DefaultSoundEffect::play()
{
    QSoundEffect::play();
}

AutoStopSoundEffect::AutoStopSoundEffect(int Stop_milisec)
    : Stop_milisec(Stop_milisec)
{

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
    timer->start(Stop_milisec);
}

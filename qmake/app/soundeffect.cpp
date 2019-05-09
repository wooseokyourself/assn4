#include "soundeffect.h"

// 이하 두 선언 디버깅용
#include <iostream>
using namespace std;

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
    cout<<" AutoStopSoundEffect.play()!"<<endl;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(stop()));
    QSoundEffect::play();
    timer->start(Stop_milisec);
}

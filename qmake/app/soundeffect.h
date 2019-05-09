#ifndef __AS4_SOUNDEFFECT_H_
#define __AS4_SOUNDEFFECT_H_

#include <QWidget>
#include <QTimer>
#include <QSoundEffect>

class DefaultSoundEffect : public QSoundEffect
{
    Q_OBJECT
public:
    DefaultSoundEffect();
    virtual ~DefaultSoundEffect();
    virtual void play();
};

class AutoStopSoundEffect : public DefaultSoundEffect
{
    Q_OBJECT
public:
    AutoStopSoundEffect(int Stop_milisec);
    virtual ~AutoStopSoundEffect();
    virtual void play();

private:
    QTimer* timer;
    int Stop_milisec;
};

#endif

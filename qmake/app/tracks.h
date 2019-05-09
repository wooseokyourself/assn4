#ifndef __AS4_TRACKS_H_
#define __AS4_TRACKS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <QUrl>
#include <QMediaPlayer>

#include "soundeffect.h"
#include "model/seq.h"
#include "model/song.h"
#include "model/time.h"

class DefaultTrack : QWidget
{
    Q_OBJECT
public:
    explicit DefaultTrack(QWidget *parent = nullptr);
    virtual ~DefaultTrack();
    virtual void setPath(as4::model::ISeq* seq);
    virtual void setVector();
    void play();
    bool isPlay();

protected slots:
    void playUnit();

protected:
    std::string file;
    std::vector< std::vector<DefaultSoundEffect*>* > Sound;
    int increasingIdx;
    QTimer* timer;
    as4::model::TimeConfig timeConfig;
};

class DrumTrack : public DefaultTrack
{
public:
    DrumTrack();
    ~DrumTrack();
    virtual void setPath(as4::model::ISeq* seq);
    virtual void setVector();
};

#endif

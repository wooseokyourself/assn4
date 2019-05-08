#ifndef __AS4_TRACKS_H_
#define __AS4_TRACKS_H_

#include <iostream>
#include <fstream>
#include <string>

#include <QUrl>

#include "autostopsoundeffect.h"
#include "model/seq.h"
#include "model/song.h"

class DefaultTrack : QWidget
{
    Q_OBJECT
public:
    explicit DefaultTrack(QWidget *parent = nullptr);
    virtual ~DefaultTrack();
    virtual void setPath(as4::model::ISeq* seq);
    void setVector();

protected slots:
    void playUnit();

protected:
    std::string file;
    std::vector< std::vector<AutoStopSoundEffect*>* > Sound;
    int increasingIdx;
    QTimer* timer;
};

class DrumTrack : public DefaultTrack
{
public:
    DrumTrack();
    ~DrumTrack();
    virtual void setPath(as4::model::ISeq* seq);
};

#endif

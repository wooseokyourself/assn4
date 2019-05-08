#ifndef __AS4_TRACKS_H
#define __AS4_TRACKS_H

#include <iostream>
#include <fstream>
#include <string>

#include <QWidget>
#include <QUrl>
#include <QSoundEffect>
#include <QThread>

#include "model/seq.h"
#include "model/song.h"

class DefaultTrack // : public QWidget
{
    //Q_OBJECT
public:
    //explicit DefaultTrack(QWidget *parent = nullptr);
    DefaultTrack();
    virtual ~DefaultTrack();
    virtual void setPath(as4::model::ISeq* seq);
    void play();

protected:
    std::string file;
    std::vector< std::vector<QSoundEffect*>* > Sound;
};

class DrumTrack : public DefaultTrack
{
public:
    DrumTrack();
    virtual ~DrumTrack();
    virtual void setPath(as4::model::ISeq* seq);
};

#endif // DEFAULTTRACK_H

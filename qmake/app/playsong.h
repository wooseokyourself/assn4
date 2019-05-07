#ifndef __AS4_PLAYSONG_H_
#define __AS4_PLAYSONG_H_

#include <vector>
#include <QSoundEffect>
#include <QThread>
#include <fstream>
#include "model/song.h"
#include "model/time.h"
#include "io/songio.h"

using namespace as4::io;
using namespace as4::model;

class PlaySong
{
public:
    PlaySong();
    ~PlaySong();
    void SetAndPlay(Song* FullSong);
    void test();

protected: // 유틸리티함수
    void Play();


private:
    Song *Tracks;
    std::vector< std::vector<QSoundEffect*>* > AllTrackSounds;
};

#endif // PLAYSONG_H

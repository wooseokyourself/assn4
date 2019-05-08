#ifndef __AS4_PLAYSONG_H_
#define __AS4_PLAYSONG_H_

#include <vector>
#include <QSoundEffect>
#include <QThread>
#include <QTabWidget>
#include <fstream>
#include "model/song.h"
#include "model/time.h"
#include "io/songio.h"
#include "io/seqio.h"
#include "tracks.h"

using namespace as4::io::operators;
using namespace as4::model;
using namespace std;

class PlaySong
{
public:
    PlaySong();
    ~PlaySong();
    void SetAndPlay(Song* FullSong, QTabWidget* tabWidget);
    void test();

private:
    Song *Tracks;
    std::vector< std::vector<QSoundEffect*>* > AllTrackSounds;
};

#endif // PLAYSONG_H

#ifndef __AS4_PLAYSONG_H_
#define __AS4_PLAYSONG_H_

#include <QTabWidget>
#include <stack>
#include "io/songio.h"
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

private:
    stack<DefaultTrack*> TrackMemory;
    DefaultTrack* Track;
};

#endif

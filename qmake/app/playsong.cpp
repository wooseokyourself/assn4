#include "playsong.h"

PlaySong::PlaySong()
{

}

PlaySong::~PlaySong()
{
}

void PlaySong::SetAndPlay(Song* FullSong)
{
    Tracks = FullSong;
    std::ofstream fout("SongPath.txt");
    as4::io::operators::WritePathFile(fout, *Tracks);
    Play();
}

void PlaySong::Play()
{
    // 여기에서 재생
    std::ifstream fin("SongPath.txt");
    bool ExistNote[40] = {false};

    for(int i=0; i<40; i++){
        AllTrackSounds.push_back(nullptr);
        //std::cout<<" >> vector["<<i<<"] addr : "<<AllTrackSounds[i]<<std::endl;
    }

    while(!fin.eof()){
        float start, duration;
        std::string path;
        fin >> start;
        fin >> duration;
        fin >> path;
        int startIdx = start/0.5 - 1;


        QString qPath;
        qPath.fromStdString(path);
        QSoundEffect* wav_file = new QSoundEffect;
        wav_file->setSource(QUrl::fromLocalFile(qPath));
        wav_file->setLoopCount(2);
        wav_file->setVolume(0.5f);

        if(AllTrackSounds[startIdx] == nullptr){
            std::cout<<" >> nullptr : "<<AllTrackSounds[startIdx]<<std::endl;
            AllTrackSounds[startIdx] = new std::vector<QSoundEffect*>;
            std::cout<<" >> nowAddr : "<<AllTrackSounds[startIdx]<<std::endl;
        }
        std::cout<<" >> 2"<<std::endl;
        AllTrackSounds[startIdx]->push_back(wav_file);
        std::cout<<" >> 3"<<std::endl;
        if(fin.eof())
            break;
    }
    fin.close();

    for(int i=0; i<40; i++){
        QThread::msleep(250);
        if(AllTrackSounds[i] == nullptr)
            continue;
        else {
            for(int j=0; j<AllTrackSounds[i]->size(); j++){
                std::cout<<" >> AllTrackSounds["<<i<<"]->size : "<<AllTrackSounds[i]->size()<<std::endl;
                AllTrackSounds[i]->back()->play();
                std::cout<<" >> 여기에서 소리가 나야할텐데 말이죠.."<<std::endl;
                //AllTrackSounds[i]->pop_back();
            }
        }
    }

}

void PlaySong::test()
{
    std::ifstream fin("SongPath.txt");
    if(fin.is_open()){
        std::cout<<"파일열렸슴둥"<<std::endl;
        while(!fin.eof()){
            std::string line;
            fin >> line;
            std::cout<<" >> "<<line<<std::endl;
        }
    }
    else {
        std::cout<<"파일안열렸슴둥"<<std::endl;
    }
    fin.close();
}

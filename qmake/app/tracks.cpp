#include "tracks.h"

//DefaultTrack::DefaultTrack(QWidget *parent) : QWidget(parent)
DefaultTrack::DefaultTrack()
{

}

DefaultTrack::~DefaultTrack()
{
    for(int i=0; i<Sound.size(); i++){
        if(Sound[i] == nullptr)
            continue;
        Sound[i]->clear();
    }
    Sound.clear();
}

DrumTrack::DrumTrack() : DefaultTrack ()
{

}

DrumTrack::~DrumTrack()
{

}

void DefaultTrack::setPath(as4::model::ISeq *seq)
{
    file = "TrackResource.txt";
    std::ofstream out(file);
    for(int i=0; i<seq->getSize(); i++){
        out<<(*seq)[i]->GetStart()<<" "<<(*seq)[i]->GetDuration()
          <<" "<<":/audio/melody/audio/melody/"<<(*seq)[i]->GetPitch().GetPitchClass()
          <<"_"<<(*seq)[i]->GetPitch().GetOctave()<<".wav"<<std::endl;
    }
    out.close();
}

void DrumTrack::setPath(as4::model::ISeq *seq)
{
    file = "TrackResource.txt";
    std::ofstream out(file);
    for(int i=0; i<seq->getSize(); i++){
        out<<(*seq)[i]->GetStart()<<" "<<(*seq)[i]->GetDuration()
          <<" "<<":/audio/drum/audio/drum/"<<(*seq)[i]->GetPitch().GetPitchClass()
          <<"_"<<(*seq)[i]->GetPitch().GetOctave()<<".wav"<<std::endl;
    }
    out.close();
}

void DefaultTrack::play()
{
    for(int i=0; i<40; i++){
        Sound.push_back(nullptr);
    }

    int startIdx;
    float start, duration;
    std::string path;

    std::ifstream fin(file);
    while(!fin.eof()){
        fin >> start;
        fin >> duration;
        fin >> path;
        startIdx = start/0.5 - 1;

        if(Sound[startIdx] == nullptr){
            Sound[startIdx] = new std::vector<QSoundEffect*>;
        }

        QSoundEffect* wav_file;
        Sound[startIdx]->push_back(wav_file);
        Sound[startIdx]->back() = new QSoundEffect;
        Sound[startIdx]->back()->setSource(QUrl::fromUserInput(path.c_str()));
        Sound[startIdx]->back()->setLoopCount(QSoundEffect::Infinite);
        Sound[startIdx]->back()->setVolume(0.5f);

        // 이하 네줄 디버깅용
        QUrl url = Sound[startIdx]->back()->source();
        QString qst = url.toString();
        std::string reals = qst.toStdString();
        std::cout<<" >> 벡터 안에서 입력된 소스경로   : "<<reals<<std::endl;
    }
    fin.close();

    for(int i=0; i<40; i++){
        QThread::msleep(1000);
        if(Sound[i] == nullptr)
            continue;
        else {
            for(int j=0; j<Sound[i]->size(); j++){
                // 이하 4줄 디버깅용코드
                QUrl src = Sound[i]->operator[](j)->source();
                QString ssrc = src.toString();
                std::string real = ssrc.toStdString();
                std::cout<<" >> src : "<<real<<std::endl;

                Sound[i]->operator[](j)->play();

                if(Sound[i]->operator[](j)->isPlaying()){
                    std::cout<<" >> yes!"<<std::endl;
                }
                else{
                    std::cout<<" >> no!" <<std::endl;
                }
            }
        }
    }
    for(int i=0; i<Sound.size(); i++){
        if(Sound[i] == nullptr)
            continue;
        Sound[i]->clear();
    }
    Sound.clear();
}



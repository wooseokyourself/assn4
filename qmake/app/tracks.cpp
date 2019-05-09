#include "tracks.h"

DefaultTrack::DefaultTrack(QWidget *parent) : QWidget(parent), timeConfig(120, 4)
{
    timer = new QTimer(this);
}

//DrumTrack::DrumTrack(QWidget *parent) : QWidget(parent), DefaultTrack ()
DrumTrack::DrumTrack() : DefaultTrack ()
{

}


DefaultTrack::~DefaultTrack()
{
    std::cout<<" > DefaultTrack destructor!"<<std::endl;
    for(int i=0; i<Sound.size(); i++){
        if(Sound[i] == nullptr)
            continue;
        Sound[i]->clear();
    }
    Sound.clear();
    delete timer;
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

void DefaultTrack::setVector()
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
        if(fin.eof())
            break;
        if(Sound[startIdx] == nullptr){
            Sound[startIdx] = new std::vector<DefaultSoundEffect*>;
        }

        DefaultSoundEffect* wav_file;
        Sound[startIdx]->push_back(wav_file);
        Sound[startIdx]->back() = new AutoStopSoundEffect(timeConfig.miliSeconds(duration));
        Sound[startIdx]->back()->setSource(QUrl::fromUserInput(path.c_str()));
        Sound[startIdx]->back()->setVolume(0.5f);

        // 이하 네줄 디버깅용
        QUrl url = Sound[startIdx]->back()->source();
        QString qst = url.toString();
        std::string reals = qst.toStdString();
        std::cout<<" >> 벡터 안에서 입력된 소스경로   : "<<reals<<std::endl;
    }
    fin.close();

    play();
}

void DrumTrack::setVector()
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
        if(fin.eof())
            break;
        if(Sound[startIdx] == nullptr){
            Sound[startIdx] = new std::vector<DefaultSoundEffect*>;
        }


        DefaultSoundEffect* wav_file;
        Sound[startIdx]->push_back(wav_file);
        Sound[startIdx]->back() = new DefaultSoundEffect;
        Sound[startIdx]->back()->setSource(QUrl::fromUserInput(path.c_str()));
        Sound[startIdx]->back()->setVolume(0.5f);

        // 이하 네줄 디버깅용
        QUrl url = Sound[startIdx]->back()->source();
        QString qst = url.toString();
        std::string reals = qst.toStdString();
        std::cout<<" >> 벡터 안에서 입력된 소스경로   : "<<reals<<std::endl;
    }
    fin.close();

    play();
}

void DefaultTrack::play()
{
    //timer->setInterval(timeConfig.miliSeconds(2)); // 총 5비트 = 40유닛
    connect(timer, SIGNAL(timeout()), this, SLOT(playUnit()));

    increasingIdx = 0;
    timer->start(timeConfig.miliSeconds(1));
}

void DefaultTrack::playUnit()
{
    if(increasingIdx >= 40){ // 최대 벡터는 40
        std::cout<<" >> 벡터 idx 40 도달"<<std::endl;
        timer->stop();
        increasingIdx = 0;
        return;
    }

    if(Sound[increasingIdx] == nullptr){
        increasingIdx++;
        return;
    }
    for(int i=0; i<Sound[increasingIdx]->size(); i++){
        Sound[increasingIdx]->operator[](i)->play();
        if(Sound[increasingIdx]->operator[](i)->isPlaying())
            std::cout<<" >> play!"<<std::endl;
        else {
            std::cout<<" >> can't play"<<std::endl;
        }
    }
    std::cout<<" >> 현재 벡터 idx : "<<increasingIdx<<std::endl;
    increasingIdx++;
}

bool DefaultTrack::isPlay()
{
    return timer->isActive();
}


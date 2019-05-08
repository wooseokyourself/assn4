#include "tracks.h"

DefaultTrack::DefaultTrack(QWidget *parent) : QWidget(parent)
{

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

        if(Sound[startIdx] == nullptr){
            Sound[startIdx] = new std::vector<AutoStopSoundEffect*>;
        }

        AutoStopSoundEffect* wav_file;
        Sound[startIdx]->push_back(wav_file);
        Sound[startIdx]->back() = new AutoStopSoundEffect(duration);
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

    timer = new QTimer(this);
    timer->setInterval(5000);
    connect(timer, SIGNAL(timeout()), this, SLOT(playUnit()));

    increasingIdx = 0;
    timer->start(125);
    if(timer->isActive()){
        std::cout<<" >> 시계가 동작한다네"<<std::endl;
    }
    else {
        std::cout<<" >> 시계가 멈춰있다네"<<std::endl;
    }

}

void DefaultTrack::playUnit()
{
    if(Sound[increasingIdx] == nullptr){
        increasingIdx++;
        return;
    }
    for(int i=0; i<Sound[increasingIdx]->size(); i++){
        Sound[increasingIdx]->operator[](i)->play();
        if(Sound[increasingIdx]->operator[](i)->isPlaying())
            std::cout<<" >> Yes!"<<std::endl;
        else {
            std::cout<<" >> No.."<<std::endl;
        }
    }
    increasingIdx++;
}



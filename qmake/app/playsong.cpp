#include "playsong.h"

PlaySong::PlaySong()
{

}

PlaySong::~PlaySong()
{
    while(!TrackMemory.empty()){
        delete TrackMemory.top();
        TrackMemory.pop();
    }
    delete Track;
}

void PlaySong::SetAndPlay(Song* FullSong, QTabWidget* tabWidget)
{
    // 여기에서 파일의 [melody], [drum] 을 구분하여 해당 트랙 객체 생성.
    // 이후 그 트랙 객체 메소드를 통해 filepath를 쓰는 것부터, 곡 재생까지 진행.
    // 재생을 완료하였으면 트랙 객체 삭제후 이 함수 리턴
    std::cout<<" >> PLAY BUTTON click!"<<std::endl;
    if(!TrackMemory.empty()){
        if(TrackMemory.top()->isPlay()){
            std::cout<<" >> 이미 재생중입니다."<<std::endl;
            return;
        }
    }

    while(!TrackMemory.empty()){
        delete TrackMemory.top();
        TrackMemory.pop();
    }

    if(tabWidget->currentIndex() == 0){
        Track = new DefaultTrack;
        Track->setPath(FullSong->GetMelodySeq());
    }
    else if(tabWidget->currentIndex() == 1){
        Track = new DrumTrack;
        Track->setPath(FullSong->GetDrumSeq());
    }
    else{
        std::cout<<" >> Invalid track."<<std::endl;
        return;
    }
    Track->setVector();
    TrackMemory.push(Track);

    cout<<" >> SetAndPlay() exit!"<<endl;
}

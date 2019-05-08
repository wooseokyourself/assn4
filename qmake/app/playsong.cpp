#include "playsong.h"


#include <QUrl>

PlaySong::PlaySong()
{

}

PlaySong::~PlaySong()
{
    delete Track;
}

void PlaySong::SetAndPlay(Song* FullSong, QTabWidget* tabWidget)
{
    // 여기에서 파일의 [melody], [drum] 을 구분하여 해당 트랙 객체 생성.
    // 이후 그 트랙 객체 메소드를 통해 filepath를 쓰는 것부터, 곡 재생까지 진행.
    // 재생을 완료하였으면 트랙 객체 삭제후 이 함수 리턴

    if(tabWidget->currentIndex() == 0){
        Track = new DefaultTrack;
        Track->setPath(FullSong->GetMelodySeq());
    }
    else if(tabWidget->currentIndex() == 1){
        Track = new DrumTrack;
        Track->setPath(FullSong->GetDrumSeq());
    }
    else{
        std::cout<<" >> Invalid track. Choice the tab widget."<<std::endl;
        return;
    }
    Track->setVector();


    cout<<" >> SetAndPlay() exit!"<<endl;
}





void PlaySong::test()
{
    std::ifstream fin("SongPath.txt");
    if(fin.is_open()){
        std::cout<<" >> file open"<<std::endl;
        while(!fin.eof()){
            std::string line;
            fin >> line;
            std::cout<<" >> "<<line<<std::endl;
        }
    }
    else {
        std::cout<<" >> file not open"<<std::endl;
    }
    fin.close();
}

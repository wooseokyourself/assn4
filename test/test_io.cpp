/** Test codes for model */

#include <QtTest/QtTest>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "io/seqio.h"
#include "io/songio.h"

using namespace as4::model;
using namespace as4::io;

class TestIo : public QObject
{
    Q_OBJECT
private slots:
    void ReadWriteSeq();
    void ReadWriteSong();
};

///////////////////////////////////////////////////////////////////////////
/// Problem 1-2) Make this test pass
///////////////////////////////////////////////////////////////////////////
void TestIo::ReadWriteSeq()
{
    ISeq *seq1 = new DefaultSeq;
    // ( start , duration, {Pitch , Octave} )
    seq1->Put({100, 10, {0, 1}}); // C1 start:duration 100:10
    seq1->Put({0, 10, {0, 1}}); // 0:10, C1
    seq1->Put({10, 10, {2, 1}}); // 10:10, D1
    seq1->Put({10, 20, {5, 1}}); // 10:20, F1

    // temporary output file
    std::string tmp_file_path = "TestIoReadWriteSeq.seq";

    // 파일 쓰기 (프로그램 -> 파일)
    {
        using namespace as4::io::operators;
        std::ofstream fout(tmp_file_path);
        fout << *seq1;
    }

    ISeq *seq2 = new DefaultSeq;
    // 파일 읽기 (파일 -> 프로그램)
    {
        using namespace as4::io::operators;
        std::ifstream fin(tmp_file_path);
        fin >> *seq2;
    }

    /*cout<<" >> seq1 size : "<<seq1->getSize()<<endl;
    cout<<" >> seq2 size : "<<seq2->getSize()<<endl;
    int size;
    if(seq1->getSize()!=seq2->getSize()){
        cout<<" >> 두 seq에 저장된 원소의 수가 다릅니다!"<<endl;
    }
    else{
        size = seq1->getSize();
        for(int i=0; i<size; i++){
            cout<<" >> ["<<i<<"] 번 째 seq 인덱스 비교 (seq1 / seq2)"<<endl;
            cout<<seq1->operator[](i)->GetStart()<<" / "<<seq2->operator[](i)->GetStart()<<endl;
            cout<<seq1->operator[](i)->GetDuration()<<" / "<<seq2->operator[](i)->GetDuration()<<endl;
            cout<<seq1->operator[](i)->GetPitch().GetPitchClass()<<" / "<<seq2->operator[](i)->GetPitch().GetPitchClass()<<endl;
            cout<<seq1->operator[](i)->GetPitch().GetOctave()<<" / "<<seq2->operator[](i)->GetPitch().GetOctave()<<endl;
        }
    }*/

    /*cout<<" >> 시퀀스파일 내용보기"<<endl;
    char inputString[1000];
    std::ifstream fff(tmp_file_path);
    while(!fff.eof()){
        fff.getline(inputString, 100);
        cout<<inputString<<endl;
    }
    fff.close();
    */

    QCOMPARE(*seq1, *seq2);
    // QCOMPARE(actual, expected);
    // 여기 QCOMPARE은 seq1, seq2의 주소값을 비교하는 게 아니라, 안의 내용을 비교해야함
}

void TestIo::ReadWriteSong()
{
    Song song;

    song.GetMelodySeq()->Put({100, 10, {0, 1}}); // C1 start:duration 100:10 >> 200유닛에서 play
    song.GetMelodySeq()->Put({0, 10, {0, 1}}); // C1 0:10 >> 2유닛에서 play
    song.GetMelodySeq()->Put({10, 10, {2, 1}}); // D1 10:10 >> 20유닛에서 play
    song.GetMelodySeq()->Put({10, 20, {5, 1}}); // F1 10:20 >> 20유닛에서 play

    song.GetDrumSeq()->Put({90, 10, {0, 1}}); // C1 start:duration 100:10
    song.GetDrumSeq()->Put({10, 10, {0, 1}}); // C1 0:10
    song.GetDrumSeq()->Put({10, 10, {2, 1}}); // D1 10:10
    song.GetDrumSeq()->Put({10, 20, {5, 1}}); // F1 10:20

    // temporary output file
    std::string tmp_file_path = "TestIoReadWriteSong.song";
    {
        using namespace as4::io::operators;
        std::ofstream fout(tmp_file_path);
        fout << song;
    }

    Song song_recon;

    {
        using namespace as4::io::operators;
        std::ifstream fin(tmp_file_path);
        fin >> song_recon;
    }

    /*cout<<" >> 송 파일 내용보기"<<endl;
    char inputString[100];
    std::ifstream fff(tmp_file_path);
    while(!fff.eof()){
        fff.getline(inputString, 100);
        cout<<inputString<<endl;
    }
    fff.close();
    */

    // cout<<" >> Melody 시퀀스 비교"<<endl;
    QCOMPARE(*song.GetMelodySeq(), *song_recon.GetMelodySeq());
    // cout<<" >> Drum 시퀀스 비교"<<endl;
    QCOMPARE(*song.GetDrumSeq(), *song_recon.GetDrumSeq());

}

QTEST_MAIN(TestIo)
#include "test_io.moc"

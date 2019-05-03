#include "io/songio.h"
#include "io/seqio.h"
#include <iostream>
using namespace std;

namespace as4::io
{
    namespace operators
    {
        /* Put your code here */
        std::ofstream& operator<< (std::ofstream& out, as4::model::Song& song)
        {
            //out << *song.GetMelodySeq() << *song.GetDrumSeq() 시행시 제한사항때문에 song에 대한 operator를 따로 구현
            out << "[Melody]" << endl;
            for(int i=0; i<song.GetMelodySeq()->getSize(); i++){
                out << (*song.GetMelodySeq())[i]->GetStart();
                out << " ";
                out << (*song.GetMelodySeq())[i]->GetDuration();
                out << " ";
                out << (*song.GetMelodySeq())[i]->GetPitch().GetPitchClass();
                out << " ";
                out << (*song.GetMelodySeq())[i]->GetPitch().GetOctave();
                out << std::endl;
            }

            out << "[Drum]" << endl;
            for(int i=0; i<song.GetDrumSeq()->getSize(); i++){
                out << (*song.GetDrumSeq())[i]->GetStart();
                out << " ";
                out << (*song.GetDrumSeq())[i]->GetDuration();
                out << " ";
                out << (*song.GetDrumSeq())[i]->GetPitch().GetPitchClass();
                out << " ";
                out << (*song.GetDrumSeq())[i]->GetPitch().GetOctave();
                out << std::endl;
            }
            out.close();
            return out;
        }

        std::ifstream& operator>> (std::ifstream& in, as4::model::Song& song)
        {
            //in >> *song.GetMelodySeq() >> *song.GetDrumSeq() 시행시 제한사항때문에 song에 대한 operator를 따로 구현
            std::string flag;
            in >> flag;
            if(flag != "[Melody]"){
                cout<<" >> 이거 파일이 잘못됐는데요?"<<endl;
                return in;
            }
            else{
                while(!in.eof()){

                    in >> flag; // = tempStart
                    if(flag == "[Drum]"){
                        // cout<<" >> "<<flag<<"이 감지되어 Melody 입력 종료"<<endl;
                        break;
                    }
                    as4::model::Timestamp tempStart = stoull(flag, 0, 10);
                    //cout<<"flag -> tempStart : "<<tempStart<<endl;

                    as4::model::TimeInterval tempInterval;
                    in >> tempInterval;

                    int tempPitch, tempOctave;
                    in >> tempPitch;
                    in >> tempOctave;
                    as4::model::Pitch tempP(tempPitch, tempOctave);
                    as4::model::Note tempNote(tempStart, tempInterval, tempP);
                    song.GetMelodySeq()->Put(tempNote);
                }
                //cout<<" >> "<<flag<<" 입력시작! "<<endl;
                while(!in.eof()){

                    as4::model::Timestamp tempStart;
                    as4::model::TimeInterval tempInterval;

                    in >> tempStart;
                    in >> tempInterval;

                    int tempPitch, tempOctave;
                    in >> tempPitch;
                    in >> tempOctave;
                    as4::model::Pitch tempP(tempPitch, tempOctave);

                    as4::model::Note tempNote(tempStart, tempInterval, tempP);

                    song.GetDrumSeq()->Put(tempNote);
                }
                song.GetDrumSeq()->PopBack();
            }
            in.close();
            return in;
        }
    }
}

#include "io/seqio.h"

#include <iostream>
using namespace std;

namespace as4::io
{
    namespace operators
    {
        /* Put your code here */
        std::ofstream& operator<< (std::ofstream& out, as4::model::ISeq& seq)
        {
            for(int i=0; i<seq.getSize(); i++){
                out << seq[i]->GetStart();
                out << " ";
                out << seq[i]->GetDuration();
                out << " ";
                out << seq[i]->GetPitch().GetPitchClass();
                out << " ";
                out << seq[i]->GetPitch().GetOctave();
                out << std::endl;
            }
            out.close();
            return out;
        }

        std::ifstream& operator>> (std::ifstream& in, as4::model::ISeq& seq)
        {
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

                seq.Put(tempNote);
            }
            seq.PopBack();
            in.close();
            return in;
        }
    }
}

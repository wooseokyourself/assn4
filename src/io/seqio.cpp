#include "io/seqio.h"

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
            return out;
        }

        std::ifstream& operator>> (std::ifstream& in, as4::model::ISeq& seq)
        {
            int i=0;
            while(!in.eof()){
                as4::model::Timestamp tempStart;
                as4::model::TimeInterval tempInterval;

                in >> tempStart;
                seq[i]->SetStart(tempStart);
                in >> tempInterval;
                seq[i]->SetDuration(tempInterval);

                int tempPitch, tempOctave;
                in >> tempPitch;
                in >> tempOctave;

                as4::model::Pitch tempP(tempPitch, tempOctave);

                seq[i]->SetPitch(tempP);

                i++;
            }
            return in;
        }
    }
}

#include "io/songio.h"

namespace as4::io
{
    namespace operators
    {
        /* Put your code here */
        std::ofstream& operator<< (std::ofstream& out, as4::model::Song& song)
        {
            out << song.GetMelodySeq();
            out << song.GetDrumSeq();
            return out;
        }

        std::ifstream& operator>> (std::ifstream& in, as4::model::Song& song)
        {/*
            as4::model::DefaultSeq *tempMelody = song.GetMelodySeq();
            in >> tempMelody;
            // in >> DefaultSeq* seq;
            in >> song.GetDrumSeq();
            return in;
        */}
    }
}

#ifndef __AS4_SONGIO_H
#define __AS4_SONGIO_H

#include <istream>
#include <ostream>
#include <fstream>

#include "model/song.h"

namespace as4::io
{
    namespace operators
    {
        /* Put your code here */
        std::ofstream& operator<< (std::ofstream& out, as4::model::Song& song);

        std::ifstream& operator>> (std::ifstream& in, as4::model::Song& song);
    }
}

#endif

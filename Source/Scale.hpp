//
//  Scale.hpp
//  MusicTheory
//
//  Created by Cem Olcay on 27.01.2018.
//

#ifndef Scale_hpp
#define Scale_hpp

#include <stdio.h>
#include <vector>
#include "MusicTheory.hpp"

namespace MusicTheory {

  class Scale {
  public:
    Scale(Interval* intervals);
    std::vector<Interval> intervals;
    std::vector<Note> getNotes(NoteType key, int octave);

    const static Scale major;
    const static Scale minor;
  };

}

#endif /* Scale_hpp */

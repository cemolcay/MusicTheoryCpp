//
//  MusicTheory.hpp
//  MusicTheory
//
//  Created by Cem Olcay on 17.01.2018.
//  Copyright © 2018 cemolcay. All rights reserved.
//

#ifndef MusicTheory_hpp
#define MusicTheory_hpp

#include <stdio.h>

namespace MusicTheory {

  enum NoteType {
    C,
    DFlat,
    D,
    EFlat,
    E,
    F,
    GFlat,
    G,
    AFlat,
    A,
    BFlat,
    B
  };

  class Note {
  public:
    Note(int midiNoteNumber);
    Note(NoteType noteType, int octave);
    ~Note();

    int getMIDINoteNumber();
    int getPianoKeyIndex();
    double getFrequency(double base = 440.0);
    
    NoteType type;
    int octave;
  };

  struct Interval {
    int halfsteps;
  };

  static Interval unison = {0};
}

#endif /* MusicTheory_hpp */

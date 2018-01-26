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

  struct Interval {
    Interval(int halfsteps);
    int halfsteps;

    bool operator==(const Interval &lhs) const;
    Interval operator+(const Interval &lhs) const;
    Interval operator-(const Interval &lhs) const;

    const static Interval P1; // Unison
    const static Interval m2; // Minor Second
    const static Interval M2; // Major Second
    const static Interval m3; // Minor Third
    const static Interval M3; // Major Third
    const static Interval P4; // Perfect Fourth
    const static Interval d5; // Tritone
    const static Interval P5; // Perfect Fifth
    const static Interval m6; // Minor Sixth
    const static Interval M6; // Major Sixth
    const static Interval m7; // Minor Seventh
    const static Interval M7; // Major Seventh
    const static Interval P8; // Octave
  };
  
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

    bool operator==(Note &lhs);
    Note operator+(const Interval &lhs);
    Note operator-(const Interval &lhs);
    Note operator+(const int &lhs);
    Note operator-(const int &lhs);
  };
}

#endif /* MusicTheory_hpp */

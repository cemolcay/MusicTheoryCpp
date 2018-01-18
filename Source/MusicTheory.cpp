//
//  MusicTheory.cpp
//  MusicTheoryCpp
//
//  Created by Cem Olcay on 17.01.2018.
//  Copyright © 2018 cemolcay. All rights reserved.
//

#include "MusicTheory.hpp"
#include <math.h>

namespace MusicTheory {

  // MARK: Note

  Note::~Note() {}

  Note::Note(int midiNoteNumber) {
    octave = (midiNoteNumber / 12) - (midiNoteNumber < 0 ? 1 : 0);
    type = NoteType(octave > 0 ?
                    (midiNoteNumber - (octave * 12)) :
                    (midiNoteNumber - ((octave + 1) * 12) + 12));
  }

  Note::Note(NoteType noteType, int octave) {
    type = noteType;
    this->octave = octave;
  }
  
  int Note::getMIDINoteNumber() {
    return type + (octave * 12);
  }

  int Note::getPianoKeyIndex() {
    return getMIDINoteNumber() + 4;
  }

  double Note::getFrequency(double base) {
    int pianoKey = getPianoKeyIndex();
    double fn = powf(2.0, float(pianoKey - 49) / 12.0);
    return fn * base;
  }
}

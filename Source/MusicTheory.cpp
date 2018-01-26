//
//  MusicTheory.cpp
//  MusicTheory
//
//  Created by Cem Olcay on 17.01.2018.
//  Copyright © 2018 cemolcay. All rights reserved.
//

#include "MusicTheory.hpp"
#include <math.h>

namespace MusicTheory {

  // MARK: - Interval

  Interval::Interval(int halfsteps) : halfsteps(halfsteps) {}

  bool Interval::operator==(const Interval &lhs) const {
    return halfsteps == lhs.halfsteps;
  }

  Interval Interval::operator+(const Interval &lhs) const {
    return Interval{halfsteps + lhs.halfsteps};
  }

  Interval Interval::operator-(const Interval &lhs) const {
    return Interval{halfsteps - lhs.halfsteps};
  }

  // MARK: - Note

  Note::~Note() {}

  Note::Note(int midiNoteNumber) {
    octave = (midiNoteNumber / 12) - 1;
    type = NoteType(midiNoteNumber - ((octave + 1) * 12));
  }

  Note::Note(NoteType noteType, int octave) {
    type = noteType;
    this->octave = octave;
  }
  
  int Note::getMIDINoteNumber() {
    return type + ((octave + 1) * 12);
  }

  double Note::getFrequency(double base) {
    double fn = powf(2.0, float(getMIDINoteNumber() - 69) / 12.0);
    return fn * base;
  }

  bool Note::operator==(Note &lhs) {
    return getMIDINoteNumber() == lhs.getMIDINoteNumber();
  }

  Note Note::operator+(const MusicTheory::Interval &lhs) {
    return Note(getMIDINoteNumber() + lhs.halfsteps);
  }

  Note Note::operator-(const MusicTheory::Interval &lhs) {
    return Note(getMIDINoteNumber() - lhs.halfsteps);
  }

  Note Note::operator+(const int &lhs) {
    return Note(getMIDINoteNumber() + lhs);
  }

  Note Note::operator-(const int &lhs) {
    return Note(getMIDINoteNumber() - lhs);
  }
}

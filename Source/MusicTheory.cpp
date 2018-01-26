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

  const Interval Interval::P1 = {0};
  const Interval Interval::m2 = {1};
  const Interval Interval::M2 = {2};
  const Interval Interval::m3 = {3};
  const Interval Interval::M3 = {4};
  const Interval Interval::P4 = {5};
  const Interval Interval::d5 = {6};
  const Interval Interval::P5 = {7};
  const Interval Interval::m6 = {8};
  const Interval Interval::M6 = {9};
  const Interval Interval::m7 = {10};
  const Interval Interval::M7 = {11};
  const Interval Interval::P8 = {12};

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

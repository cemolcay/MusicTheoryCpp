//
//  Scale.cpp
//  MusicTheory
//
//  Created by Cem Olcay on 27.01.2018.
//

#include "Scale.hpp"

namespace MusicTheory {

  Scale::Scale(Interval* intervals) {
    int length = sizeof(intervals)/sizeof(intervals[0]);
    this->intervals.assign(intervals, intervals + length);
  }

  std::vector<Note> Scale::getNotes(NoteType key, int octave) {
    std::vector<Note> notes;
    notes.reserve(this->intervals.size());

    Note root = Note(key, octave);
    for (int i = 0; i < this->intervals.size(); i++) {
      Interval current = this->intervals[i];
      notes.push_back(root + current);
    }

    return notes;
  }

  Interval majorIntervals[] = {Interval::P1, Interval::M2, Interval::M3, Interval::P4, Interval::P5, Interval::M6, Interval::M7};
  const Scale Scale::major = Scale(majorIntervals);
  Interval minorIntervals[] = {Interval::P1, Interval::M2, Interval::m3, Interval::P4, Interval::P5, Interval::m6, Interval::m7};
  const Scale Scale::minor = Scale(minorIntervals);
}

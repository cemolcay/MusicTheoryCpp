//
//  Tests.m
//  Tests
//
//  Created by Cem Olcay on 17.01.2018.
//  Copyright © 2018 cemolcay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XCTest/XCTest.h>
#include "MusicTheory.hpp"
#include "Scale.hpp"
#include <vector>

using namespace MusicTheory;

@interface Tests : XCTestCase

@end

@implementation Tests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testNote {
  NoteType a = A;
  Note a4 = Note(a, 4);
  XCTAssertEqual(a4.octave, 4);
  XCTAssertEqual(a4.type, A);
  XCTAssertEqual(a4.getFrequency(), 440.0);
  XCTAssertEqual(a4.getMIDINoteNumber(), 69);
  
  Note c4 = Note(60);
  XCTAssertEqual(c4.octave, 4);
  XCTAssertEqual(c4.type, C);
  XCTAssertEqual(c4.getMIDINoteNumber(), 60);

  Note c0 = Note(0);
  XCTAssertEqual(c0.octave, -1);
  XCTAssertEqual(c0.type, C);
  XCTAssertEqual(c0.getMIDINoteNumber(), 0);

  Interval M2 = {2};
  Note b4 = a4 + 2;
}

- (void)testInterval {
  XCTAssert(Interval::P1 + 1 == Interval::m2);
  XCTAssert(Interval::m2 - 1 == Interval::P1);
}

- (void)testScales {
  Note cmajor[] = { Note(C, 1), Note(D, 1), Note(E, 1), Note(F, 1), Note(G, 1), Note(A, 1), Note(B, 1) };

  Scale major = Scale::major;
  Interval majorIntervals[] = {Interval::P1, Interval::M2, Interval::M3, Interval::P4, Interval::P5, Interval::M6, Interval::M7};
  for (int i = 0; i < 7; i++) {
    XCTAssertEqual(major.intervals[i].halfsteps, majorIntervals[i].halfsteps);
  }

  std::vector<Note> cmajorNotes = major.getNotes(C, 1);
  for (int i = 0; i < 7; i++) {
    XCTAssertEqual(cmajor[i].getMIDINoteNumber(), cmajorNotes[i].getMIDINoteNumber());
  }
}

@end

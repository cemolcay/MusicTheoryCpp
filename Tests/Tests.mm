//
//  Tests.m
//  Tests
//
//  Created by Cem Olcay on 17.01.2018.
//  Copyright © 2018 cemolcay. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "MusicTheory.hpp"

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
  Note a4 = Note(a, 3);
  XCTAssertEqual(a4.getFrequency(), 440.0);
  XCTAssertEqual(a4.getMIDINoteNumber(), 45);
  
  a4 = Note(45);
  XCTAssertEqual(a4.getMIDINoteNumber(), 45);
}

@end

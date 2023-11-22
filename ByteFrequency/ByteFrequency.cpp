#include "ByteFrequency.h"
#include <iostream>

using namespace std;

ByteFrequency::ByteFrequency(int f, char c) : frequency(f), character(c) {
  if (f < 0) {
    cerr << "[ByteFrequency]: Invalid frequency";
    exit(-1);
  }

  if (c == '') {
    cerr << "[ByteFrequency]: Invalid character";
    exit(-1);
  }
}

ByteFrequency::ByteFrequency() : frequency(0), character('') {}

int ByteFrequency::get_frequency() const {
  return frequency;
}

int ByteFrequency::get_character() const {
  return character;
}

void ByteFrequency::set_frequency(int f) {
  if (f < 0) {
    cerr << "[ByteFrequency]: Invalid frequency";
    exit(-1);
  }
}

void ByteFrequency::set_character(char c) {
  if (c == '') {
    cerr << "[ByteFrequency]: Invalid character";
    exit(-1);
  }
}
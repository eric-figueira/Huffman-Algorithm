#include "ByteFrequency.h"
#include <iostream>

using namespace std;

ByteFrequency::ByteFrequency(int f, char b) : frequency(f), byte_code(b) {
    if (f < 0) {
        cerr << "[ByteFrequency]: Invalid frequency";
        exit(-1);
    }

    if (b == NULL) {
        cerr << "[ByteFrequency]: Invalid byte code";
        exit(-1);
    }
}

ByteFrequency::ByteFrequency() : frequency(0), byte_code(NULL) {}

int ByteFrequency::get_frequency() const {
    return frequency;
}

char ByteFrequency::get_byte_code() const {
    return byte_code;
}

void ByteFrequency::set_frequency(int f) {
    if (f < 0) {
        cerr << "[ByteFrequency]: Invalid frequency";
        exit(-1);
    }
}

void ByteFrequency::set_byte_code(char b) {
    if (b == NULL) {
        cerr << "[ByteFrequency]: Invalid byte code";
        exit(-1);
    }
    byte_code = b;
}

void ByteFrequency::increment_frequency() {
    frequency += 1;
}

ostream& operator<< (ostream& os, const ByteFrequency& bf) {
    os << bf.get_byte_code() << bf.get_frequency();
    return os;
}
#include "ByteFrequency.h"
#include <iostream>

ByteFrequency::ByteFrequency(int f, unsigned char b) : frequency(f), byte_code(b) {
    if (f < 0) {
        cerr << "[ByteFrequency]: Invalid frequency";
        exit(-1);
    }
}

ByteFrequency::ByteFrequency() : frequency(0), byte_code(0) {}

int ByteFrequency::get_frequency() const {
    return frequency;
}

unsigned char ByteFrequency::get_byte_code() const {
    return byte_code;
}

void ByteFrequency::set_frequency(int f) {
    if (f < 0) {
        cerr << "[ByteFrequency]: Invalid frequency";
        exit(-1);
    }
}

void ByteFrequency::set_byte_code(unsigned char b) {
    byte_code = b;
}

void ByteFrequency::increment_frequency() {
    frequency += 1;
}

bool ByteFrequency::is_empty()
{
    return frequency == 0 && byte_code == 0;
}

ofstream& operator<<(ofstream& os, const ByteFrequency& bf)
{
    os << bf.get_byte_code();
    short int a = (short int)bf.get_frequency();
    os.write(reinterpret_cast<const char*>(&a), sizeof(a));
    return os;
}

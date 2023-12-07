#include <iostream>

#include "ByteFrequency.h"
#include "Types.h"

ByteFrequency::ByteFrequency(unsigned long long f, byte b) : frequency(f), byte_code(b) {
    if (f < 0) {
        cerr << "[ByteFrequency]: Invalid frequency";
        exit(-1);
    }
}

ByteFrequency::ByteFrequency() : frequency(0), byte_code(0) {}

unsigned long long ByteFrequency::get_frequency() const {
    return frequency;
}

byte ByteFrequency::get_byte_code() const { return byte_code; }

void ByteFrequency::set_frequency(unsigned long long f) {
    if (f < 0) {
        cerr << "[ByteFrequency]: Invalid frequency";
        exit(-1);
    }
}

void ByteFrequency::set_byte_code(byte b) { byte_code = b; }

void ByteFrequency::increment_frequency() { frequency += 1; }

bool ByteFrequency::is_empty() { return frequency == 0; }

ofstream& operator<<(ofstream& os, const ByteFrequency& bf)
{
    os << bf.get_byte_code();
    unsigned long long f = bf.get_frequency();
    os.write(reinterpret_cast<const char*>(&f), sizeof(f));
    return os;
}

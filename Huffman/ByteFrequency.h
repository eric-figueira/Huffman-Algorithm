#ifndef BYTEFREQUENCY
#define BYTEFREQUENCY

#include <iostream>
#include <fstream>

#include "Types.h"

using namespace std;

class ByteFrequency
{
    private:
        unsigned long long frequency;
        byte byte_code;

    public:
        unsigned long long get_frequency() const;
        byte get_byte_code() const;

        void set_frequency(unsigned long long f);
        void set_byte_code(byte b);
        void increment_frequency();

        bool is_empty();

        ByteFrequency(unsigned long long f, byte b);
        ByteFrequency();

        friend ofstream& operator<< (ofstream& os, const ByteFrequency& bf);
};

#endif
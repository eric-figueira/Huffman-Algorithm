#ifndef BYTEFREQUENCY
#define BYTEFREQUENCY

#include <iostream>
#include <fstream>

#include "Types.h"

using namespace std;

class ByteFrequency
{
    private:
        short int  frequency;
        byte byte_code;

    public:
        short int  get_frequency() const;
        byte get_byte_code() const;

        void set_frequency(int f);
        void set_byte_code(byte b);
        void increment_frequency();

        bool is_empty();

        ByteFrequency(int f, byte b);
        ByteFrequency();

        friend ofstream& operator<< (ofstream& os, const ByteFrequency& bf);
};

#endif
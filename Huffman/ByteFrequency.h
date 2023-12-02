#ifndef BYTEFREQUENCY
#define BYTEFREQUENCY

#include <iostream>
#include <fstream>


using namespace std;

class ByteFrequency
{
    private:
        short int  frequency;
        unsigned char byte_code;

    public:
        short int  get_frequency() const;
        unsigned char get_byte_code() const;

        void set_frequency(int f);
        void set_byte_code(unsigned char b);
        void increment_frequency();

        bool is_empty();

        ByteFrequency(int f, unsigned char b);
        ByteFrequency();

        friend ofstream& operator<< (ofstream& os, const ByteFrequency& bf);
};

#endif
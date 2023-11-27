#ifndef BYTEFREQUENCY
#define BYTEFREQUENCY

#include <iostream>
#include <fstream>

using namespace std;

class ByteFrequency
{
private:
    int  frequency;
    char byte_code;

public:
    int  get_frequency() const;
    char get_byte_code() const;

    void set_frequency(int f);
    void set_byte_code(char b);
    void increment_frequency();

    ByteFrequency(int f, char b);
    ByteFrequency();

    friend ofstream& operator<< (ofstream& os, const ByteFrequency& bf);
};

#endif
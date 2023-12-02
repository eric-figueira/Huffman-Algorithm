#ifndef CODE
#define CODE

#include <iostream>
#include <fstream>

#include "LinkedList.h"
#include "Types.h"


using namespace std;

class Code
{
    private:
        LinkedList bytes;
        unsigned int number_of_used_bits;
        void set_bit(unsigned short int n);
        void clear_bit(unsigned short int n);

    public:
        Code();

        LinkedList get_bytes() const;
        unsigned int get_number_of_used_bits() const;

        void add_bit(bool bit);
        bool get_bit(unsigned int n);

        void add_bits(bool* bits, unsigned int num_bits);

        void add_byte(byte byte, unsigned int num_bits);
        byte get_byte(unsigned int n);

        friend ofstream& operator<< (ofstream& os, const Code& code);
};

#endif
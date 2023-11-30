#include "Code.h"

void Code::set_bit(unsigned int pos, unsigned short int n)
{
    if (n == 0)
        bytes.push(0);
    bytes.set(pos, bytes.get(pos) | (1 << n));
}

void Code::clear_bit(unsigned int pos, unsigned short int n)
{
    if (n == 0)
        bytes.push(0);
    bytes.set(pos, bytes.get(pos) & ~(1 << n));
}

Code::Code() : bytes(), number_of_used_bits(0) {};

LinkedList Code::get_bytes() const
{
    return bytes;
}

unsigned int Code::get_number_of_used_bits() const
{
    return number_of_used_bits;
}

void Code::add_bit(bool bit)
{
    unsigned int pos = (unsigned int)(number_of_used_bits / 8);
    unsigned int mod = number_of_used_bits % 8;

    if (bit)
        set_bit(pos, mod);
    else
        clear_bit(pos, mod);

    number_of_used_bits++;
}

bool Code::get_bit(unsigned int n)
{
    unsigned int pos = (unsigned int)(n / 8);
    unsigned int mod = n % 8;

    return bytes.get(pos) & (1 << mod);
}

void Code::add_bits(bool* bits, unsigned int num_bits)
{
    for (unsigned int i = 0; i < num_bits; i++)
    {
        add_bit(bits[i]);
    }
}

void Code::add_byte(char byte, unsigned int num_bits)
{
    unsigned int n = (unsigned int)(number_of_used_bits / 8);
    bytes.set(n, byte);
    number_of_used_bits += num_bits;
}

char Code::get_byte(unsigned int n)
{
    return bytes.get(n);
}

ofstream& operator<<(ofstream& os, const Code& code)
{
    LinkedList list = code.get_bytes();
    os << list;
    return os;
}

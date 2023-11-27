#include "Code.h"

void Code::set_bit(unsigned int pos, char n)
{
    bytes.set(pos, bytes.get(pos) | (1 << n));
}

void Code::clear_bit(unsigned int pos, char n)
{
    bytes.set(pos, bytes.get(pos) & ~(1 << n));
}

Code::Code() : bytes(), number_of_used_bits(0) {};

LinkedList<char> Code::get_bytes() const
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
        set_bit(pos, (char)(7 - mod));
    else
        clear_bit(pos, (char)(7 - mod));

    number_of_used_bits++;
}

bool Code::get_bit(unsigned int n) const
{
    unsigned int pos = (unsigned int)(n / 8);
    unsigned int mod = n % 8;

    return bytes.get(pos) & (1 << (7 - mod));
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

char Code::get_byte(unsigned int n) const
{
    return bytes.get(n);
}

ofstream& operator<<(ofstream& os, const Code& code)
{
    LinkedList<char> list = code.get_bytes();
    list.set_current(list.get_begin());
    while (list.get_current() != nullptr)
    {
        list.set_current(list.get_current()->get_next());
        os << list.get_current()->get_data();
    }
    return os;
}

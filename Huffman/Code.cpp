#include "Code.h"
#include "Types.h"

void Code::set_bit(unsigned short int n)
{
    if (n == 0)
        bytes.push(unsigned char(0));
    ListNode* end = bytes.get_end();
    end->set_data(end->get_data() | (unsigned char(1) << (7 - n)));
}

void Code::clear_bit(unsigned short int n)
{
    if (n == 0)
        bytes.push(unsigned char(0));
    ListNode* end = bytes.get_end();
    end->set_data(end->get_data() & ~(unsigned char(1) << (7 - n)));
}

Code::Code() : bytes(LinkedList()), number_of_used_bits(0) {};

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
    unsigned int mod = number_of_used_bits % 8;

    if (bit)
        set_bit(mod);
    else
        clear_bit(mod);

    number_of_used_bits++;
}

bool Code::get_bit(unsigned int n)
{
    ListNode* current = bytes.get_current();
    unsigned int mod = n % 8;
    if (current == nullptr)
        current = bytes.get_begin();
    else if (mod == 0)
        current = current->get_next();
    bytes.set_current(current);
    bool ret = current->get_data() & (unsigned char(1) << (7 - mod));
    return ret;
}

void Code::add_bits(bool* bits, unsigned int num_bits)
{
    for (unsigned int i = num_bits; i > 0; i--)
    {
        add_bit(bits[i - 1]);
    }
}

void Code::add_byte(byte byte, unsigned int num_bits)
{
    bytes.push(byte);
    number_of_used_bits += num_bits;
}

byte Code::get_byte(unsigned int n)
{
    return bytes.get(n);
}

ofstream& operator<<(ofstream& os, const Code& code)
{
    LinkedList list = code.get_bytes();
    os << list;
    return os;
}

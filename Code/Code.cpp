#include "Code.h"

void Code::set_bit(unsigned int pos, char n) 
{
  bytes[pos] = bytes[pos] | (1 << n);
}

void Code::clear_bit(unsigned int pos, char n) 
{
  bytes[pos] = bytes[pos] & ~(1 << n);
}

// aqui uma lista ligada seria útil
Code::Code(): bytes(bool[10000]), number_of_used_bits(0) {};

char* Code::get_bytes()
{
  return bytes;
}

unsigned int Code::get_number_of_used_bits()
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

bool Code::get_bit(unsigned int n) 
{
  unsigned int pos = (unsigned int)(n / 8);
  unsigned int mod = n % 8;

  return bytes[pos] & (1 << (7 - mod));
}
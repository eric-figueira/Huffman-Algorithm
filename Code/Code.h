#ifndef CODE
#define CODE

#include <ofstream>
#include "LinkedList.h"

using namespace std;

class Code 
{
  private:
    LinkedList<char> bytes;
    unsigned int number_of_used_bits;
    void set_bit(unsigned int pos, char n);
    void clear_bit(unsigned int pos, char n);

  public:
    Code();

    LinkedList<char> get_bytes();
    unsigned int get_number_of_used_bits();

    void add_bit(bool bit);
    bool get_bit(unsigned int n);

    void add_bits(bool* bits, unsigned int num_bits);

    void add_byte(char byte, unsigned int num_bits);
    char get_byte(unsigned int n);

    friend ofstream& operator<< (ofstream& os, const Code& code);
};

#endif 
#ifndef CODE
#define CODE

#include <ofstream>

using namespace std;

class Code 
{
  private:
    char* bytes;
    unsigned int number_of_used_bits;
    void set_bit(unsigned int pos, char n);
    void clear_bit(unsigned int pos, char n);

  public:
    Code();

    char* get_bytes();
    unsigned int get_number_of_used_bits();

    void add_bit(bool bit);
    bool get_bit(unsigned int n);

    // adiciona bit a bit a variável passada no parêmtro, e, sempre que chegar em 8, grava no arquivo esse byte gerado
    ofstream& operator<< (ostream& os, const Code& cd);
};

#endif 
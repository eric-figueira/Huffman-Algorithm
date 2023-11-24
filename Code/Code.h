#ifndef CODE
#define CODE

class Code 
{
  private:
    char* bytes;
    unsigned int number_of_used_bits;
    void set_bit(unsigned int pos, char n);
    void clear_bit(unsigned int pos, char n);

  public:
    Code();
    Code(unsigned int number_of_used_bits);

    char* get_bytes();
    unsigned int get_number_of_used_bits();

    void add_bit(bool bit);
    bool get_bit(unsigned int n);
};

#endif 
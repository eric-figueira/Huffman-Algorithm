#ifndef BYTEFREQUENCY
#define BYTEFREQUENCY


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
    // TODO: implement operators ==, < and > for this class (so we can use it as a compareTo -> code it in a way that consider priorities as a and b, and when you compare a < b, a is smaller than b)
};

#endif
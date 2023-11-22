#ifndef BYTEFREQUENCY
#define BYTEFREQUENCY


class ByteFrequency
{
  private:
    int  frequency;
    // TODO: char must be changed to generic byte
    char character; 

  public:
    int  get_frequency() const;
    char get_character() const;

    void set_frequency(int f);
    void set_character(char c);
  
    ByteFrequency(int f, char c);
    ByteFrequency();
}

#endif
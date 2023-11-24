#ifndef ENCODER
#define ENCODER

class Encoder 
{
  private:
    char* input_directory;

  public:
    Encoder();
    Encoder(char* input_directory);

    void encode(char* output_directory) const;
};

#endif 
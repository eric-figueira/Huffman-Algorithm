#ifndef DECODER
#define DECODER

class Decoder 
{
  private:
    char* input_directory;

  public:
    Decoder();
    Decoder(char* input_directory);

    void decode(char* output_directory) const;
};

#endif 
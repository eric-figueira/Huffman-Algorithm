#include <iostream>
#include <fstream.h>

#include "BinaryTree.h"
#include "Code.h"
#include "Decoder.h"
#include "PriorityQueue.h"

using namespace std;

Decoder::Decoder(): input_directory("C:\\input.dat") {}

Decoder::Decoder(char* input_directory): input_directory(input_directory) {}

void Decoder::decode(char* output_directory) const 
{
  
}
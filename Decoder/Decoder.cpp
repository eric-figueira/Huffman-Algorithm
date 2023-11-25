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
  ifstream input(input_directory);
  if (!input)
  {
    cerr << "[Encoder]: Input file not found!";
    exit(-1);
  }

  PriorityQueue priorityQueue;
  // quantos caracteres distintos existem no arquivo
  char n_distinct_chars;
  input.get(c);

  // caracteres e suas respectivas frequências
  for (unsigned char i = 0; i < n_distinct_chars; i++) {
    // char
    char c;
    input.get(c);

    // frequency
    unsigned int c_frequency;
    input.read(reinterpret_cast<char*>(&c_frequency), sizeof(c_frequency));

    TreeNode<ByteFrequency> node (ByteFrequency(c_frequency, c));

    priorityQueue.add_by_priority(node);
  }

  BinaryTree binaryTree;
  binaryTree.create_tree_from_priority_queue(priorityQueue);

  // quantos bits da árvore existem
  unsigned int n_bits_from_tree;
  input.read(reinterpret_cast<char*>(&n_bits_from_tree), sizeof(n_bits_from_tree));
  
  // bits da árvore (0 para esc, 1 para dir)
  
}
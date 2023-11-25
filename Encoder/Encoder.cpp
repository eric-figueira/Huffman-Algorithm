#include <iostream>
#include <fstream.h>

#include "BinaryTree.h"
#include "Code.h"
#include "Encoder.h"
#include "PriorityQueue.h"


using namespace std;

Encoder::Encoder(): input_directory("C:\\input.dat") {}

Encoder::Encoder(char* input_directory): input_directory(input_directory) {}

void Encoder::encode(char* output_directory) const 
{
  ifstream input(input_directory);
  if (!input) 
  {
    cerr << "[Encoder]: Input file not found!";
    exit(-1);
  }

  PriorityQueue priorityQueue;
  char input_sequence[];
  unsigned int seq_index = 0;
  while (input.eof() == 0) 
  {
    char c;
    input.get(c);
    priorityQueue.add_in_pos(c);
    input_sequence[seq_index++] = c;
  }

  input.close();

  priorityQueue.order_vector();

  ofstream output(output_directory);
  if (!ofstream) 
  {
    cerr << "[Encoder]: Output file could not be created!";
  }

  // quantos caracteres distintos existem no arquivo
  char n = priorityQueue.get_used_size();
  output << n;

  // caracteres e suas respectivas frequências
  TreeNode<ByteFrequency>* vector = priorityQueue.get_vector();
  for (char i = 0; i < n; i++) 
  {
    output << vector[i].get_data();
  }

  BinaryTree binaryTree;
  binaryTree.create_tree_from_priority_queue(priorityQueue);

  // quantos bits da árvore existem
  unsigned int n_nodes = binaryTree.get_n_nodes();
  output << n_nodes;

  // bits da árvore (0 para esc, 1 para dir)
  CharCode* codes = binaryTree.visit_and_generate_codes();

  Code code;

  for (int i = 0; i < seq_index; i++) {
    char c = input_sequence[i];
    CharCode val;
    for (unsigned int j = 0; j < n; j++) 
    {
      if (codes[j].get_char() == c)
      {
        val = codes[j];
        break;
      }
    }
    bool* cd = val.get_code();
    for (unsigned int j = 0; j < val.get_code_size(); i ++) 
    {
      code.add_bit([j]);
    }
  }

  output << code;

  output.close();
}
#include <iostream>
#include <fstream>

#include "BinaryTree.h"
#include "Code.h"
#include "Encoder.h"
#include "PriorityQueue.h"
#include "LinkedList.h"


void Encoder::encode(char* input_directory, char* output_directory)
{
    ifstream input(input_directory);
    if (!input)
    {
        cerr << "[Encoder]: Input file not found!";
        exit(-1);
    }

    PriorityQueue priorityQueue;
    LinkedList input_sequence;
    while (input.eof() == 0)
    {
        char c;
        input.get(c);
        priorityQueue.add(c);
        input_sequence.push(c);
    }

    input.close();

    priorityQueue.order_vector();

    TreeNode* vect = priorityQueue.get_vector();
    for (int i = 0; i < priorityQueue.get_used_size(); i++)
        cout << vect[i].get_data().get_byte_code();

    ofstream output(output_directory);
    if (!output)
    {
        cerr << "[Encoder]: Output file could not be created!";
        exit(-1);
    }

    // quantos caracteres distintos existem no arquivo
    char n = priorityQueue.get_used_size();
    output << n;

    // caracteres e suas respectivas frequências
    TreeNode* vector = priorityQueue.get_vector();
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

    for (unsigned int i = 0; i < input_sequence.get_size(); i++) {
        char c = input_sequence.get(i);
        CharCode val;
        for (unsigned int j = 0; j < (unsigned int)n; j++)
        {
            if (codes[j].get_char() == c)
            {
                val = codes[j];
                break;
            }
        }
        bool* cd = val.get_code();
        code.add_bits(cd, val.get_code_size());
    }

    output << code;

    delete codes;

    output.close();
}
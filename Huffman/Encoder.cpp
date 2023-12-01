#include <iostream>
#include <fstream>

#include "BinaryTree.h"
#include "Code.h"
#include "Encoder.h"
#include "PriorityQueue.h"
#include "LinkedList.h"


void Encoder::encode(char* input_directory, char* output_directory)
{
    ifstream input(input_directory, ios::binary);
    if (!input)
    {
        cerr << "[Encoder]: Input file not found!";
        exit(-3);
    }

    PriorityQueue priorityQueue;
    LinkedList input_sequence;
    char c;
    while (input.get(c))
    {
        priorityQueue.add(c);
        input_sequence.push(c);
    }

    input.close();

    priorityQueue.order_vector();

    ofstream output(output_directory, ios::binary);
    if (!output)
    {
        cerr << "[Encoder]: Output file could not be created!";
        exit(-3);
    }

    // quantos caracteres distintos existem no arquivo
    unsigned char n = priorityQueue.get_used_size();
    output << n;

    // caracteres e suas respectivas frequências
    TreeNode* vector = priorityQueue.get_vector();
    for (unsigned char i = 0; i < n; i++)
    {
        output << vector[i].get_data();
        /*cout << (int)i << " ";
        cout << vector[i].get_data().get_byte_code() << " ";
        cout << vector[i].get_data().get_frequency() << "\n";*/
    }

    output << "_"; // separação entre últma frequencia e numero de nos

    BinaryTree binaryTree;
    binaryTree.create_tree_from_priority_queue(priorityQueue);

    // bits da árvore (0 para esc, 1 para dir)
    CharCode* codes = binaryTree.visit_and_generate_codes();

    Code code;

    for (unsigned int i = 0; i < input_sequence.get_size(); i++) {
        unsigned char c = input_sequence.get(i);
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
        cout << val.get_char() << " ";
        code.add_bits(cd, val.get_code_size());
    }

    // quantos bits da árvore existem
    output << (int)code.get_number_of_used_bits();

    output << code;

    output.close();
}
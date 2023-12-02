#include <iostream>
#include <fstream>

#include "BinaryTree.h"
#include "Code.h"
#include "Encoder.h"
#include "PriorityQueue.h"
#include "LinkedList.h"
#include "Types.h"


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
        priorityQueue.add((byte) c);
        input_sequence.push((byte) c);
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
    byte n = priorityQueue.get_used_size();
    output << n;

    // caracteres e suas respectivas frequ�ncias
    TreeNode* vector = priorityQueue.get_vector();
    for (byte i = 0; i < n; i++)
    {
        output << vector[i].get_data();
    }

    BinaryTree binaryTree;
    binaryTree.create_tree_from_priority_queue(priorityQueue);

    // bits da �rvore (0 para esc, 1 para dir)
    CharCode* codes = binaryTree.visit_and_generate_codes();

    Code code;

    for (ListNode* current = input_sequence.get_begin(); current != nullptr; current = current->get_next()) {
        byte c = current->get_data();
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

    // quantos bits da �rvore existem
    unsigned int u = code.get_number_of_used_bits();
    output.write(reinterpret_cast<const char*>(&u), sizeof(u));

    output << code;

    output.close();
}
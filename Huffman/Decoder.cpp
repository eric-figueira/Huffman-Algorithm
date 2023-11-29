#include <iostream>
#include <fstream>

#include "BinaryTree.h"
#include "Code.h"
#include "Decoder.h"
#include "PriorityQueue.h"


void Decoder::decode(char* input_directory, char* output_directory)
{
    ifstream input(input_directory);
    if (!input)
    {
        cerr << "[Encoder]: Input file not found!";
        exit(-2);
    }

    PriorityQueue priorityQueue;
    // quantos caracteres distintos existem no arquivo
    char n_distinct_chars;
    input.get(n_distinct_chars);

    // caracteres e suas respectivas frequências
    for (unsigned char i = 0; i < n_distinct_chars; i++) {
        // char
        char c;
        input.get(c);

        // frequency
        unsigned int c_frequency;
        input.read(reinterpret_cast<char*>(&c_frequency), sizeof(c_frequency));

        TreeNode node(ByteFrequency(c_frequency, c));

        priorityQueue.add_by_priority(node);
    }

    BinaryTree binaryTree;
    binaryTree.create_tree_from_priority_queue(priorityQueue);

    // quantos bits da árvore existem
    unsigned int n_bits_from_tree;
    input.read(reinterpret_cast<char*>(&n_bits_from_tree), sizeof(n_bits_from_tree));

    // bits da árvore (0 para esc, 1 para dir)
    Code code = Code();
    for (unsigned int i = 0; i < (unsigned int)(n_bits_from_tree / 8); i++)
    {
        code.add_byte(input.get(), 8);
    }

    code.add_byte(input.get(), (unsigned int)(n_bits_from_tree % 8));

    CharCode* codes = binaryTree.visit_and_generate_codes();

    // salvando o arquivo descompactado
    ofstream output(output_directory);
    if (!output)
    {
        cerr << "[Decoder]: Output file could not be created!";
        exit(-2);
    }

    // percorrer a árvore e guardar no arquivo os códigos ao chegar nas folhas
    LinkedList chars = binaryTree.generate_bytes_from_code(code);

    output << chars;

    delete codes;

    output.close();
}
#include <iostream>
#include <fstream>

#include "BinaryTree.h"
#include "Code.h"
#include "Decoder.h"
#include "PriorityQueue.h"
#include "Types.h"


void Decoder::decode(char* input_directory, char* output_directory)
{
    ifstream input(input_directory, ios::binary);
    if (!input)
    {
        cerr << "[Encoder]: Input file not found!";
        exit(-2);
    }

    PriorityQueue priorityQueue;
    
    // quantos caracteres distintos existem no arquivo
    unsigned short int n_distinct_chars;
    n_distinct_chars = input.get() + 1;
    // input.read(reinterpret_cast<char*>(&n_distinct_chars), sizeof(n_distinct_chars));

    // caracteres e suas respectivas frequ�ncias
    for (unsigned short int i = 0; i < n_distinct_chars; i++) {
        // char
        char c;
        input.get(c);

        // frequency
        unsigned long long frequency_value;
        input.read(reinterpret_cast<char*>(&frequency_value), sizeof(frequency_value));
        //input >> frequency_value;

        TreeNode node(ByteFrequency(frequency_value, c));

        priorityQueue.add_by_priority(node);
    }

    CharCode* codes = new CharCode[n_distinct_chars];

    BinaryTree binaryTree;
    binaryTree.create_tree_from_priority_queue(priorityQueue, codes);

    // quantos bits da �rvore existem
    unsigned long long n_bits_from_tree;
    input.read(reinterpret_cast<char*>(&n_bits_from_tree), sizeof(n_bits_from_tree));;

    // bits da �rvore (0 para esc, 1 para dir)
    Code code = Code();
    for (unsigned long long i = 0; i < (unsigned long long)(n_bits_from_tree / 8); i++)
    {
        code.add_byte(input.get(), 8);
    }

    if (n_bits_from_tree % 8 != 0)
        code.add_byte(input.get(), (unsigned long long)(n_bits_from_tree % 8));

    // salvando o arquivo descompactado
    ofstream output(output_directory, ios::binary);
    if (!output)
    {
        cerr << "[Decoder]: Output file could not be created!";
        exit(-2);
    }

    // percorrer a �rvore e guardar no arquivo os c�digos ao chegar nas folhas
    LinkedList chars = binaryTree.generate_bytes_from_code(code);

    output << chars;
}
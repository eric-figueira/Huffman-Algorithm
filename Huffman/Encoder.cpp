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
    ifstream input(input_directory, ios::binary|ios::in);
    if (!input)
    {
        cerr << "[Encoder]: Input file not found!";
        exit(-3);
    }

    PriorityQueue priorityQueue;
    LinkedList input_sequence;
    char c;

    while (!input.eof())
    {
        input.get(c);
        priorityQueue.add((byte) c);
        input_sequence.push((byte) c);
    }

    priorityQueue.order_vector();

    ofstream output(output_directory, ios::binary|ios::out);
    if (!output)
    {
        cerr << "[Encoder]: Output file could not be created!";
        exit(-3);
    }

    // quantos caracteres distintos existem no arquivo
    unsigned short n = priorityQueue.get_used_size();
    output << (byte)(n - 1);

    // caracteres e suas respectivas frequ�ncias
    TreeNode** vector = priorityQueue.get_vector();
    for (unsigned short int i = 0; i < n; i++)
    {
        output << (*(vector[i])).get_data();
    }

    // bits da �rvore (0 para esc, 1 para dir)
    CharCode* codes = new CharCode[n];

    BinaryTree binaryTree;
    binaryTree.create_tree_from_priority_queue(priorityQueue, codes);

    //for (int i = 0; i < n; i++) 
    //{
    //    cout << codes[i].get_char() << " ";
    //    for (int j = 0; j < codes[i].get_code_size(); j++)
    //    {
    //        if (codes[i].get_code()[j])
    //            cout << "1";
    //        else
    //            cout << "0";
    //    }
    //    cout << "\n";
    //}

    Code code;

    ListNode* current = new ListNode();

    for (*current = *input_sequence.get_begin(); current != nullptr; current = current->get_next()) {
        byte c = current->get_data();
        CharCode val;
        for (unsigned short int j = 0; j < n; j++)
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

    delete current;
    delete[] codes;
    
    // quantos bits da �rvore existem
    unsigned long long u = code.get_number_of_used_bits();
    output.write(reinterpret_cast<const char*>(&u), sizeof(u));

    output << code;
}
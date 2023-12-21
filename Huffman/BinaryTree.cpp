#include <iostream>
#include <cstdbool>

#include "BinaryTree.h"
#include "TreeNode.h"
#include "CharCode.h"

BinaryTree::BinaryTree() : root(nullptr), current(nullptr), previous(nullptr), n_nodes(0) {}

BinaryTree::~BinaryTree()
{
    destructor(root);
}

void BinaryTree::destructor(TreeNode* node)
{
    if (node != nullptr) {
        destructor(node->get_left());
        destructor(node->get_right());

        delete node;
    }
}

void BinaryTree::create_codes(TreeNode* node, CharCode* codes, TreeNode* newNode, unsigned short int *index, bool val)
{
    // se o n� � uma folha, ent�o criar um novo c�digo no vetor de c�digos e adicionar o valor correspondente � posi��o do n�
    if ((*node).get_left() == nullptr && (*node).get_right() == nullptr)
    {
        codes[*index] = CharCode((*node).get_data().get_byte_code(), new bool[8], 0);
        codes[*index].push_to_code(val);
        (*index)++;
        (*newNode).append_under((*node).get_data().get_byte_code());
    }

    else {
        // se n�o, percorrer os c�digos dos n�s que est�o abaixo do n� atual, e, para cada um deles, encontrar a posi��o do 
        // n� com aquele c�digo no vetor de c�digos e adicionar o valor correspondente � sua posi��o no mesmo
        byte* under = (*node).get_under();
        unsigned short int size = (*node).get_size();
        unsigned short int i;
        for (i = 0; i < size; i++) {
            byte c = under[i];
            unsigned short int j;
            for (j = 0; j < *index; j++)
            {
                if (codes[j].get_char() == c)
                    break;
            }
            codes[j].push_to_code(val);
        }
        (*newNode).append_under((*node).get_under(), (*node).get_size());
    }
}

void BinaryTree::create_tree_from_priority_queue(PriorityQueue* queue, CharCode* codes) {
    unsigned short int index = 0;

    // enquanto a fila tiver dois ou mais nodos:
    while ((*queue).get_used_size() >= 2) {
        // Desenfileirar um n� para se tornar a sub�rvore esquerda
        TreeNode* left = (*queue).dequeue();
        // Desenfileirar um n� para se tornar a sub�rvore direita
        TreeNode* right = (*queue).dequeue();

        // Criar um novo n�, com as respectivas sub�rvores
        // Tornar a frequ�ncia do novo n� igual a soma das frequencias dos filhos esquerdo e direito
        
        TreeNode* newNode = new TreeNode(ByteFrequency((*left).get_data().get_frequency() + (*right).get_data().get_frequency(), 0),
            left, right);

        // criando os c�digos

        if (codes != nullptr)
        {
            create_codes(left, codes, newNode, &index, false);
            create_codes(right, codes, newNode, &index, true);
        }

        // Enfileirar o novo n� (de acordo com a prioridade)
        (*queue).add_by_priority(newNode);

        n_nodes += 1;
    }

    // Quando a fila s� tiver um n�
    if ((*queue).get_used_size() == 1) {
        // Desenfileire esse n�
        TreeNode* lastNode = (*queue).dequeue();

        // Coloque esse n� como raiz da arvore
        root = lastNode;

        n_nodes += 1;
    }
}

unsigned int BinaryTree::get_n_nodes() const { return n_nodes; }

LinkedList BinaryTree::generate_bytes_from_code(Code code)
{
    LinkedList list;

    current = root;
    for (unsigned long long i = 0; i < code.get_number_of_used_bits(); i++)
    {
        if (current->get_right() == nullptr && current->get_left() == nullptr)
        {
            list.push(current->get_data().get_byte_code());
            current = root;
        }
        bool val = code.get_bit(i);
        if (val)
            current = current->get_right();
        else
            current = current->get_left();
    }

    return list;
}

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
    // se o nó é uma folha, então criar um novo código no vetor de códigos e adicionar o valor correspondente à posição do nó
    if ((*node).get_left() == nullptr && (*node).get_right() == nullptr)
    {
        codes[*index] = CharCode((*node).get_data().get_byte_code(), new bool[8], 0);
        codes[*index].push_to_code(val);
        (*index)++;
        (*newNode).append_under((*node).get_data().get_byte_code());
    }

    else {
        // se não, percorrer os códigos dos nós que estão abaixo do nó atual, e, para cada um deles, encontrar a posição do 
        // nó com aquele código no vetor de códigos e adicionar o valor correspondente à sua posição no mesmo
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
        // Desenfileirar um nó para se tornar a subárvore esquerda
        TreeNode* left = (*queue).dequeue();
        // Desenfileirar um nó para se tornar a subárvore direita
        TreeNode* right = (*queue).dequeue();

        // Criar um novo nó, com as respectivas subárvores
        // Tornar a frequência do novo nó igual a soma das frequencias dos filhos esquerdo e direito
        
        TreeNode* newNode = new TreeNode(ByteFrequency((*left).get_data().get_frequency() + (*right).get_data().get_frequency(), 0),
            left, right);

        // criando os códigos

        if (codes != nullptr)
        {
            create_codes(left, codes, newNode, &index, false);
            create_codes(right, codes, newNode, &index, true);
        }

        // Enfileirar o novo nó (de acordo com a prioridade)
        (*queue).add_by_priority(newNode);

        n_nodes += 1;
    }

    // Quando a fila só tiver um nó
    if ((*queue).get_used_size() == 1) {
        // Desenfileire esse nó
        TreeNode* lastNode = (*queue).dequeue();

        // Coloque esse nó como raiz da arvore
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

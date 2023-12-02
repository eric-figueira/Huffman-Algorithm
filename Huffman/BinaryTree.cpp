#include <iostream>
#include <cstdbool>

#include "BinaryTree.h"
#include "TreeNode.h"
#include "CharCode.h"

BinaryTree::BinaryTree() : root(nullptr), current(nullptr), previous(nullptr), n_nodes(0) {}

BinaryTree::~BinaryTree()
{
    delete root;
    delete current;
    delete previous;
}

void BinaryTree::create_tree_from_priority_queue(PriorityQueue queue) {
    // enquanto a fila tiver dois ou mais nodos:
    while (queue.get_used_size() >= 2) {
        // Desenfileirar um nó para se tornar a subárvore esquerda
        TreeNode l_node = queue.dequeue();
        // Desenfileirar um nó para se tornar a subárvore direita
        TreeNode r_node = queue.dequeue();

        // Criar um novo nó, com as respectivas subárvores
        // Tornar a frequência do novo nó igual a soma das frequencias dos filhos esquerdo e direito

        TreeNode* p_left = new TreeNode(l_node);
        TreeNode* p_right = new TreeNode(r_node);

        TreeNode newNode = TreeNode(ByteFrequency(l_node.get_data().get_frequency() + r_node.get_data().get_frequency(), 0),
            p_left, p_right);

        // Enfileirar o novo nó (de acordo com a prioridade)
        queue.add_by_priority(newNode);

        n_nodes += 1;
    }

    // Quando a fila só tiver um nó
    if (queue.get_used_size() == 1) {
        // Desenfileire esse nó
        TreeNode lastNode = queue.dequeue();

        // Coloque esse nó como raiz da arvore
        root = new TreeNode(lastNode);

        n_nodes += 1;
    }
}

unsigned int BinaryTree::get_n_nodes() const { return n_nodes; }

CharCode* codes;

CharCode* BinaryTree::visit_and_generate_codes()
{
    codes = new CharCode[n_nodes];

    bool* array = new bool[n_nodes];
    visit_and_generate_codes_helper(root, array, 0);
    delete[] array;

    return codes;
}

int index = 0;

void BinaryTree::visit_and_generate_codes_helper(TreeNode* node, bool* currentCode, unsigned int size)
{
    if (node != nullptr) {
        if (node->get_left() == nullptr && node->get_right() == nullptr) {
            // Um código está pronto quando uma folha for atingida
            // Adicionar a relação char código no vetor codes e repetir o processo até que todas as folhas tenham sido percorridas
            codes[index] = CharCode(node->get_data().get_byte_code(), currentCode, size);
            index++;
        }

        // Percorrer a árvore para obter os códigos 
        // Acrescentar 0 (false) ao código, toda vez que for para a esquerda, ou 1 (true), toda vez que for para a direita
        bool* new_current_code = new bool[size];
        for (unsigned int i = 0; i < size; i++)
            new_current_code[i] = currentCode[i];
        new_current_code[size] = false;
        visit_and_generate_codes_helper(node->get_left(), new_current_code, ++size);

        new_current_code = new bool[size];
        for (unsigned int i = 0; i < size; i++)
            new_current_code[i] = currentCode[i];
        new_current_code[size] = true;
        visit_and_generate_codes_helper(node->get_right(), new_current_code, size);
    }
}

LinkedList BinaryTree::generate_bytes_from_code(Code code)
{
    LinkedList list = LinkedList();

    current = root;
    for (unsigned int i = 0; i < code.get_number_of_used_bits() + 1; i++)
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

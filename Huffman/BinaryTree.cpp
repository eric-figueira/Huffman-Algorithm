#include <iostream>
#include <cstdbool>

#include "BinaryTree.h"
#include "TreeNode.h"
#include "CharCode.h"

BinaryTree::BinaryTree() : root(NULL), current(NULL), previous(NULL), n_nodes(0) {}

void BinaryTree::create_tree_from_priority_queue(PriorityQueue queue) {
    // enquanto a fila tiver dois ou mais nodos:
    while (queue.get_used_size() >= 2) {
        // Desenfileirar um nó para se tornar a subárvore esquerda
        TreeNode<ByteFrequency> l_node = queue.dequeue();
        // Desenfileirar um nó para se tornar a subárvore direita
        TreeNode<ByteFrequency> r_node = queue.dequeue();

        // Criar um novo nó, com as respectivas subárvores
        TreeNode<ByteFrequency> newNode(TreeNode<ByteFrequency>(ByteFrequency(), &l_node, &r_node));

        // Tornar a frequência do novo nó igual a soma das frequencias dos filhos esquerdo e direito
        newNode.get_data().set_frequency(
            newNode.get_left()->get_data().get_frequency() +
            newNode.get_right()->get_data().get_frequency()
        );

        // Enfileirar o novo nó (de acordo com a prioridade)
        queue.add_by_priority(newNode);
    }

    // Quando a fila só tiver um nó
    if (queue.get_used_size() == 1) {
        // Desenfileire esse nó
        TreeNode<ByteFrequency> lastNode = queue.dequeue();

        // Coloque esse nó como raiz da arvore
        root = &lastNode;
        n_nodes = count_nodes(root);
    }
}

int BinaryTree::count_nodes(TreeNode<ByteFrequency>* node) {
    if (node == NULL) {
        return 0;
    }

    int leftCount = count_nodes (node->get_left());
    int rightCount = count_nodes(node->get_right());

    return 1 + leftCount + rightCount;
}

unsigned int BinaryTree::get_n_nodes() const { return n_nodes; }

CharCode* codes;

CharCode* BinaryTree::visit_and_generate_codes()
{
    codes = new CharCode[n_nodes];

    bool* array = new bool[n_nodes];
    visit_and_generate_codes_helper(root, &array, 0);
    delete[] array;

    return codes;
}

int index = 0;

void BinaryTree::visit_and_generate_codes_helper(TreeNode<ByteFrequency>* node, bool** currentCode, unsigned int size)
{
    if (node->get_left() == NULL && node->get_right() == NULL) {
        // Um código está pronto quando uma folha for atingida
        // Adicionar a relação char código no vetor codes e repetir o processo até que todas as folhas tenham sido percorridas
        codes[index] = CharCode(node->get_data().get_byte_code(), *currentCode, size);
        index++;
    }

    // Percorrer a árvore para obter os códigos 
    // Acrescentar 0 (false) ao código, toda vez que for para a esquerda, ou 1 (true), toda vez que for para a direita
    bool* new_current_code = *currentCode;
    new_current_code[size] = false;
    visit_and_generate_codes_helper(node->get_left(), &new_current_code, size++);

    new_current_code[size] = true;
    visit_and_generate_codes_helper(node->get_right(), &new_current_code, size++);
}

LinkedList<char> BinaryTree::generate_bytes_from_code(Code code)
{
    LinkedList<char> list = LinkedList<char>();

    current = root;
    for (unsigned int i = 0; i < code.get_number_of_used_bits(); i++)
    {
        if (current->get_right() == NULL && current->get_left() == NULL)
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

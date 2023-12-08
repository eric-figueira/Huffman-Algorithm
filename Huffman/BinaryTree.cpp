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

void BinaryTree::create_tree_from_priority_queue(PriorityQueue queue, CharCode* codes) {
    unsigned short int index = 0;

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

        // criando os códigos

        // se o nó é uma folha, então criar um novo código no vetor de códigos e adicionar o valor correspondente à posição do nó
        if (l_node.get_left() == nullptr && l_node.get_right() == nullptr)
        {
            codes[index] = CharCode(l_node.get_data().get_byte_code(), new bool[8], 0);
            codes[index].push_to_code(false);
            index++;
            newNode.append_under(l_node.get_data().get_byte_code());
        }

        else {
            // se não, percorrer os códigos dos nós que estão abaixo do nó atual, e, para cada um deles, encontrar a posição do 
            // nó com aquele código no vetor de códigos e adicionar o valor correspondente à sua posição no mesmo
            byte* under = l_node.get_under();
            unsigned short int size = l_node.get_size();
            unsigned short int i;
            for (i = 0; i < size; i++) {
                byte c = under[i];
                unsigned short int j;
                for (j = 0; j < index; j++)
                {
                    if (codes[j].get_char() == c)
                        break;
                }
                codes[j].push_to_code(false);
            }
            newNode.append_under(l_node.get_under(), l_node.get_size());
        }

        if (r_node.get_left() == nullptr && r_node.get_right() == nullptr)
        {
            codes[index] = CharCode(r_node.get_data().get_byte_code(), new bool[8], 0);
            codes[index].push_to_code(true);
            index++;
            newNode.append_under(r_node.get_data().get_byte_code());
        }

        else {
            byte* under = r_node.get_under();
            unsigned short int size = r_node.get_size();
            unsigned short int i;
            for (i = 0; i < size; i++) {
                byte c = under[i];
                unsigned short int j;
                for (j = 0; j < index; j++)
                {
                    if (codes[j].get_char() == c)
                        break;
                }
                codes[j].push_to_code(true);
            }
            newNode.append_under(r_node.get_under(), r_node.get_size());
        }

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

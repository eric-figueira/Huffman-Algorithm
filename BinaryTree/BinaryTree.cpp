#include <iostream>

#include "BinaryTree.h"
#include "TreeNode.h"

using namespace std;

BinaryTree::BinaryTree() : root(NULL), current(NULL), previous(NULL) {}

void BinaryTree::create_tree_from_priority_queue(PriorityQueue queue) {
  // enquanto a fila tiver dois ou mais nodos:
  while (queue.get_used_size() >= 2) {

    // Desenfileirar um nó para se tornar a subárvore esquerda
    TreeNode<ByteFrequency> l_node = queue.dequeue();
    // Desenfileirar um nó para se tornar a subárvore direita
    TreeNode<ByteFrequency> r_node = queue.dequeue();

    // Criar um novo nó, com as respectivas subárvores
    TreeNode<ByteFrequency> newNode (TreeNode<ByteFrequency>(ByteFrequency(), &l_node, &r_node));

    // Tornar a frequência do novo nó igual a soma das frequencias dos filhos esquerdo e direito
    newNode.get_data().set_frequency(
      newNode.get_left() -> get_data().get_frequency() +
      newNode.get_right() -> get_data().get_frequency()
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
  } 
}

unsigned int BinaryTree::get_n_nodes() const { return n_nodes; }

CharCode* BinaryTree::visit_and_generate_codes() 
{
  CharCode *codes = new CharCode[n_nodes];
  
  visit_and_generate_codes_helper(root, codes, 0, new bool[n_nodes]);

  return codes;
}

void BinaryTree::visit_and_generate_codes_helper(TreeNode<ByteFrequency>* node, CharCode* codesArray, unsigned int index, bool* currentCode)
{
  if (node -> get_left() == NULL && node -> get_right() == NULL) {
    // Um código está pronto quando uma folha for atingida
    codesArray[index] = CharCode(node -> get_data().get_byte_code(), *currentCode, );
  }
  // Percorrer a árvore para obter os códigos 

  
  // Acrescentar 0 (false) ao código, toda vez que for para a esquerda, ou 1 (true), toda vez que for para a direita 

  

  // Adicionar a relação char código no vetor codes e repetir o processo até que todas as folhas tenham sido percorridas
}
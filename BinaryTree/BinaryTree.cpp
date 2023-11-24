#include <iostream>

#include "BinaryTree.h"
#include "TreeNode.h"

using namespace std;

BinaryTree::BinaryTree() : first(NULL), current(NULL), previous(NULL) {}

void BinaryTree::create_tree_from_priority_queue(PriorityQueue queue) {
  // enquanto a fila tiver dois ou mais nodos:
  /*
    - crie um novo nodo
    - desenfileire um nodo e o torne subarvore esquerda
    - desenfileire um nodo e o torne subarvore direita
    - torne a frequencia do nodo igual a soma das frequencias dos filhos esquerdo e direito
    - enfileire o novo nodo (de acordo com a prioridade)
  */

  // quando a fila só tiver um nodo
  /*
    - desenfileire esse nodo
    - coloque esse nodo como raiz da arvore
    - a frequencia da raiz deve ser igual a quantidade total de bytes do arquivo
  */
}

unsigned int BinaryTree::get_n_nodes() const { return n_nodes; }

CharCode* BinaryTree::visit_and_generate_codes() 
{
  CharCode *codes;
  /*
    - percorra a árvore para obter os códigos 
    - acrescente 0 (false) ao código, toda vez que for para a esquerda, ou 1 (true), toda vez que for para a direita 
    - um código está pronto quando uma folha for atingida
    - adicionar a relação char código no vetor codes e repetir o processo até que todas as folhas tenham sido percorridas
  */
}
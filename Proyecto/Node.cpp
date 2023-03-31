//
// Created by oscaraad on 31/03/23.
//

#include <iostream>
#include "Node.h"
#include "ListaSimple.h"

using namespace std;
/**
 * @brief Método constructor de la clase Node
 * @param value Valor que tomará el nodo
 */
Node::Node(int value){
    this->value = value;
    this->next = nullptr;
}
/**
 * @brief Método que permite revisar la dirección de un nodo
 * @return Retorna el puntero de un nodo
 */
int* Node::checkPointer(){
    this->value = value;
    int* ptr = &value;
    return ptr;
}
/**
 * @brief Método para revisar el valor de un nodo
 */
void Node::checkNode(){
    cout<<this->value<<endl;
}
/**
 * @brief Método para modificar el valor de un nodo
 * @param value
 */
void Node::modifyNode(int value){
    this->value = value;
}

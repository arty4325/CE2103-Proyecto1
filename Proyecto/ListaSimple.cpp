//
// Created by oscaraad on 31/03/23.
//
#include "Node.h"
#include "ListaSimple.h"
#include <iostream>
using namespace std;


/**
 * @brief Método constructor de la clase ListaSimple
 */
ListaSimple::ListaSimple() {
    this->head = nullptr;
}
/**
 * @brief Permite obtener el head de una lista
 * @return Retorna el head de la lista
 */
Node* ListaSimple::getHead() {
    return this->head;
}
/**
 * @brief Permite cambiar el valor de head
 * @param newHead Nuevo valor que tomará head
 */
void ListaSimple::setHead(Node* newHead) {
    this->head = newHead;
}
/**
 * @brief Método que permite añadir nuevos nodos a la lista
 * @param value Valor que se contendrá en el nodo creado
 */
void ListaSimple::insertHead(int value){
    Node* newNode = new Node(value);
    newNode -> next = this -> head;
    this -> head = newNode;
}
/**
 * @brief Método que permite eliminar nodos de la lista
 */
void ListaSimple::deleteHead(){
    if(head != nullptr){
        Node* temp = head;
        head = head -> next;
        temp -> next = nullptr;
        delete temp;
    }
}
/**
 * @brief Método que permite mostrar los valores de la lista
 */
void ListaSimple::printList() const{
    cout << "*********************" << endl;
    cout << "Estado actual de la lista " << endl;
    Node* current = this->head;
    while(current != nullptr){
        cout << current->value << endl;
        current = current -> next;
    }
    cout << "*********************" << endl;
}


int ListaSimple::getPosVal(int position) const {
    Node* current = this -> head;
    int currentPosition = 0;
    while (current != nullptr && currentPosition != position){
        current = current -> next;
        currentPosition++;
    }
    if (current == nullptr){
        //throw std::out_of_range("Posicion Invalida");
        return 0;
    }
    return current -> value;
}



//
// Created by oscaraad on 12/04/23.
//

#include "SimpleList.h"
#include "NodeList.h"
#include "NodeList.cpp"
#include <iostream>
using namespace std;

/**
 * @brief Clase constructora de la clase Simple List
 * @tparam T
 */
template <class T>
SimpleList<T>::SimpleList() {
    this -> head = nullptr;
}

/**
 * @brief Obtiene el primer valor dde la lista SimpleList
 * @tparam T Tipo de dato
 * @return El valor que esta en la cabeza de SimpleList
 */
template <class T>
NodeList<T>* SimpleList<T>::getHead(){
    return this -> head;
}

/**
 * @brief Permite definir de nuevo cual es el primer valor en la lista SimpleList
 * @tparam T Tipo del dato
 * @param newHead El valor que se esta sustituyendo
 */
template <class T>
void SimpleList<T>::setHead(NodeList<T>* newHead){
    this -> head = newHead;
}

/**
 * @brief Permite insertar un valor en la cabeza de Simple List
 * @tparam T Tipo del dato
 * @param value El valor que se esta ingresando en la cabeza de SimpleList
 */
template <class T>
void SimpleList<T>::insertHead(T value){
    NodeList<T>* newNode = new NodeList<T>(value);
    newNode -> next = this -> head;
    this -> head = newNode;
}

/**
 * @brief Permite borrar el primer valor que esta en una Lista Simple
 * @tparam T El tipo del dato
 */
template <class T>
void SimpleList<T>::deleteHead(){
    if (head != nullptr){
        NodeList<T>* temp = head;
        head = head -> next;
        temp -> next = nullptr;
        delete temp;
    }
}

/**
 * @brief Imprime los valores que estan dentro de simple list
 * @tparam T Tipo del dato
 */
template <class T>
void SimpleList<T>::printList() const {
    cout << "*********************" << endl;
    cout << "Estado actual de la lista " << endl;
    NodeList<T>* current = this -> head;
    while (current != nullptr){
        cout << current-> value << endl;
        current = current -> next;
    }
    cout << "*********************" << endl;
}

/**
 * @brief Obtiene el valor e una posicion de la lista
 * @tparam T El tipo del dato
 * @param position La posicion que se quiere obtener
 * @return El valor que esta en la posicion dada
 */
template <class T>
T SimpleList<T>::getPosVal(int position) const {
    NodeList<T>* current = this -> head;
    int currentPosition = 0;
    while (current != nullptr && currentPosition != position){
        current = current -> next;
        currentPosition++;
    }
    if (current == nullptr){
        //throw out_of_range("Posicion Invalida");
        return head -> value;

    }
    return current -> value;
}

/**
 * @brief Permite obtener el valor de la cantidad de datos que hay en la lista
 * @tparam T Tipo de los datos
 * @return La cantidad de datos que hay en la lista
 */
template <class T>
int SimpleList<T>::getSize() const {
    NodeList<T>* current = this -> head;
    int size = 0;
    while (current != nullptr){
        size++;
        current = current -> next;
    }
    return size;
}

/**
 * @brief Borra el valor en una posicion en la lista
 * @tparam T El tipo de los datos
 * @param position La posicion del dato que se quiere borrar
 */
template <class T>
void SimpleList<T>::deletePos(int position) {
    if (position == 0) {
        deleteHead();
        return;
    }
    NodeList<T>* current = this -> head;
    int currentPosition = 0;
    while (current != nullptr && currentPosition != position - 1){
        current = current -> next;
        currentPosition++;
    }
    if (current == nullptr || current->next == nullptr) {
        throw out_of_range("Posicion Invalida");
    }
    NodeList<T>* temp = current->next;
    current->next = temp->next;
    temp->next = nullptr;
    delete temp;
}
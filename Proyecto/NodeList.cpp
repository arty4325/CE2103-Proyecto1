//
// Created by oscaraad on 12/04/23.
//

#include "NodeList.h"
#include <iostream>
using namespace std;

/**
 * @brief Metodo constructor de la clase NodeList
 * @tparam T Cualquier tipo de dato que se le quiera ingresar al nodo
 * @param value Valor que se le va a ingresar al Nodo
 */
template <class T>
NodeList<T>::NodeList(T value){
    this -> value = value;
    this -> next = nullptr;
}

/**
 * @brief Revisa cual es el puntero
 * @tparam T Valor
 * @return Puntero
 */
template <class T>
int* NodeList<T>::checkPointer() {
    int* ptr = &value;
    return ptr;
}

/**
 * @brief Revisa el valor en el nodo
 * @tparam T valor en el nodo
 */
template <class T>
void NodeList<T>::checkNode() {
    cout << this -> value << endl;
}

/**
 * @brief Modifica los valores en un nodo
 * @tparam T Tipo de dato por el que se va a sustituir
 * @param value Valor por el que se va a sustituir
 */
template <class T>
void NodeList<T>::modifyNode(T value) {
    this -> value = value;
}
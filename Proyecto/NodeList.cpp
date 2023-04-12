//
// Created by oscaraad on 12/04/23.
//

#include "NodeList.h"
#include <iostream>
using namespace std;

template <class T>
NodeList<T>::NodeList(T value){
    this -> value = value;
    this -> next = nullptr;
}

template <class T>
int* NodeList<T>::checkPointer() {
    int* ptr = &value;
    return ptr;
}

template <class T>
void NodeList<T>::checkNode() {
    cout << this -> value << endl;
}

template <class T>
void NodeList<T>::modifyNode(T value) {
    this -> value = value;
}
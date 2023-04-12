//
// Created by oscaraad on 12/04/23.
//

#include "SimpleList.h"
#include "NodeList.h"
#include "NodeList.cpp"
#include <iostream>
using namespace std;

template <class T>
SimpleList<T>::SimpleList() {
    this -> head = nullptr;
}

template <class T>
NodeList<T>* SimpleList<T>::getHead(){
    return this -> head;
}

template <class T>
void SimpleList<T>::setHead(NodeList<T>* newHead){
    this -> head = newHead;
}

template <class T>
void SimpleList<T>::insertHead(T value){
    NodeList<T>* newNode = new NodeList<T>(value);
    newNode -> next = this -> head;
    this -> head = newNode;
}

template <class T>
void SimpleList<T>::deleteHead(){
    if (head != nullptr){
        NodeList<T>* temp = head;
        head = head -> next;
        temp -> next = nullptr;
        delete temp;
    }
}


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

template <class T>
T SimpleList<T>::getPosVal(int position) const {
    NodeList<T>* current = this -> head;
    int currentPosition = 0;
    while (current != nullptr && currentPosition != position){
        current = current -> next;
        currentPosition++;
    }
    if (current == nullptr){
        throw out_of_range("Posicion Invalida");

    }
    return current -> value;
}
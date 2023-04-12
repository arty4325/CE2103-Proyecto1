//
// Created by oscaraad on 12/04/23.
//

#ifndef BATTLE_SPACE_SIMPLELIST_H
#define BATTLE_SPACE_SIMPLELIST_H

#include "NodeList.h"

template <class T>
class SimpleList {
private:
    NodeList<T>* head;
public:
    SimpleList();
    NodeList<T>* getHead();
    void insertHead(T value);
    void deleteHead();
    void printList() const;
    T getPosVal(int position) const;

    void setHead(NodeList<T> *newHead);

    int getSize() const;

    void deletePos(int position);
};


#endif //BATTLE_SPACE_SIMPLELIST_H

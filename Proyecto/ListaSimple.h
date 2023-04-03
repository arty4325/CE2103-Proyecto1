//
// Created by oscaraad on 31/03/23.
//

#ifndef BATTLE_SPACE_LISTASIMPLE_H
#define BATTLE_SPACE_LISTASIMPLE_H
#include "Node.h"
class ListaSimple{
private:
    Node* head;

public:
    ListaSimple();
    Node* getHead();
    void setHead(Node* newHead);
    void insertHead(int value);
    void deleteHead();
    void printList() const;
    int getPosVal(int position) const;
    //void* operator new(size_t size, int value);
    //void operator delete(void* ptr) noexcept;

};
#endif //BATTLE_SPACE_LISTASIMPLE_H

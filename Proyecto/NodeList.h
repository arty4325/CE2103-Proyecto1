//
// Created by oscaraad on 12/04/23.
//

#ifndef BATTLE_SPACE_NODELIST_H
#define BATTLE_SPACE_NODELIST_H

template <class T>
class NodeList {
public:
    NodeList(T value);

    T value;
    NodeList<T>* next;
    int* checkPointer();
    void checkNode();
    void modifyNode(T value);
};


#endif //BATTLE_SPACE_NODELIST_H

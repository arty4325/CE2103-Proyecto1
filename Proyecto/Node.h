//
// Created by oscaraad on 31/03/23.
//

#ifndef BATTLE_SPACE_NODE_H
#define BATTLE_SPACE_NODE_H
#include <cstddef>

/**
* @file Node.h
* @authors Jorge Guillén y Oscar Acuña
* @brief En esta header se crea la clase Node
* @version 0.1
* @date 10-3-2023
*
* @copyright Copyright (c) 2023
*/
class Node{
public:
    int value;
    Node* next;
    Node(int value);
    void checkNode();
    int* checkPointer();
    void modifyNode(int value);
};
#endif //BATTLE_SPACE_NODE_H

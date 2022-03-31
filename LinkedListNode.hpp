//
// Created by Cody on 3/30/2022.
//

#ifndef CS415PROJECT2_LINKEDLISTNODE_HPP
#define CS415PROJECT2_LINKEDLISTNODE_HPP

#include "Data.hpp"
#include <iostream>
#include <stdlib.h>

class Data;
class LinkedListNode
{
private:

    LinkedListNode* previousNode;
    LinkedListNode* nextNode;
  Data *PointerToDataForAParticularClient; 



public:
    void SetPointerToDataForAParticularClient(Data* IncomingPointerToDataForAParticularClient);
    void SetPreviousNodePointer(LinkedListNode* IncomingGraphNodePointer);
    void SetNextNodePointer(LinkedListNode* IncomingGraphNodePointer);
    LinkedListNode* GetPreviousNodePointer();
    LinkedListNode* GetNextNodePointer();
    Data* GetPointerToDataForAParticularClient();

};


#endif //CS415PROJECT2_LINKEDLISTNODE_HPP

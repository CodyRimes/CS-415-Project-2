//
// Created by Cody on 3/30/2022.
//

#ifndef CS415PROJECT2_LINKEDLISTNODE_HPP
#define CS415PROJECT2_LINKEDLISTNODE_HPP

#include "Data.hpp"
#include <iostream>
#include <stdlib.h>

class Data;
<<<<<<< HEAD
=======

>>>>>>> origin/main
class LinkedListNode
{
private:

    LinkedListNode* previousNode;
    LinkedListNode* nextNode;
<<<<<<< HEAD
  Data *PointerToDataForAParticularClient; 
=======
    int IndexID;

    //Data* PointerToDataForAParticularClient;
>>>>>>> origin/main



public:
    //Constructor
    LinkedListNode();
    //Parameterized Constructor
    LinkedListNode(LinkedListNode*, LinkedListNode*);

    //Setters
    //void SetPointerToDataForAParticularClient(Data* IncomingPointerToDataForAParticularClient);
    void SetPreviousNodePointer(LinkedListNode* IncomingGraphNodePointer);
    void SetNextNodePointer(LinkedListNode* IncomingGraphNodePointer);
    void SetIndexID(int IncomingAdjacencyListIndex);

    //Getters
    LinkedListNode* GetPreviousNodePointer();
    LinkedListNode* GetNextNodePointer();
    int GetIndexID();
    //Data* GetPointerToDataForAParticularClient();

};


#endif //CS415PROJECT2_LINKEDLISTNODE_HPP

//
// Created by Cody on 3/30/2022.
//

#ifndef CS415PROJECT2_LINKEDLISTNODE_HPP
#define CS415PROJECT2_LINKEDLISTNODE_HPP

#include "Data.hpp"
#include <iostream>

class Data;

class LinkedListNode
{
private:

    LinkedListNode* previousNode;
    LinkedListNode* nextNode;
    int IndexID;

    //Data* PointerToDataForAParticularClient;



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

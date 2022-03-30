//
// Created by Cody on 3/30/2022.
//

#include "LinkedListNode.hpp"
#include "Data.hpp"

void LinkedListNode::SetPointerToDataForAParticularClient(Data* IncomingPointerToDataForAParticularClient)
{
    PointerToDataForAParticularClient = IncomingPointerToDataForAParticularClient;
}
void LinkedListNode::SetPreviousNodePointer(LinkedListNode* IncomingGraphNodePointer)
{
    previousNode = IncomingGraphNodePointer;
}
void LinkedListNode::SetNextNodePointer(LinkedListNode* IncomingGraphNodePointer)
{
    nextNode = IncomingGraphNodePointer;
}
LinkedListNode* LinkedListNode::GetPreviousNodePointer()
{
    return previousNode;
}
LinkedListNode* LinkedListNode::GetNextNodePointer()
{
    return nextNode;
}
Data* LinkedListNode::GetPointerToDataForAParticularClient()
{
    return PointerToDataForAParticularClient;
}
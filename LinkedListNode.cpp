//
// Created by Cody on 3/30/2022.
//

#include "LinkedListNode.hpp"
#include "Data.hpp"
LinkedListNode::LinkedListNode()
{
    previousNode = nullptr;
    nextNode = nullptr;
}
LinkedListNode::LinkedListNode(LinkedListNode * PointToThePreviousNode, LinkedListNode * PointToTheNextNode)
{
    previousNode = PointToThePreviousNode;
    nextNode = PointToTheNextNode;
}


void LinkedListNode::SetPreviousNodePointer(LinkedListNode* IncomingPreviousNodePointer)
{
    //Note how this is not a pointer pointing at another pointer, but it is assigning our pointer to point at the same thing the incoming pointer is pointing at.
    previousNode = IncomingPreviousNodePointer;
}
void LinkedListNode::SetNextNodePointer(LinkedListNode* IncomingNexNodePointer)
{
    nextNode = IncomingNexNodePointer;
}
void LinkedListNode::SetIndexID(int IncomingAdjacencyListIndex)
{
    IndexID = IncomingAdjacencyListIndex;
}
LinkedListNode* LinkedListNode::GetPreviousNodePointer()
{
    return previousNode;
}
LinkedListNode* LinkedListNode::GetNextNodePointer()
{
    return nextNode;
}
int LinkedListNode::GetIndexID()
{
    return IndexID;
}


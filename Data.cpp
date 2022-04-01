//
// Created by Cody on 3/30/2022.
//
#include <iostream>
#include "Data.hpp"
using namespace std;

Data::Data()
{
    StartDate = 0;
    EndDate = 0;
    AmountWillingToPay = 0;
    IncomingEdges = 0;
    PointerToCorrespondingLinkedList = nullptr;
}
Data::Data(int Start, int End, int AmountToPay)
{
    StartDate = Start;
    EndDate = End;
    AmountWillingToPay = AmountToPay;
    IncomingEdges = 0;
    PointerToCorrespondingLinkedList = nullptr;
}

//Setters for private attributes (in case we need to do so later on in the program)
void Data::SetStartDate(int Start)
{
    StartDate = Start;
}
void Data::SetEndDate(int End)
{
    EndDate = End;
}
void Data::SetAmountWillingToPay(int AmountToPay)
{
    AmountWillingToPay = AmountToPay;
}
void Data::SetIncomingEdgesCount(int NumberOfIncomingEdges)
{
    IncomingEdges = NumberOfIncomingEdges;
}
void Data::SetIndexID(int WhereTheClientIsInTheAdjacencyListViaIndex)
{
    indexID = WhereTheClientIsInTheAdjacencyListViaIndex;
}
void Data::SetPointerToCorrespondingLinkedList(LinkedListNode* PointToThisLinkedList)
{
    PointerToCorrespondingLinkedList = PointToThisLinkedList;
}
//Getters for private attributes (in case we need to do so later on in the program)
int Data::GetStartDate()
{
    return StartDate;
}
int Data::GetEndDate()
{
    return EndDate;
}
int Data::GetAmountWillingToPay()
{
    return AmountWillingToPay;
}
int Data::GetIncomingEdgesCount()
{
    return IncomingEdges;
}
int Data::GetIndexID()
{
    return indexID;
}
LinkedListNode* Data::GetPointerToCorrespondingLinkedList()
{
    return PointerToCorrespondingLinkedList;
}

void Data::PrintData()
{
    //Print the data contents
    cout << endl;
    //Adding 1 because GetIndexID returns the position the client is in inside the adjacency list/vector. If we add 1 it will show a more human
    //readable version of a client numbering system
    cout << "Client " << this->GetIndexID() + 1 << " contains:" << endl;
    cout << "Start date: " << StartDate << endl;
    cout << "End date: " << EndDate << endl;
    cout << "Amount willing to pay: " << AmountWillingToPay << endl;
    //Then print the neighbors of this client using it's linked list
    //If this client's corresponding LinkedListNode's next pointer points to a nullptr, that means there is no neighbors for this client
    if (this->GetPointerToCorrespondingLinkedList() == nullptr)
    {
        //Thus we can print that there is no neighbors
        cout << "This client has no neighbors" << endl;
    }
    //Otherwise if our corresponding LinkedListNode has it's next pointer pointing to another LinkedListNode, we need to print the entirity of the linked list until we hit a nullptr
    else
    {
        cout << "It's neighbors are: ";
        //Creating a TemporaryHead pointer to travel through the linked list
        //Setting that temporary head equal to the start of the actual LinkedList
        LinkedListNode* TemporaryHead = this->GetPointerToCorrespondingLinkedList();
        //So long as our node we're at has it's next pointer to another actual node, i.e. it is not equal to nullptr,
        //we can print the indexID from the Data class that the LinkedListNode points back to
        while (TemporaryHead != nullptr)
        {
            //Print the indexID that the LinkedListNode has access to via it's Data class pointer
            cout << " " << TemporaryHead->GetIndexID() + 1 << "-> ";
            //Be sure to set the pointer we're at to point to the next node in the linked list
            TemporaryHead = TemporaryHead->GetNextNodePointer();
        }

    }
    cout << endl;


}
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
LinkedListNode* Data::GetPointerToCorrespondingLinkedList()
{
    return PointerToCorrespondingLinkedList;
}

void Data::PrintData()
{
    cout << endl;
    cout << "This Client/Graph Node/Vertex contains: " << endl;
    cout << "Start date: " << StartDate << endl;
    cout << "End date: " << EndDate << endl;
    cout << "Amount willing to pay: " << AmountWillingToPay << endl;
    cout << endl;
}
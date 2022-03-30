//
// Created by Cody on 3/30/2022.
//

#ifndef CS415PROJECT2_DATA_HPP
#define CS415PROJECT2_DATA_HPP
#include "LinkedListNode.hpp"


class Data
{
private:
    int StartDate;
    int EndDate;
    int AmountWillingToPay;
    int IncomingEdges;
    LinkedListNode* PointerToCorrespondingLinkedList;

public:
    //Constructor
    Data();
    //Parameterized Constructor
    Data(int Start, int End, int AmountToPay);

    //Setters for private attributes (in case we need to do so later on in the program)
    void SetStartDate(int Start);
    void SetEndDate(int End);
    void SetAmountWillingToPay(int AmountToPay);
    void SetIncomingEdgesCount(int NumberOfIncomingEdges);
    void SetPointerToCorrespondingLinkedList(LinkedListNode* PointToThisLinkedList);

    //Getters for private attributes (in case we need to do so later on in the program)
    int GetStartDate();
    int GetEndDate();
    int GetAmountWillingToPay();
    int GetIncomingEdgesCount();
    LinkedListNode* GetPointerToCorrespondingLinkedList();

    void PrintData();
};


#endif //CS415PROJECT2_DATA_HPP

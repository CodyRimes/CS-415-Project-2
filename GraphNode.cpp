//
// Created by Cody on 3/25/2022.
//

#include <iostream>
#include "GraphNode.hpp"

using namespace std;

//Constructor
GraphNode::GraphNode()
{
    //Intialize private attributes
    StartDate = 0;
    EndDate = 0;
    AmountWillingToPay = 0;
    previousNode = nullptr;
    nextNode = nullptr;

}
//Parameterized constructor for when we initially parse our input and initialize with those parsed values upon creation of a GraphNode
GraphNode::GraphNode(int Start, int End, int AmountToPay)
{
    StartDate = Start;
    EndDate = End;
    AmountWillingToPay = AmountToPay;
    previousNode = nullptr;
    nextNode = nullptr;
}
void GraphNode::SetStartDate(int Start)
{
    StartDate = Start;
}
void GraphNode::SetEndDate(int End)
{
    EndDate = End;
}
void GraphNode::SetAmountWillingToPay(int Amount)
{
    AmountWillingToPay = Amount;
}
int GraphNode::GetStartDate()
{
    return StartDate;
}
int GraphNode::GetEndDate()
{
    return EndDate;
}
int GraphNode::GetAmountWillingToPay()
{
    return AmountWillingToPay;
}
void GraphNode::printGraphNode()
{
    cout << endl;
    cout << "This Client/Graph Node/Vertex contains: " << endl;
    cout << "Start date: " << StartDate << endl;
    cout << "End date: " << EndDate << endl;
    cout << "Amount willing to pay: " << AmountWillingToPay << endl;
    cout << endl;
}
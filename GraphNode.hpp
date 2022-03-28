//
// Created by Cody on 3/25/2022.
//

#ifndef CS415PROJECT2_GRAPHNODE_HPP
#define CS415PROJECT2_GRAPHNODE_HPP

//input will in the format of start date, end date, and amount willing to pay, thus when parsing we must capture
//three integers (ex. 10, 40, 100 = the client starts on day 10, leaves on day 40, and is willing to pay $100)
class GraphNode
{
private:
    int StartDate;
    int EndDate;
    int AmountWillingToPay;

public:
    GraphNode();
    //Parameterized constructor
    GraphNode(int Start, int End, int AmountToPay);
    //Setters for private attributes (in case we need to do so later on in the program)
    void SetStartDate(int Start);
    void SetEndDate(int EndD);
    void SetAmountWillingToPay(int AmountToPay);
    //Getters for private attributes (in case we need to do so later on in the program)
    int GetStartDate();
    int GetEndDate();
    int GetAmountWillingToPay();
    void printGraphNode();


};


#endif //CS415PROJECT2_GRAPHNODE_HPP

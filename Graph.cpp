//
// Created by Cody on 3/25/2022.
//
#include <iostream>
#include <fstream>
#include "Graph.hpp"
//Constructor
Graph::Graph()
{
    //Initialize private variables
    NumberOfEdges = 0;
    NumberOfVertexNodes = 0;

}
//Parameterized constructor
Graph::Graph(string InputFileName)
{
    //Initialize private variables
    NumberOfEdges = 0;
    NumberOfVertexNodes = 0;

    //Creating an input file stream object called "inputFileStreamObject"
    ifstream inputFileStreamObject;

    //Opening the file given to us
    inputFileStreamObject.open(InputFileName);

    //Throw an error back to the user if we are unable to open the file
    if( ! inputFileStreamObject.is_open())
    {

        std::cout << "Make sure that " << InputFileName << " exists and is readable. Terminating.";
        exit(2);
    }
    else
    {
        cout << "We are able to read the file. Reading..." << endl;
    }

    //Creating variables to capture input from our input file
    int StartDate;
    int EndDate;
    int AmountWillingToPay;

    /*
    //Making a counter so for each iteration in our while loop we will be adding a client to
    //the appropriate spot in our adjacency list
    int counter = 0;
    */

    //NOTE: We need to parse one line of input, that being start day, end day, and amount willing to pay
    //We then need to put those three elements in a graph vertex/node
    //Put that graph vertex/node pointer into the appropriate spot into the vector adjacency list
    //Continue until you have reached the end of the file

    while (!inputFileStreamObject.eof())
    {
        //Getting a line of input from our input file and parsing it into the appropriate variables
        inputFileStreamObject >> StartDate >> EndDate >> AmountWillingToPay;
        //We then need to make a GraphNode object with these values
        GraphNode* GraphNodeToBePutInOurAdjacencyList = new GraphNode(StartDate, EndDate, AmountWillingToPay);
        //Now that we have our graph node, put it into our adjacency list that is a part of our Graph Object
        AddVertexNode(GraphNodeToBePutInOurAdjacencyList);

        /*
        //We've gone through one while loop iteration by this point, so increment our counter
        //so we can put the next GraphNode in the right spot in our adjacencylist
        counter = counter + 1;
         */
    }


    inputFileStreamObject.close();

}


//Add a graph node/vertex to our graph
void Graph::AddVertexNode(GraphNode* IncomingGraphNode)
{
    AdjacencyList.push_back(IncomingGraphNode);
}
//Add an edge to a particular vertex/graph node in our graph
void Graph::AddEdge(GraphNode* ClientToHaveEdgeAddedTo, GraphNode* ClientThatIsAPossiblePath)
{
    //First we need to make a copy of the ClientThatIsAPossiblePath's node, that way we don't mess up the original that's currently in the adjacency list
    GraphNode* CopyOfClientThatIsAPossiblePathNode = new GraphNode(ClientThatIsAPossiblePath->GetStartDate(), ClientThatIsAPossiblePath->GetEndDate(), ClientThatIsAPossiblePath->GetAmountWillingToPay());

    //We will then have the ClientToHaveEdgeAddedTo node nextNode pointer set to point to that ClientThatIsAPossiblePath node and vice versa (have the ClientThatIsAPossiblePath previous pointer set to point
    //back at the ClientToHaveEdgeAddedTo node)
    ClientToHaveEdgeAddedTo->SetNextNodePointer(CopyOfClientThatIsAPossiblePathNode);
    CopyOfClientThatIsAPossiblePathNode->SetPreviousNodePointer(ClientToHaveEdgeAddedTo);
}

void Graph::FindGraphEdgeConnections()
{
    //For each GraphNode/Client/Vertex in our starting adjacency list, lets see if we can add any edges
    //We add a edge when there is indeed a possible path for one client to another
    //"We make edges to indicate when there is no overlap" - Dr. Gill
    // i.e. we will only be adding edges in our adjacency list when two clients do not have overlapping time schedules and can be a part of a possible solution
    for (int i = 0; i < AdjacencyList.size(); i++)
    {
        //For this iteration of
        for (int j = i+1; j < AdjacencyList.size(); j++)
        {
            //If the client/GraphNode we're at's end date is less than or equal to the start date of the for loop that is looking at all other clients
            //then we can add this other client as an edge to our initial client
            if (AdjacencyList.at(i)->GetEndDate() <= AdjacencyList.at(j)->GetStartDate())
            {
                //Add the client at the jth position as an edge to the client at i
                AddEdge(AdjacencyList.at(i), AdjacencyList.at(j));
            }
        }
    }

}
void Graph::TopologicalSort()
{

}
void Graph::PrintGraph()
{
    for (int i = 0; i < AdjacencyList.size(); i++)
    {
        AdjacencyList.at(i)->printGraphNode();
    }
}

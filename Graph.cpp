//
// Created by Cody on 3/25/2022.
//
#include <iostream>
#include <fstream>
#include <queue>
#include "Graph.hpp"
#include "Data.hpp"
#include "LinkedListNode.hpp"

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
        //We then need to make a Data object with these values
        Data OurDataForAClient(StartDate, EndDate,AmountWillingToPay);
        //Now that we have our client's data, put it into our adjacency list that is a part of our Graph Object
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
void Graph::AddVertexNode(Data IncomingClientToBeAddedToAdjacencyList)
{
    AdjacencyList.push_back(IncomingClientToBeAddedToAdjacencyList);
}
//Add an edge to a particular vertex node in our adjacency list
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
        for (int j = 0; j < AdjacencyList.size(); j++)
        {
            //If the client/GraphNode we're at's end date is less than or equal to the start date of the for loop that is looking at all other clients
            //then we can add this other client as an edge to our initial client
            if (AdjacencyList.at(i)->GetEndDate() <= AdjacencyList.at(j)->GetStartDate())
            {
                //Add the client at the jth position as an edge to the client at i
                AddEdge(AdjacencyList.at(i), AdjacencyList.at(j));
                //Since we know that the client at the jth position now has a an incoming edge from the client at the ith position, we need to account for that in our graph node and add an edge to that graph node
                AdjacencyList.at(j)->SetIncomingEdgesCount(AdjacencyList.at(j)->GetIncomingEdgesCount() + 1);
            }
        }
    }

}
//Topological sort of the adjacency list using Breadth First Search (BFS i.e. queue method)
void Graph::TopologicalSort()
{
    //"First visit all edges, counting the number of edges that lead to each vertex (i.e., count the number of prerequisites for each vertex).
    //All vertices with no prerequisites are placed on the queue. We then begin processing the queue.
    //When Vertex v is taken off of the queue, it is printed, and all neighbors of v (that is, all vertices that have v as a prerequisite) have their counts decremented by one.
    //Place on the queue any neighbor whose count becomes zero.
    //If the queue becomes empty without printing all of the vertices, then the graph contains a cycle (i.e., there is no possible ordering for the tasks that does not violate some prerequisite)."

    //In our FindGraphEdgeConnections function, we have walked through each of the graph nodes that were initially in our adjacency list (i.e. we parsed the input, and each line was an initial client that was the start/head of each linked
    //list in our array. No edges had been added each client yet) and added appropriate edges if they met the criteria of if the end date of a particular client was less than equal to the start date of another client,
    //we could go ahead and add that edge.
    //We will now be using a modified version of Topological sort in order to find the optimal revenue path that would give us the most bang for our buck
    // We will be using the Breadth First Search method (queue) to sort through those edges

    //Create the queue to push GraphNodes that have incoming edge counts of zero to
    queue <GraphNode*> OurTopologicalSortQueue;
    int edges = 0;
    //Walk through the adjacency list (we should only need to visit the first node/head of each linked list in the adjacency list)
    for (int i = 0; i < AdjacencyList.size(); i++)
    {
        //If the incoming edge count of a particular client/graph node in the adjacency list is 0..
        if (AdjacencyList.at(i)->GetIncomingEdgesCount() == 0)
        {
            //We push that client/graph node into our queue
            OurTopologicalSortQueue.push(AdjacencyList.at(i));
	    
	}
    }
    

}




void Graph::PrintGraph()
{
    for (int i = 0; i < AdjacencyList.size(); i++)
    {
        AdjacencyList.at(i)->printGraphNode();
    }
}

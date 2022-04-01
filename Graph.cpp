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


    //Making a counter so for each iteration in our while loop we will be adding a client to
    //the appropriate spot in our adjacency list
    int counter = 0;


    //NOTE: We need to parse one line of input, that being start day, end day, and amount willing to pay
    //We then need to put those three elements in a graph vertex/node
    //Put that graph vertex/node pointer into the appropriate spot into the vector adjacency list
    //Continue until you have reached the end of the file

    while (!inputFileStreamObject.eof())
    {
        //Getting a line of input from our input file and parsing it into the appropriate variables
        inputFileStreamObject >> StartDate >> EndDate >> AmountWillingToPay;
        //We then need to make a Data object with these values
        Data* OurDataForAClient = new Data(StartDate, EndDate,AmountWillingToPay);
        //Data* OurDataForAClient = new Data(StartDate, EndDate,AmountWillingToPay);
        //Lets make a LinkedListNode object for our client to start it's linked list
        LinkedListNode* ClientsLinkedList = new LinkedListNode();

        /////////////////////////////////////
        //Note why to not use this method:
        //Dr. Gondree: "If you use this method the object is made in the stack, and every time this while loop runs CLientLinkedList2 will be overwritten. Where as the above method
        //is put into the heap, and will not overwritten and then lost when this while loop terminates."
        //Test this theory
        //LinkedListNode ClientsLinkedList2;
        //OurDataForAClient.SetPointerToCorrespondingLinkedList(&ClientsLinkedList2);
        /////////////////////////////////////

        //We need to point that Data object to its LinkedListNode object
        OurDataForAClient->SetPointerToCorrespondingLinkedList(ClientsLinkedList);


        //Now point the LinkedListNode back at the corresponding clients data. We can do that by passing our Data object by reference
        ClientsLinkedList->SetPointerToDataForAParticularClient(OurDataForAClient);

        //Use our counter to correctly track where this client would be pushed into the vector i.e. our adjacencyList
        OurDataForAClient->SetIndexID(counter);

        //Now that we have our client's data, put it into our adjacency list that is a part of our Graph Object
        AddVertexNode(*OurDataForAClient);

        /*
        AdjacencyList.at(counter).SetPointerToCorrespondingLinkedList(ClientsLinkedList);
        ClientsLinkedList->SetPointerToDataForAParticularClient(&(AdjacencyList[counter]));
        AdjacencyList.at(counter).SetIndexID(counter);
        */

        //We've gone through one while loop iteration by this point, so increment our counter
        //so we can put the next GraphNode in the right spot in our adjacencylist
        counter = counter + 1;

    }


    inputFileStreamObject.close();

}


//Add a graph node/vertex to our graph
void Graph::AddVertexNode(Data IncomingClientToBeAddedToAdjacencyList)
{
    AdjacencyList.push_back(IncomingClientToBeAddedToAdjacencyList);
}
//Add an edge to a particular vertex node in our adjacency list
void Graph::AddEdge(Data ClientToHaveEdgeAddedTo, Data ClientThatIsAPossiblePath)
{

    //We have two Data objects. One is the client that needs to have the edge added to, and one is the client that needs to be connected to the client that needs an edge added to.
    //To do that we must first make another LinkedListNode object
    LinkedListNode* LinkedListToBeAdded = new LinkedListNode();

    //If the client to have it's edge added to has it's linked list node's next pointer pointing to null, that means besides it's first node in it's linked list (which references the data itself), it has no
    //nodes in it's linked list. We should add our new node following that default node
    if (ClientToHaveEdgeAddedTo.GetPointerToCorrespondingLinkedList()->GetNextNodePointer() == nullptr)
    {
        //Then we need to have client that needs its edge added to LinkedListNode to point to that LinkedListNode we are adding
        ClientToHaveEdgeAddedTo.GetPointerToCorrespondingLinkedList()->SetNextNodePointer(LinkedListToBeAdded);
        //Now we need to have the LinkedListNode that is to be added point back at the client's corresponding linked list as well
        LinkedListToBeAdded->SetPreviousNodePointer(ClientToHaveEdgeAddedTo.GetPointerToCorrespondingLinkedList());
        //Finally we need to point the LinkedListNode that we want to add to be point at the appropriate client's data
        //LinkedListToBeAdded->SetPointerToDataForAParticularClient(ClientThatIsAPossiblePath.GetPointerToCorrespondingLinkedList()->GetPointerToDataForAParticularClient());
        //Would this work?
        LinkedListToBeAdded->SetPointerToDataForAParticularClient(&ClientThatIsAPossiblePath);
    }
    //Otherwise we have client that has a developed linked list and we must first reach the end of that linked list so we can add the new node to the end of the list
    else
    {
        LinkedListNode* TemporaryHead = ClientToHaveEdgeAddedTo.GetPointerToCorrespondingLinkedList();

        while (TemporaryHead->GetNextNodePointer() != nullptr)
        {
            TemporaryHead = TemporaryHead->GetNextNodePointer();
        }
        //Since we've broken this while loop we now know the node we're at has a NextNodePointer equal to nullptr. We want to change that
        TemporaryHead->SetNextNodePointer(LinkedListToBeAdded);
        //The node to be added should also point back at the former "end" of the linked list
        LinkedListToBeAdded->SetPreviousNodePointer(TemporaryHead);
        //Finally we need to also make sure our LinkedListNode to be added is pointing at the correct client it is to be referencing
        //LinkedListToBeAdded->SetPointerToDataForAParticularClient(ClientThatIsAPossiblePath.GetPointerToCorrespondingLinkedList()->GetPointerToDataForAParticularClient());
        LinkedListToBeAdded->SetPointerToDataForAParticularClient(&ClientThatIsAPossiblePath);
    }


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
            if (AdjacencyList.at(i).GetEndDate() <= AdjacencyList.at(j).GetStartDate())
            {
                //Add the client at the jth position as an edge to the client at i
                AddEdge(AdjacencyList.at(i), AdjacencyList.at(j));


                //Since we know that the client at the jth position now has a an incoming edge from the client at the ith position, we need to account for that in our graph node and add an edge to that graph node
                AdjacencyList.at(j).SetIncomingEdgesCount(AdjacencyList.at(j).GetIncomingEdgesCount() + 1);
            }
        }
    }

}
/*
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

    //Walk through the adjacency list (we should only need to visit the first node/head of each linked list in the adjacency list)
    for (int i = 0; i < AdjacencyList.size(); i++)
    {
        //If the incoming edge count of a particular client/graph node in the adjacency list is 0..
        if (AdjacencyList.at(i)->GetIncomingEdgesCount() == 0)
        {
            //We push that client/graph node into our queue
            OurTopologicalSortQueue.push(AdjacencyList.at(i));
            //We then need to decrement that graph node's neighbor's edge counts by one. Note how in our adjacency list all neighbors are attached to this graph node in the same linked list

        }
    }

}
 */
void Graph::PrintGraph()
{
    for (int i = 0; i < AdjacencyList.size(); i++)
    {
        AdjacencyList.at(i).PrintData();
    }
}
void Graph::PrintLinkedList()
{

}

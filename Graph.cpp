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
    /*
    else
    {
        cout << "We are able to read the file. Reading..." << endl;
    }
     */

    //Creating variables to capture input from our input file
    int StartDate;
    int EndDate;
    int AmountWillingToPay;


    //Making a counter so for each iteration in our while loop we will be adding a client to
    //the appropriate spot in our adjacency list
    int counter = 0;

    //Hard code the start node of the graph into the adjacency list
    //Data* DummyStartNode = new Data(0,0,0);
    //Set it's index ID (should be zero since it's the start of the graph and should be the first thing entered into our adjacency list). Use the counter.
    //DummyStartNode->SetIndexID(counter);
    //And input it into the adjacency list vector
    //AddVertexNode(*DummyStartNode);
    //Then increment the counter to reflect the addition so when we add nodes further along down the code we will have the correct reference to the correct index position they were entered into
    //counter = counter + 1;


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
        //LinkedListNode* ClientsLinkedList = new LinkedListNode();

        /////////////////////////////////////
        //Note why to not use this method:
        //Dr. Gondree: "If you use this method the object is made in the stack, and every time this while loop runs CLientLinkedList2 will be overwritten. Where as the above method
        //is put into the heap, and will not overwritten and then lost when this while loop terminates."
        //Test this theory
        //LinkedListNode ClientsLinkedList2;
        //OurDataForAClient.SetPointerToCorrespondingLinkedList(&ClientsLinkedList2);
        /////////////////////////////////////

        //We need to point that Data object to its LinkedListNode object
        //OurDataForAClient->SetPointerToCorrespondingLinkedList(ClientsLinkedList);


        //Giving a reference for the linked list to refer back to via the index of where the client will be stored inside the adjacency list/vector
        //ClientsLinkedList->SetIndexID(counter);

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

    //We are done entering in input from the input file, but we still need to enter the last dummy node, which will represent the end node in our graph. Lets do that now
    //Hard code the end node of the graph into the adjacency list
    //Data* DummyEndNode = new Data(99999999999,999999999990909,0);
    //Set it's index ID. Use the counter that we've been incrementing earlier in the while loop above
    //DummyEndNode->SetIndexID(counter);
    //And input it into the adjacency list vector
    //AddVertexNode(*DummyEndNode);
    //Then increment the counter for safe measure, just in case ;) (it's good practice)
    //counter = counter + 1;

    inputFileStreamObject.close();

}


//Add a graph node/vertex to our graph
void Graph::AddVertexNode(Data IncomingClientToBeAddedToAdjacencyList)
{
    AdjacencyList.push_back(IncomingClientToBeAddedToAdjacencyList);
}
//Add an edge to a particular vertex node in our adjacency list
void Graph::AddEdge(Data &ClientToHaveEdgeAddedTo, Data &ClientThatIsAPossiblePath)
{

    //We have two Data objects. One is the client that needs to have the edge added to, and one is the client that needs to be connected to the client that needs an edge added to.
    //To do that we must first make another LinkedListNode object
    LinkedListNode* LinkedListToBeAdded = new LinkedListNode();

    //If the client to have it's edge added to has it's linked list node's next pointer pointing to null, that means besides it's first node in it's linked list (which references the data itself), it has no
    //nodes in it's linked list. We should add our new node following that default node
    if (ClientToHaveEdgeAddedTo.GetPointerToCorrespondingLinkedList() == nullptr)
    {
        //Then we need to have client that needs its edge added to LinkedListNode to point to that LinkedListNode we are adding
        ClientToHaveEdgeAddedTo.SetPointerToCorrespondingLinkedList(LinkedListToBeAdded);
        //Now we need to have the LinkedListNode that is to be added point back at the client's corresponding linked list as well
        //LinkedListToBeAdded->SetPreviousNodePointer(ClientToHaveEdgeAddedTo.GetPointerToCorrespondingLinkedList());
        //Finally we need to point the LinkedListNode that we want to add to be point at the appropriate client's data
        //LinkedListToBeAdded->SetPointerToDataForAParticularClient(ClientThatIsAPossiblePath.GetPointerToCorrespondingLinkedList()->GetPointerToDataForAParticularClient());
        //Would this work?
        LinkedListToBeAdded->SetIndexID(ClientThatIsAPossiblePath.GetIndexID());
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
        LinkedListToBeAdded->SetIndexID(ClientThatIsAPossiblePath.GetIndexID());
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
//Since we are not using a start vertex for our program, all vertexes in our adjacency list that start with an incoming edge count of 0 are source nodes, and we need to store those source nodes
//for when we do our topological sort and later on in our program for calculating the path with max value
void Graph::AddSourceVertexes()
{
    for (int i = 0; i < AdjacencyList.size(); i++)
    {
        if (AdjacencyList.at(i).GetIncomingEdgesCount() == 0)
        {
            SourceVertexes.push_back(AdjacencyList.at(i));
        }

    }
}

//Topological sort of the adjacency list using Breadth First Search (BFS i.e. queue method)
vector<Data> Graph::TopologicalSort()
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

    vector<Data> TopologicallySortedGraph;

    //Create the queue to push GraphNodes that have incoming edge counts of zero to
    queue<Data> OurTopologicalSortQueue;

    //Since all of our source nodes have incoming edges equal to zero, push them in
    for (int i = 0; i < SourceVertexes.size(); i++) {
        //Push into the queue
        OurTopologicalSortQueue.push(SourceVertexes.at(i));
        //Mark those source vertexes as seen and processed in the corresponding adjacency list
        AdjacencyList.at(SourceVertexes.at(i).GetIndexID()).SetHasItBeenSeenBefore(true);
        //Decrement the edge count in the neighbors of source nodes
        //We'll need a temporary pointer to the linked list of our source node's in the adjacency list

        if (AdjacencyList.at(SourceVertexes.at(i).GetIndexID()).GetPointerToCorrespondingLinkedList() == nullptr)
        {
            ;
            //cout << "Client " << AdjacencyList.at(SourceVertexes.at(i).GetIndexID()).GetIndexID() + 1 << " does not have any neighbors" << endl;
        }
            //If the temporary pointer to the adjacency list does not come back as a nullptr, it must have a linked list it's pointing to
        else {
            //Lets set a temporary LinkedListNode pointer to where the adjacency list is pointing to
            LinkedListNode *TemporaryHead = AdjacencyList.at(
                    SourceVertexes.at(i).GetIndexID()).GetPointerToCorrespondingLinkedList();

            //We need to travel down the linked list as well, so use a while loop to keep going down the neighbors
            while (TemporaryHead != nullptr)
            {
                //We need to decrement all neighbors edge counts
                AdjacencyList.at(TemporaryHead->GetIndexID()).SetIncomingEdgesCount(AdjacencyList.at(TemporaryHead->GetIndexID()).GetIncomingEdgesCount() - 1);

                //Travel down the linked list
                TemporaryHead = TemporaryHead->GetNextNodePointer();
            }
            //We've broken the while loop so we must have processed the last neighbor (which would have pointed next to a nullptr)
        }
    }




    //while our queue is not empty
    while (OurTopologicalSortQueue.size() > 0)
    {
        //We need to walk through the adjacency list
        for (int i = 0; i < AdjacencyList.size(); i++)
        {
            //If the incoming edge count of a particular client/graph node in the adjacency list is 0..
            if (AdjacencyList.at(i).GetIncomingEdgesCount() == 0 && AdjacencyList.at(i).GetHasItBeenSeenBefore() == false)
            {
                //We push that client/graph node into our queue
                OurTopologicalSortQueue.push(AdjacencyList.at(i));
                //We need to mark it as seen before
                AdjacencyList.at(i).SetHasItBeenSeenBefore(true);

                //We then need to check if it has neighbors
                if (AdjacencyList.at(i).GetPointerToCorrespondingLinkedList() == nullptr)
                {
                    ;
                    //cout << "Client " << AdjacencyList.at(i).GetIndexID() + 1 << " does not have any neighbors" << endl;
                }
                    //If the temporary pointer to the adjacency list does not come back as a nullptr, it must have a linked list it's pointing to
                else
                {
                    //Lets set a temporary LinkedListNode pointer to where the adjacency list is pointing to
                    LinkedListNode *TemporaryHead2 = AdjacencyList.at(i).GetPointerToCorrespondingLinkedList();

                    //We need to travel down the linked list as well, so use a while loop to keep going down the neighbors
                    while (TemporaryHead2 != nullptr)
                    {
                        //We need to decrement all neighbors edge counts
                        AdjacencyList.at(TemporaryHead2->GetIndexID()).SetIncomingEdgesCount(
                                AdjacencyList.at(TemporaryHead2->GetIndexID()).GetIncomingEdgesCount() - 1);

                        //Travel down the linked list
                        TemporaryHead2 = TemporaryHead2->GetNextNodePointer();
                    }
                    //We've broken the while loop so we must have processed the last neighbor (which would have pointed next to a nullptr)
                }

            }

        }
        //We need to capture whatever is in front of the queue
        Data OurTemporaryHolderForDataInQueue = OurTopologicalSortQueue.front();
        //Push what is in front of the queue to the vector that will store the topological sorted graph
        TopologicallySortedGraph.push_back(OurTemporaryHolderForDataInQueue);
        //pop the front element in the queue to get the element that was inserted after it (remember a queue is a FIFO structure)
        OurTopologicalSortQueue.pop();
    }

    return TopologicallySortedGraph;

}
/*
//Given a data object
Data Graph::GetMaxNeighbor(Data NodeToFindMaximumNeighborFor)
{
    //Make a data object that is ready to be filled with the appropriate values
    Data OurDataObjectToPassBack;

    //Check the adjacency linked list to see if the node we want even has a linked list
    if (AdjacencyList.at(NodeToFindMaximumNeighborFor.GetIndexID()).GetPointerToCorrespondingLinkedList() == nullptr)
    {
        cout << "The node you wanted a maximum neighbor for does not have any neighbors" << endl;
        return NodeToFindMaximumNeighborFor;
    }
    //If the else statement runs we have a linked list to check the maximum value for
    else
    {
        //Lets set a temporary LinkedListNode pointer to where the adjacency list is pointing to
        LinkedListNode *TemporaryHead3 = AdjacencyList.at(NodeToFindMaximumNeighborFor.GetIndexID()).GetPointerToCorrespondingLinkedList();

        //We need to travel down the linked list as well, so use a while loop to keep going down the neighbors list
        while (TemporaryHead3 != nullptr)
        {
            //We need compare if the node we're at has a larger value than our holder variable, if it does, set the holder variable to that larger value
            if (AdjacencyList.at(TemporaryHead3->GetIndexID()).GetAmountWillingToPay() > OurDataObjectToPassBack.GetAmountWillingToPay());
            {
                //Set everything in our once empty data object equal to the neighbor in the linked list that has a higher amount will to pay than what our data object to pass back currently holds
                OurDataObjectToPassBack.SetHasItBeenSeenBefore(AdjacencyList.at(TemporaryHead3->GetIndexID()).GetHasItBeenSeenBefore());
                OurDataObjectToPassBack.SetIncomingEdgesCount(AdjacencyList.at(TemporaryHead3->GetIndexID()).GetIncomingEdgesCount());
                OurDataObjectToPassBack.SetIndexID(AdjacencyList.at(TemporaryHead3->GetIndexID()).GetIndexID());
                OurDataObjectToPassBack.SetPointerToCorrespondingLinkedList(AdjacencyList.at(TemporaryHead3->GetIndexID()).GetPointerToCorrespondingLinkedList());
                OurDataObjectToPassBack.SetEndDate(AdjacencyList.at(TemporaryHead3->GetIndexID()).GetEndDate());
                OurDataObjectToPassBack.SetStartDate(AdjacencyList.at(TemporaryHead3->GetIndexID()).GetStartDate());
                OurDataObjectToPassBack.SetSum(AdjacencyList.at(TemporaryHead3->GetIndexID()).GetSum());
                OurDataObjectToPassBack.SetAmountWillingToPay(AdjacencyList.at(TemporaryHead3->GetIndexID()).GetAmountWillingToPay());


            }
            //Travel down the linked list
            TemporaryHead3 = TemporaryHead3->GetNextNodePointer();
        }
    }

    return OurDataObjectToPassBack;
}
*/

void Graph::GetMaxPath()
{

    //Declare vector to capture topological sort of our graph
    vector<Data> TopologicallySortedGraph;

    //Receive the topologically sorted vector
    TopologicallySortedGraph = this->TopologicalSort();

    //Make sure the vector that holds all sum values is the same size as the topologically sorted vector
    SumValues.resize(TopologicallySortedGraph.size());

    //Make sure the vector that holds all sum positions is the same size as the topologically sorted vector
    PositionsOfSumValues.resize(TopologicallySortedGraph.size());

    //Declare the variables that will be used to hold the values we will be pushing into their appropriate vectors
    int LargestNeighborValue = 0;
    int LargestNeighborIndexPosition = 0;

    //We need to walk through the topologically sorted vector in reverse
    for (int i = TopologicallySortedGraph.size() - 1; i > 0; i--) {

        //Take the maximum value of the  neighbor of the vertex we're at, and sum it with the vertex we're at and store it in the sum values vector
        //Check the adjacency linked list to see if the node we want even has a linked list
        if (AdjacencyList.at(TopologicallySortedGraph.at(i).GetIndexID()).GetPointerToCorrespondingLinkedList() == nullptr)
        {
            //cout << "The node you wanted a maximum neighbor for does not have any neighbors" << endl;
            //Store the largest value we've seen so far
            LargestNeighborValue = AdjacencyList.at(TopologicallySortedGraph.at(i).GetIndexID()).GetAmountWillingToPay();
            //And capture the index position of that neighbor's position in the adjacency list
            LargestNeighborIndexPosition = AdjacencyList.at(TopologicallySortedGraph.at(i).GetIndexID()).GetIndexID();
        }
            //If the else statement runs we have a linked list to check the maximum value for
        else
            {
            //Lets set a temporary LinkedListNode pointer to where the adjacency list is pointing to
            LinkedListNode *TemporaryHead3 = AdjacencyList.at(TopologicallySortedGraph.at(i).GetIndexID()).GetPointerToCorrespondingLinkedList();

            //We need to travel down the linked list as well, so use a while loop to keep going down the neighbors list
            while (TemporaryHead3 != nullptr)
            {
                //We need compare if the node we're at has a larger value than our holder variable, if it does, set the holder variable to that larger value
                if (AdjacencyList.at(TemporaryHead3->GetIndexID()).GetAmountWillingToPay() > LargestNeighborValue);
                {
                    //Store the largest value we've seen so far
                    LargestNeighborValue = AdjacencyList.at(TemporaryHead3->GetIndexID()).GetAmountWillingToPay() + AdjacencyList.at(TopologicallySortedGraph.at(i).GetIndexID()).GetAmountWillingToPay();
                    //Now set the Adjacency's list amount willing to pay with the summed value stored in LargestNeighborValue, so if we ever reference it again we'll get the correct value
                    AdjacencyList.at(TemporaryHead3->GetIndexID()).SetAmountWillingToPay(LargestNeighborValue);
                    //And capture the index position of that neighbor's position in the adjacency list
                    LargestNeighborIndexPosition = AdjacencyList.at(TemporaryHead3->GetIndexID()).GetIndexID();

                }
                //Travel down the linked list
                TemporaryHead3 = TemporaryHead3->GetNextNodePointer();
            }
        }
        //Now that we have the Largest Neighbor's value for this particular vertex we are at in our topologically sorted vector, we now need to place it into the appropriate vector at the appropriate position
        SumValues.at(i) = LargestNeighborValue;
        //Now that we have the Largest Neighbor's index position for this particular vertex we are at in our topologically sorted vector, we now need to place it into the appropriate vector at the appropriate position
        PositionsOfSumValues.at(i) = LargestNeighborIndexPosition;


    }


}






void Graph::PrintGraph()
{
    for (int i = 0; i < AdjacencyList.size(); i++)
    {
        AdjacencyList.at(i).PrintData();
    }
}




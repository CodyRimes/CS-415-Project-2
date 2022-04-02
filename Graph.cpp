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

    //Hard code the start node of the graph into the adjacency list
    Data* DummyStartNode = new Data(0,0,0);
    //Set it's index ID (should be zero since it's the start of the graph and should be the first thing entered into our adjacency list). Use the counter.
    DummyStartNode->SetIndexID(counter);
    //And input it into the adjacency list vector
    AddVertexNode(*DummyStartNode);
    //Then increment the counter to reflect the addition so when we add nodes further along down the code we will have the correct reference to the correct index position they were entered into
    counter = counter + 1;


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
    Data* DummyEndNode = new Data(99999999999,999999999990909,0);
    //Set it's index ID. Use the counter that we've been incrementing earlier in the while loop above
    DummyEndNode->SetIndexID(counter);
    //And input it into the adjacency list vector
    AddVertexNode(*DummyEndNode);
    //Then increment the counter for safe measure, just in case ;) (it's good practice)
    counter = counter + 1;

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
    queue <Data> OurTopologicalSortQueue;

    //Walk through the adjacency list (we should only need to visit the first node/head of each linked list in the adjacency list)
    for (int i = 0; i < AdjacencyList.size(); i++)
    {
        //If the incoming edge count of a particular client/graph node in the adjacency list is 0..
        if (AdjacencyList.at(i).GetIncomingEdgesCount() == 0)
        {
            //We push that client/graph node into our queue
            OurTopologicalSortQueue.push(AdjacencyList.at(i));

            //While the size of our queue is greater than 0
            while(OurTopologicalSortQueue.size() > 0)
            {
                //We need to capture whatever is in front of the queue
                Data OurTemporaryHolderForDataInQueue = OurTopologicalSortQueue.front();
                //Push what is in front of the queue to the vector that will store the topological sorted graph
                TopologicallySortedGraph.push_back(OurTemporaryHolderForDataInQueue);
                //pop the front element in the queue to get the element that was inserted after it (remember a queue is a FIFO structure)
                OurTopologicalSortQueue.pop();
                //If the data that was represented at the front of our queue was not marked as seen before
                if (AdjacencyList.at(OurTemporaryHolderForDataInQueue.GetIndexID()).GetHasItBeenSeenBefore()==false)
                {
                    //We need to mark it as seen
                    AdjacencyList.at(OurTemporaryHolderForDataInQueue.GetIndexID()).SetHasItBeenSeenBefore(true);

                    //If this client has no neighbors we would expect to see a nullptr
                    if (AdjacencyList.at(OurTemporaryHolderForDataInQueue.GetIndexID()).GetPointerToCorrespondingLinkedList() == nullptr)
                    {
                        cout << " Client " << AdjacencyList.at(OurTemporaryHolderForDataInQueue.GetIndexID()).GetIndexID() << "does not have any neighbors" << endl;
                    }

                    //Otherwise we should expect a linked list of neighbors
                    else
                    {
                        //We then need to visit all of the neighbors for this particular client, so lets set a variable equal to the linked list
                        LinkedListNode* TemporaryHead = AdjacencyList.at(OurTemporaryHolderForDataInQueue.GetIndexID()).GetPointerToCorrespondingLinkedList();

                        while (TemporaryHead != nullptr)
                        {

                        //We need to decrement all neighbors edge counts
                        AdjacencyList.at(TemporaryHead->GetIndexID()).SetIncomingEdgesCount(AdjacencyList.at(TemporaryHead->GetIndexID()).GetIndexID() - 1);
                        //any neighbors that have edge counts equal to zero also need to be pushed into the queue
                        if (AdjacencyList.at(TemporaryHead->GetIndexID()).GetIncomingEdgesCount() == 0)
                        {
                            //Push what is held at the adjacency list (using the linked list reference) into the queue
                            OurTopologicalSortQueue.push(AdjacencyList.at(TemporaryHead->GetIndexID()));
                            //Since we are accounting for neighbors that have edge counts equal to zero and have pushed them into the queue, we need to mark them as seen so we don't process them again
                            AdjacencyList.at(TemporaryHead->GetIndexID()).SetHasItBeenSeenBefore(true);
                        }
                        //Travel down the linked list
                        TemporaryHead = TemporaryHead->GetNextNodePointer();
                        }

                    }


                }

            }

            /*
            //Set that client in the adjacency list as seen before by this topological sort
            AdjacencyList.at(i).SetHasItBeenSeenBefore(true);

            //We then need to decrement that graph node's neighbor's edge counts by one. Note how in our adjacency list all neighbors are attached to this client in it's linked list
            //if it has a neighbor, the corresponding linked list pointer will not be null
            if (AdjacencyList.at(i).GetPointerToCorrespondingLinkedList() != nullptr)
            {
                //Make a temporary pointer to that neighbor
                LinkedListNode* TemporaryHead = AdjacencyList.at(i).GetPointerToCorrespondingLinkedList();
                //Get that neighbors reference index back to the adjacency graph
                int IndexReference = TemporaryHead->GetIndexID();
                //Correct the incoming edge count at the adjacency list of that neighbor in this linked list
                AdjacencyList.at(IndexReference).SetIncomingEdgesCount(AdjacencyList.at(IndexReference).GetIncomingEdgesCount() - 1);

                //If there's another node in the linked list
                while (TemporaryHead->GetNextNodePointer() != nullptr)
                {
                    //Move to it
                    TemporaryHead = TemporaryHead->GetNextNodePointer();
                    //And do the same thing as the lines above
                    IndexReference = TemporaryHead->GetIndexID();
                    AdjacencyList.at(IndexReference).SetIncomingEdgesCount(AdjacencyList.at(IndexReference).GetIncomingEdgesCount() - 1);
                }
                //Once we break this while loop we know there are no more nodes in the linked list to process
            }

            else
            {
                cout << "Client " << AdjacencyList.at(i).GetIndexID() << "at index position in the adjacency list " << i << " does not have any neighbors to decrement and has zero incoming edges" << endl;
            }
            //We now have handled decrementing the neighbors one particular client that has zero incoming edges
                */
        }




    }
    //Once we have walked through the entire adjacency list, we may have affected edge counts in later iterations of the for loop of iterations that were near the beginning of the for loop
    //How do we account for that????????????????????????

    //While the queue isn't empty, we need to do the logic that is inside this while loop
    while (!OurTopologicalSortQueue.empty())
    {
        //We need to capture whatever is in front of the queue
        Data OurTemporaryHolderForDataInQueue = OurTopologicalSortQueue.front();
        //Push what is in front of the queue to the vector that will store the topological sorted graph
        TopologicallySortedGraph.push_back(OurTemporaryHolderForDataInQueue);
        //pop the front element in the queue to get the element that was inserted after it (remember a queue is a FIFO structure)
        OurTopologicalSortQueue.pop();
    }

    return TopologicallySortedGraph;
}

void Graph::PrintGraph()
{
    for (int i = 0; i < AdjacencyList.size(); i++)
    {
        AdjacencyList.at(i).PrintData();
    }
}




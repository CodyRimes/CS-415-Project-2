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

    int temp;

    // get first value from inputFileStreamObject
    inputFileStreamObject >> temp;

    //Now that we are able to read the file, fill the vector

    //NOTE: We need to parse one line of input, that being start day, end day, and amount willing to pay
    //We then need to put those three elements in a graph vertex/node
    //Put that graph vertex/node pointer into the appropriate spot into the vector adjacency list
    //Continue until you have reached the end of the file
    while (!inputFileStreamObject.eof())
    {
        cout << "We are before the vector push" << endl;
        cout << temp << endl;
        DataFromInputFile.push_back(temp);
        inputFileStreamObject >> temp;
        cout << "We are before the vector push" << endl;

    }
    inputFileStreamObject.close();

}

//Add a graph node/vertex to our graph
void Graph::AddVertexNode()
{

}
//Add an edge to a particular vertex/graph node in our graph
void Graph::AddEdge()
{

}
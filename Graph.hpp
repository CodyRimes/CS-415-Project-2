//
// Created by Cody on 3/25/2022.
//This will be our directed acyclic graph (DAG)
//It will hold vertexes that are on the graph via an adjacency matrix
//.i.e. a vector, with each index holding a pointer to the start of a linked list


#ifndef CS415PROJECT2_GRAPH_HPP
#define CS415PROJECT2_GRAPH_HPP

#include "GraphNode.hpp"
#include "Data.hpp"
#include "LinkedListNode.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace std;



class Graph
{
private:
    int NumberOfEdges;
    int NumberOfVertexNodes;
    vector <Data> AdjacencyList;
    //Do we need these?
    GraphNode* StartNode;
    GraphNode* EndNode;
public:
    //Constructor
    Graph();
    //Parameterized constructor
    Graph(string InputFileName);
    void AddEdge(Data&, Data&);
    void AddVertexNode(Data);
    void AddSourceVertexes();
    vector <Data> TopologicalSort();
    void FindGraphEdgeConnections();
    void PrintGraph();

    //Data GetMaxNeighbor(Data NodeToFindMaximumNeighborFor);
    void GetMaxPath();
    //Declaring a vector to hold sum values for optimal path
    vector<int> SumValuesAKAFvalues;
    //Declaring a vector to hold positions of max neighbor
    vector<int> PositionsOfSumValuesAKAFvalues;
    vector <Data> SourceVertexes;



};


#endif //CS415PROJECT2_GRAPH_HPP

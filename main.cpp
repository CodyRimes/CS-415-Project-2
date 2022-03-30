#include "Graph.hpp"
#include "LinkedListNode.hpp"
#include "Data.hpp"
#include "GraphNode.hpp"
#include <iostream>

using namespace std;

int main()
{
    string FileName;

    //When we first make our graph, it will need a text file as input to be passed to it's parameterized constructor so it can parse that input data as vertex's/nodes of it's graph
    cout << "Enter the file to read data: " << endl;
    cin >> FileName;

    //Create a graph object with the file name to open given to us above
    Graph OurGraphObject(FileName);
    OurGraphObject.PrintGraph();

    /*
    cout << "There are " + " clients in this file" << endl;

    cout << "Optimal revenue earned is " << endl;
    cout << "Cliets contributing to this optimal revenue: " << endl;
    */












    return 0;
}

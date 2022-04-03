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
    cout << "Enter the file to read data: ";
    cin >> FileName;

    //Create a graph object with the file name to open given to us above
    Graph OurGraphObject(FileName);
    OurGraphObject.FindGraphEdgeConnections();
    OurGraphObject.AddSourceVertexes();
    //OurGraphObject.PrintGraph();
    vector <Data> CaptureMe;
    CaptureMe = OurGraphObject.TopologicalSort();

    //Close but no cigar
    //OurGraphObject.GetMaxPath();


    //CaptureMe = OurGraphObject.GetMaxPath();
    //cout << "The size of our topological sorted vector is: ";
    //cout << CaptureMe.size();
    //cout << endl;

    cout << "There are " << CaptureMe.size() << " clients in this file" << endl;

    for (int i = 0; i < CaptureMe.size(); i++)
    {
        cout  << "Index: " << i << " of our topological sorted vector is:  " << CaptureMe.at(i).GetIndexID() << endl;
    }



/*

    for (int i = 0; i < OurGraphObject.SumValues.size(); i++)
    {
        cout  << "Sum values carries at " << i << " value " << OurGraphObject.SumValues.at(i) << endl;
    }

    cout << "Line break! Index positions come next" << endl;

    for (int i = 0; i < OurGraphObject.PositionsOfSumValues.size(); i++)
    {
        cout  << "Positions of sums carries at " << i << " value " << OurGraphObject.PositionsOfSumValues.at(i) << endl;
    }

*/


    return 0;
}

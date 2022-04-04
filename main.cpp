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
    //vector <Data> CaptureMe;
    //CaptureMe = OurGraphObject.TopologicalSort();

    //Close but no cigar
    OurGraphObject.GetMaxPath();

    cout << "There are " << OurGraphObject.SumValuesAKAFvalues.size() << " clients in this file" << endl;
    cout << endl;

    int MaxRevenue = 0;



    for (int i = 0; i < OurGraphObject.SourceVertexes.size(); i++)
    {
        if (OurGraphObject.SumValuesAKAFvalues.at(OurGraphObject.SourceVertexes.at(i).GetIndexID()) > MaxRevenue)
        {
            MaxRevenue = OurGraphObject.SumValuesAKAFvalues.at(OurGraphObject.SourceVertexes.at(i).GetIndexID());
        }
    }

    cout << "Optimal revenue earned is " << MaxRevenue << endl;

    cout << "Clients contributing to this optimal revenue: ";

    //Go to greatest source node, and follow the neighbors that gave it it's fvalue in PositionsOfSumValuesAKAFvalues to find the optimal path
    for (int i = 0; i < OurGraphObject.SourceVertexes.size(); i++)
    {
        if (OurGraphObject.SumValuesAKAFvalues.at(OurGraphObject.SourceVertexes.at(i).GetIndexID()) == MaxRevenue)
        {
            cout << OurGraphObject.PositionsOfSumValuesAKAFvalues.at(OurGraphObject.SourceVertexes.at(i).GetIndexID()) << endl;
        }
    }



    //CaptureMe = OurGraphObject.GetMaxPath();
    //cout << "The size of our topological sorted vector is: ";
    //cout << CaptureMe.size();
    //cout << endl;
/*
    cout << "There are " << CaptureMe.size() << " clients in this file" << endl;

    for (int i = 0; i < CaptureMe.size(); i++)
    {
        cout  << "Index: " << i << " of our topological sorted vector is:  " << CaptureMe.at(i).GetIndexID() << endl;
    }

*/

/*
    for (int i = 0; i < OurGraphObject.SumValuesAKAFvalues.size(); i++)
    {
        cout  << "Sum values carries at " << i << " value " << OurGraphObject.SumValuesAKAFvalues.at(i) << endl;
    }

    cout << "Line break! Index positions come next" << endl;

    for (int i = 0; i < OurGraphObject.PositionsOfSumValuesAKAFvalues.size(); i++)
    {
        cout  << "Positions of sums carries at " << i << " value " << OurGraphObject.PositionsOfSumValuesAKAFvalues.at(i) << endl;
    }


    cout << OurGraphObject.SourceVertexes.size() << " is the size of the source vector" << endl;

*/
    return 0;
}

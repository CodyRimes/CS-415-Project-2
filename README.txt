- Group Members For Project 2a: Cody Grimes and Alana Reyna
- Extra credit implemented: 
	- DAG is implemented in an adjacency list
	- Topological sort uses a queue-based decrease-by-one design method

Very close to finding the max path (implementation was a function called "GetMaxPath()" for the Graph class.
Close but no cigar. Public vectors called "SumValues" and "PositionOfSumValues" implemented inside the Graph class had trouble towards the very front of the vector
getting the right index position. 

Topological sort, making edge connections for the directed acyclic graph, parsing input, a print function for the graph all
work just fine. GetMaxPath() should also work if uncommented in main, however it doesn't functionally do what it's supposed
to all the way. 

Graph.hpp represents the DAG
Data.hpp represents the client and it's relative data
LinkedListNode.hpp represents the linked list a client would be pointing to in Data.hpp. A LinkedListNode refers back
to the index of it's respective client it represents. 

GraphNode.hpp is not used in the program and was a prototype in trying to implement the functionality that Data.hpp
and LinkedListNode.hpp give in one class. We had to break up the functionality into two different classes. 


We were not able to save console output to an output file. Sending screenshots instead. Did not include a screenshot of Data9.txt
as it was too large to screenshot.

Thank you for all of your help on this project!
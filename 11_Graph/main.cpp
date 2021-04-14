#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    Graph<int, 3> a;
    /* add [0*0] to end of the graph edges  
    for example:
    Node: 5
    Connection: 3:5 5:3 0*0
    */
    a.addNode();    
    a.addNode();
    a.addNode();

    int num1, num2;
    cout<< "input head of edge: ";
    cin>> num1;
    cout<< "input end of edge: ";
    cin>> num2;
    a.addEdge(num1, num2);
    a.removeNode(3);
    cout << "print for first time\n";
    a.print();
    auto x = a.search(12);
    if (x)
        a.removeNode(12);

    cout << "print for second time\n";
    a.print();
}

/*
Node: 5
Connection: 3:5 5:3 0*0
Node: 6
Connection: 6:5 5:3 6:6 0*0
Node: 12 
Connection: 12:3 6:12 12:12 0*0
input head of edge: 5
input end of edge: 6
print for first time
data: 5
Edge: 6 
data: 6
Edge: 5 6 12 
data: 12
Edge: 12 
print for second time
data: 5
Edge: 6 
data: 6
Edge: 5 6
*/
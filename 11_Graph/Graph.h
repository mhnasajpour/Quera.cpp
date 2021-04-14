#include "Node.h"
#include <iostream>
using namespace std;

template <class T, T newNode>
class Graph
{
private:
    Node<T> *graph;
    int numNodes;

public:
    Graph()
    {
        numNodes = 1;
        graph = new Node<T>;
        graph[0].setData(newNode);
    }

    ~Graph()
    {
        delete[] graph;
    }

    void addNode()
    {
        Node<T> *temp = new Node<T>[numNodes + 1];
        for (int i = 0; i < numNodes; i++)
            temp[i] = graph[i];

        delete[] graph;
        graph = temp;
        cout << "Node: ";
        cin >> graph[numNodes].getData();
        cout << "Connection: ";
        while (1)
        {
            T a, b;
            char c = '*';
            cin >> a >> c >> b;
            if (c == '*')
                break;

            if (a == graph[numNodes].getData())
            {
                for (int i = 0; i <= numNodes; i++)
                {
                    if (graph[i].getData() == b)
                    {
                        graph[numNodes].addData(graph[i]);
                        break;
                    }
                }
            }

            else
            {
                for (int i = 0; i < numNodes; i++)
                {
                    if (graph[i].getData() == a)
                    {
                        graph[i].addData(graph[numNodes]);
                        break;
                    }
                }
            }
        }
        numNodes++;
    };

    void removeNode(T a)
    {
        bool b = false;
        for (int i = 0; i < numNodes; i++)
            if (a == graph[i].data)
            {
                b = true;
                break;
            }

        if (!b)
            return;

        for (int i = 0; i < numNodes; i++)
            for (int j = 0; j < graph[i].getSize(); j++)
                if (graph[i].pointer[j].getData() == a)
                    graph[i].removeData(graph[i].pointer[j]);

        Node<T> *temp = new Node<T>[numNodes - 1];

        int j = 0;
        for (int i = 0; i < numNodes; i++)
        {
            if (a == graph[i].data)
                i++;

            temp[j] = graph[i];
            j++;
        }
        delete[] graph;
        graph = temp;
        numNodes--;
    }

    void removeNode(Node<T> *r)
    {
        removeNode(r->data);
    }

    void addEdge(T a, T b)
    {
        for (int i = 0; i < numNodes; i++)
            if (graph[i].getData() == a)
                for (int j = 0; j < numNodes; j++)
                    if (graph[j].getData() == b)
                    {
                        graph[i].addData(graph[j]);
                        break;
                    }
    }

    void removeEdge(T a, T b)
    {
        for (int i = 0; i < numNodes; i++)
            if (graph[i].getData() == a)
                for (int j = 0; j < numNodes; j++)
                    if (graph[j].getData() == b)
                    {
                        graph[i].removeData(graph[j]);
                        break;
                    }
    }

    Node<T> *search(T a)
    {
        for (int i = 0; i < numNodes; i++)
            if (graph[i].getData() == a)
                return &graph[i];

        return NULL;
    }

    void print()
    {
        for (int i = 0; i < numNodes; i++)
        {
            cout << "data: " << graph[i].getData() << "\nEdge: ";
            for (int j = 0; j < graph[i].sizePtr; j++)
                cout << graph[i].pointer[j].getData() << ' ';

            cout << endl;
        }
    }
};
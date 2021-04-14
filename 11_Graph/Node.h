template <class T>
class Node
{
private:
    T data;
    Node *pointer; // conect with which nodes
    int sizePtr;   // size of pointer

public:
    Node();
    Node(const Node &r);
    
    void setData(const T &_data);
    T &getData();
    int getSize();
    
    void removeData(Node<T> &_data); // of pointer
    void addData(Node<T> &_data); // of pointer

    template <class G, G newNode>
    friend class Graph;
};


template <class T>
Node<T>::Node()
{
    pointer = nullptr;
    sizePtr = 0;
}

template <class T>
Node<T>::Node(const Node &r)
{
    data = r.data;
    sizePtr = r.sizePtr;
    pointer = new Node[r.sizePtr];
    for (int i = 0; i < sizePtr; i++)
        pointer[i] = r.pointer[i];
}

template <class T>
void Node<T>::setData(const T &_data)
{
    data = _data;
}

template <class T>
T& Node<T>::getData()
{
    return data;
}

template <class T>
int Node<T>::getSize()
{
    return sizePtr;
}

template <class T>
void Node<T>::removeData(Node<T> &_data) // of pointer
{
    if (sizePtr == 0)
        return;
        
    Node *temp = new Node[sizePtr - 1];
    int j = 0;
    for (int i = 0; i < sizePtr; i++)
    {
        if (_data.data == pointer[i].data)
            i++;

        temp[j] = pointer[i];
        j++;
    }

    delete[] pointer;
    pointer = temp;
    sizePtr--;
}

template <class T>
void Node<T>::addData(Node<T> &_data) // of pointer
{
    Node *temp = new Node[sizePtr + 1];
    for (int i = 0; i < sizePtr; i++)
    {
        if (_data.data == pointer[i].data)
        {
            delete[] temp;
            return;
        }
        temp[i] = pointer[i];
    }

    temp[sizePtr] = _data;
    delete[] pointer;
    pointer = temp;
    sizePtr++;
}
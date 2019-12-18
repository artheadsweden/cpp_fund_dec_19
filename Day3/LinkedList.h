#pragma once
using namespace std;

/******************************************
 * Node Class
 * Represents a node in the list.
 * This class is templated so it can hold any type of data
 * A pointer, next, points to the next node in the lisr
 */
template <typename T>
class Node
{
public:
    // Default constructor for a node
    Node();
    // Constructor that takes data of type T as its argument
    Node(T data);
    // Node destructor. Use it to print that the node is deleted to verify that all nodes are removed
    ~Node();
    // Getter for data
    T getData();
    // Setter for data
    void setData(T data);
    // Getter for the next pointer
    Node<T>* getNext();
    // Setter for the next pointer
    void setNext(Node<T>* next);
private:
    // Data stored in the node is of type T
    T data;
    // Pointer to the next node in the list. If it is the last node it should point to null
    Node<T>* next;
};

template <typename T>
Node<T>::Node(): data(T()), next(nullptr){}

template <typename T>
Node<T>::Node(T data): data(data), next(nullptr){}

template <typename T>
Node<T>::~Node()
{
    cout << "Deleteing node with data " << data << endl;
}

template <typename T>
T Node<T>::getData()
{
    return data;
}

template <typename T>
void Node<T>::setData(T data)
{
    this->data = data;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
    this->next = next;
}

/******************************************
 * Linked list class.
 * Handles the list and manages insertions and deletes of nodes
 * It also has some utility member functions
 */

template <typename T>
class LinkedList
{
public:
    // Default constructor for a linked list. Creates an empty list
    LinkedList();
    // Copy constructor. Needs to copy all the nodes from another list
    LinkedList(const LinkedList<T>& other);
    // Move construcotr. Needs to take over ownership from the other list and make it an empty list
    LinkedList(LinkedList<T>&& other);
    // List destructor. Must make sure all nodes are deleted
    ~LinkedList();
    // List copy assignment operator. Must make sure to copy all nodes from the other list
    LinkedList<T>& operator = (const LinkedList<T>& other);
    // List move assignment operator. Needs to take over ownership from the other list and make it an empty list
    LinkedList<T>& operator = (LinkedList<T>&& other);
    // Subscript operator overload. Even though the nodes are not in continues memory we want to be able to index into it
    T operator [](int index);
    // Empties the list. Make sure all nodes are deleted
    void clear();
    // Insert a new node at the tail
    void insertTail(T data);
    // Insert a new ode at the head
    void insertHead(T data);
    // Removes the node at the tail and returns the data from that node
    T popTail();
    // Removes the node at the head and returns the data from that node
    T popHead();
    // Returns the data at the tail
    T peekTail();
    // Returns the data at the head
    T peekHead();
    // Prints all the nodes in the list
    void print();
    // Returns the list size (the number of nodes)
    int size();
    // Returns the node at a specific index
    Node<T>* getNode(int index);
private:
    // Utility member function that creates a copy of a list to this instance.
    // Used by the copy constructor and the copy assignment operator
    void copy(const LinkedList<T>& other);
    // Pointer to the first node in the list
    Node<T>* head;
    // Pinter to the last node in the list
    Node<T>* tail;
    // Counter that keeps track of the number of nodes currently in the list
    int _size;
};

template <typename T>
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr), _size(0){}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    copy(other);
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList&& other) : head(nullptr), tail(nullptr), _size(0)
{
    swap(head, other.head);
    swap(tail, other.tail);
    swap(_size, other._size);
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& other)
{
    if (head)
    {
        clear();
    }
    copy(other);
    return *this;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator =(LinkedList&& other)
{
    if (head)
    {
        clear();
    }
    swap(head, other.head);
    swap(tail, other.tail);
    swap(_size, other._size);
    return *this;
}

template <typename T>
T LinkedList<T>::operator [](int index)
{
    return getNode(index)->getData();
}

template <typename T>
void LinkedList<T>::clear()
{
    if (!head)
    {
        return;
    }
    tail = head;
    while (tail)
    {
        tail = head->getNext();
        delete head;
        head = tail;
    }
    _size = 0;
}

template <typename T>

void LinkedList<T>::insertTail(T data)
{
    if (!tail)
    {
        head = new Node<T>(data);
        tail = head;
    }
    else
    {
        tail->setNext(new Node<T>(data));
        tail = tail->getNext();
    }
    _size++;
}

template <typename T>
void LinkedList<T>::insertHead(T data)
{
    if (!head)
    {
        head = new Node<T>(data);
        tail = head;
    }
    else
    {
        Node<T>* tempPtr = new Node<T>(data);
        tempPtr->setNext(head);
        head = tempPtr;
    }
    _size++;
}

template <typename T>
T LinkedList<T>::popHead()
{
    if (!head)
    {
        return T();
    }
    T nodeData = head->getData();
    Node<T>* tempPtr = head->getNext();
    delete head;
    head = tempPtr;
    if (!head)
    {
        tail = nullptr;
    }
    _size--;
    return nodeData;
}

template <typename T>
T LinkedList<T>::popTail()
{
    if (!tail)
    {
        return T();
    }
    if (!head->getNext())
    {
        T nodeData = head->getData();
        delete head;
        head = nullptr;
        tail = nullptr;
        _size = 0;
        return nodeData;
    }
    Node<T>* tempPtr = head;
    while (tempPtr->getNext() != tail)
    {
        tempPtr = tempPtr->getNext();
    }
    T nodeData = tail->getData();
    delete tail;
    tail = tempPtr;
    tail->setNext(nullptr);
    _size--;
    return nodeData;
}

template <typename T>
T LinkedList<T>::peekHead()
{
    return head->getData();
}

template <typename T>
T LinkedList<T>::peekTail()
{
    return tail->getData();
}

template <typename T>
void LinkedList<T>::print()
{
    Node<T>* tempPtr = head;
    while (tempPtr)
    {
        cout << tempPtr->getData() << " ";
        if (tempPtr->getNext())
        {
            cout << "->";
        }
        else
        {
            cout << "-|";
        }
        tempPtr = tempPtr->getNext();
    }
    cout << endl;
}

template <typename T>
int LinkedList<T>::size()
{
    return _size;
}

template <typename T>
Node<T>* LinkedList<T>::getNode(int index)
{
    if (!head || index > _size - 1 || index < 0)
    {
        return nullptr;
    }
    int pos = 0;
    Node<T>* tempPtr = head;
    while (pos < index)
    {
        tempPtr = tempPtr->getNext();
        pos++;
    }
    return tempPtr;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList& other)
{
    if (!other.head)
    {
        head = nullptr;
        tail = nullptr;
        _size = 0;
        return;
    }
    Node<T>* tempPtr = other.head;
    while (tempPtr)
    {
        insertTail(tempPtr->getData());
        tempPtr = tempPtr->getNext();
    }
    _size = other._size;
}
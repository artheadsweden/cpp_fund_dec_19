#include <iostream>

using namespace std;

/******************************************
 * Node Class
 * Represents a node in the list.
 * This class is templated so it can hold any type of data
 * A pointer, next, points to the next node in the list
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
    Node<T> *getNext();
    // Setter for the next pointer
    void setNext(Node<T> *next);

private:
    // Data stored in the node is of type T
    T data;
    // Pointer to the next node in the list. If it is the last node it should point to null
    Node<T> *next;
};

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
    LinkedList(const LinkedList<T> &other);
    // Move construcotr. Needs to take over ownership from the other list and make it an empty list
    LinkedList(LinkedList<T> &&other);
    // List destructor. Must make sure all nodes are deleted
    ~LinkedList();
    // List copy assignment operator. Must make sure to copy all nodes from the other list
    LinkedList<T> &operator=(const LinkedList<T> &other);
    // List move assignment operator. Needs to take over ownership from the other list and make it an empty list
    LinkedList<T> &operator=(LinkedList<T> &&other);
    // Subscript operator overload. Even though the nodes are not in continues memory we want to be able to index into the list
    T operator[](int index);
    // Empties the list. Make sure all nodes are deleted
    void clear();
    // Insert a new node containing data at the tail
    void insertTail(T data);
    // Insert a new node containing data at the head
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
    Node<T> *getNode(int index);

private:
    // Utility member function that creates a copy of a list to this instance.
    // Used by the copy constructor and the copy assignment operator
    void copy(const LinkedList<T> &other);
    // Pointer to the first node in the list
    Node<T> *head;
    // Pointer to the last node in the list
    Node<T> *tail;
    // Counter that keeps track of the number of nodes currently in the list
    int _size;
};

int main()
{
    return 0;
}
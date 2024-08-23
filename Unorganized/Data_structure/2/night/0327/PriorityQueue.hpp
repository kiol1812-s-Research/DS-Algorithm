#include <iostream>
using namespace std;

template<class E, class C>
class Node{
private:
    C Priority;
    Node* next;
    E data;
};

template<class E, class C>
class PriorityQueue{
private:
    Node<E, C>* head;
public:
    bool Insert(E object);  // O(n), n=size() | sorted list <- insert sort ; O(1) | unsorted list
    bool removeMin();       // O(1) | sorted list ; O(n) | unsorted
    bool IsEmpty();         // O(1)
    int size();             // O(1)
    E min();                // O(1) | sorted list ; O(n) | unsorted <- use unsorted varse output were like selection sort
};



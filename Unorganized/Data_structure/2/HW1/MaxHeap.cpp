/* 2024/03/14 max heap
*/
#include <iostream>
using namespace std;

template <class T>
class MaxHeap{
private:
    T* heap;
    int heapSize;
    int capacity;
public:
    MaxHeap(int theCapacity=10);
    ~MaxHeap(){ delete[] heap; };
    void Push(const T& e);
    void Pop();
    T& Top() const;
    bool IsEmpty() const { return heapSize==0; }
    int Size() const { return heapSize; }
    void PrintHeap() const;
};
template <class T>
MaxHeap<T>::MaxHeap(int theCapacity){
    if(theCapacity<1) throw "Capacity must be >= 1";
    this->capacity = theCapacity;
    this->heapSize = 0;
    this->heap = new T[capacity+1];
}
template <class T>
void MaxHeap<T>::Push(const T& e){
    if(heapSize==capacity){
        T* tmp = new T[capacity*2+1];
        for(int i=1; i<heapSize+1; i++){
            tmp[i]=heap[i];
        }
        delete[] heap;
        heap = tmp;
        capacity*=2;
    }
    int currentNode = ++heapSize;
    while(currentNode>1&&heap[currentNode/2]<e){
        heap[currentNode] = heap[currentNode/2];
        currentNode /= 2;
    }
    heap[currentNode] = e;
}
template <class T>
void MaxHeap<T>::Pop(){
    if(IsEmpty()) throw "Heap is empty. Can't pop.";
    heap[1].~T(); // delete max elemeent
    T lastE = heap[heapSize--];
    int currentNode=1, child=2;
    while(child<=heapSize){
        if(child<heapSize&&heap[child]<heap[child+1]) child++;
        if(lastE>=heap[child]) break;
        heap[currentNode] = heap[child];
        currentNode = child;
        child*=2;
    }
    heap[currentNode] = lastE;
}
template <class T>
T& MaxHeap<T>::Top() const {
    if(IsEmpty()) throw "Heap is empty. No top element.";
    return heap[1];
}
template <class T>
void MaxHeap<T>::PrintHeap() const {
    for(int i=1; i<=heapSize; i++){
        cout<<" "+(i==1)<<heap[i];
    }
    cout<<"\n";
}

int main(){
    MaxHeap<int> heap(2);
    const int arr[7] = {20, 30, 20, 50, 70, 80, 100};
    for(int i=0; i<7; i++){
        heap.Push(arr[i]);
    }
    cout<<"\nPrintHeap():\n";
    heap.PrintHeap();
    cout<<"\nprint heap in order:\n";
    while(!heap.IsEmpty()){
        cout<<heap.Top()<<" ";
        heap.Pop();
    }
    return 0;
}
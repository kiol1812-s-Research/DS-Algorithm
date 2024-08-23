/* 1107 楊育哲 刻queue */
#include <iostream>
using namespace std;

template<class T>
class MyQueue{
private:
    T* myqueue;
    int front;
    int rear;
    int capacity;
public:
    MyQueue(int init=10);
    ~MyQueue(){ delete[] myqueue; };
    bool isEmpty() const;
    T& Front() const;
    void Push(const T& item);
    void Pop();
};

template<class T>
MyQueue<T>::MyQueue(int init):capacity(init){
    if(init<1) throw "error.";
    T* myqueue = new T[capacity];
    front = 0;
    rear  = 0;
}

template<class T>
inline bool MyQueue<T>::isEmpty() const{ return (front==rear); }

template<class T>
void MyQueue<T>::Push(const T& item){
    if((rear+1)%capacity==front){
        // changeSize1D();
        capacity*=2;
    }
    rear = (rear+1)%capacity;
    myqueue[rear] = item;
}

template<class T>
void MyQueue<T>::Pop(){//要再改
    if(isEmpty()) throw "error, queue is empty.";
    myqueue[front].~T();
}

template<class T>
T& MyQueue<T>::Front() const{
    if(isEmpty()) throw "error.";
    return myqueue[front+1];
}


int main(){//待查
    MyQueue<int> test(4);
    cout<<test.isEmpty()<<"\n";
    test.Push(1);
    // test.Push(2);
    cout<<test.Front()<<"\n";
    // test.Pop();
    // cout<<test.Front()<<"\n";
    return 0;
}
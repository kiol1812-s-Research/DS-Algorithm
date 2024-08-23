/* 1107 楊育哲 刻stack*/
#include <iostream>
using namespace std;

// template<class T>
// void changeSize1D(T* array, int original, int newSize){
//     T* temp = new T[newSize];
//     copy(array, array+original, newSize);//可能得手刻
//     delete[] array;
//     array = temp;
// }

template<class T>
class MyStack{
private:
    T* mystack;
    int top;
    int capacity;
public:
    MyStack(int init=10);
    ~MyStack(){ delete[] mystack; }
    bool isEmpty() const;
    T& Top() const;
    void Push(const T& item);
    void Pop();
};

template<class T>
MyStack<T>::MyStack(int init):capacity(init){
    if(init<1) throw "error.";
    mystack = new T[capacity];
    top = -1;
}

template<class T>
inline bool MyStack<T>::isEmpty() const { return (top==-1); }

template<class T>
void MyStack<T>::Push(const T& item){
    if(top==capacity-1){
        // changeSize1D(mystack, capacity, capacity*2);
        capacity*=2;
    }
    mystack[++top] = item;
}

template<class T>
T& MyStack<T>::Top() const {
    if(isEmpty()) throw "error, stack is empty.";
    return mystack[top];
}

template<class T>
void MyStack<T>::Pop(){
    if(isEmpty()) throw "error, stack is empty.";
    // auto item=mystack[top];
    mystack[top--].~T();// !
    // return item;
}

int main(){
    MyStack<int> test(2);
    cout<<test.isEmpty()<<"\n";
    test.Push(1);
    test.Push(2);
    // test.Push(3);
    cout<<test.isEmpty()<<"\n";
    cout<<test.Top()<<"\n";
    test.Pop();
    cout<<test.Top()<<"\n";
    test.Pop();
    cout<<test.Top()<<"\n"; // throw 怎麼顯示待查
    // test.Pop();
    // cout<<test.Top()<<"\n";
    return 0;
}
/* 1114 楊育哲 實作鏈結串列迭代 */
#include <iostream>
using namespace std;

template<class T>
class NodeChain{
friend void operator++();
friend void operator++(int);
friend void operator+=(int); // !
friend void operator--();
friend void operator--(int);
friend void operator-=(int); // !
// friend void operator==(T& A, T& B)const{ return (A==B); }
// friend void operator!=(T& A, T& B)const{ return (A!=B); }
private:
    T value;
    NodeChain<T> *next;
public:
    NodeChain():next(NULL){};
    NodeChain(const T& data):next(NULL){ this->value=data; };
    NodeChain(const T& data, const NodeChain<T>* link){ this->value=data;this->next=link; };
    // ~NodeChain();
};

template<class T>
class Chain{
private:
    NodeChain<T>* first;
public:
    Chain():first(0);
    ~Chain();
    void Insert(T newValue, int index);//繞過例外, 如index過大，加在最後一格
    void Delete(int index);//記得寫例外處理
    T Get(int index);//記得寫例外回傳
    bool IsEmpty()const{ return first==0; };
    int IndexOf(const T& item)const{};
};

int main(){
    return 0;
}

template<class T>
T Chain<T>::Get(int index){
    NodeChain<T>* desiredNode = first;
    while(desiredNode->next&&index){
        desiredNode = desiredNode->next;
        index--;
    }
    if(index) return NULL;//throw
    else rerturn desiredNode->value;
}

template<class T>
void Chain<T>::Insert(T newValue, int index){
    if(index){
        NodeChain<T>* beforeNode = first;
        while(beforeNode->next&&index>1){
            beforeNode = beforeNode->next;
            index--;
        }//執行完index>0, 表示到串列尾端了，當接在尾端處理, 就不throw error了
        NodeChain<T>* newNode = NodeChain(newValue, beforeNode->next);
        beforeNode->next = newNode;
    }else{
        NodeChain<T>* newNode = NodeChain(newValue, first);
        first = newNode;
    }
}

template<class T>
void Chain<T>::Delete(int index){
    NodeChain<T>* beforeNode = first;
    if(index){
        while(beforeNode->next&&index>1){
            beforeNode = beforeNode->next;
            index--;
        }
        if(index) throw "error, this index does exist.";
        else{
            NodeChain<T>* deleteNode = beforeNode->next;
            beforeNode->next = deleteNode->next;
            delete deleteNode;
        }
    }else{
        first = first->next;
        delete beforeNode;
    }
}

template<class T>
int Chain<T>::IndexOf(const T& item)const{
    NodeChain<T>* current = first;
    int index=0;
    while(current->value!=item&&current->next){
        current = current->next;
        index++;
    }
    if(current->next) returm index;
    else return -1;
}


template<class T>
Chain<T>::~Chain(){
    while(first!=NULL){
        NodeChain<T>* next = first->next;
        delete first;
        first = next;
    }
}
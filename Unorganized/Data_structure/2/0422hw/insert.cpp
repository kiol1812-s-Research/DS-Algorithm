#include <iostream>
using namespace std;

template<class T>
class List{
private:
    T* arr;
    int size;
public:
    List(int init, T* l):size(init){
        arr = new T[size];
        for(int i=0; i<init; i++){
            arr[i]=l[i];
        }
    }
    void InsertSort(){
        int i=1, j=0;
        while(i<size){
            j=i;
            while(j>0&&arr[j-1]>arr[j]){
                swap(arr[j], arr[j-1]);
                j--;
            }
            i++;
        }
    }
    void swap(T& a, T& b){
        T temp = a;
        a = b;
        b = temp;
    }
    void show(){
        for(int i=0; i<size; i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
};

int main(){
    int* listA=new int[8];
    int index=0;
    for(int i=8; i>0; i--) listA[index++]=i;
    List<int> ListA = List<int>(8, listA);
    ListA.show();
    ListA.InsertSort();
    ListA.show();
    return 0;
}
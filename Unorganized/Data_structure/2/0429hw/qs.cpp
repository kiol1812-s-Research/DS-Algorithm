#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

template<class T>
void swap(T* a, T* b){
    T tmp = *a;
    *a = *b;
    *b = tmp;
}
// template<class T>
// int countLessThen(T* a, int pivot, int l, int r){
//     int ans=0;
//     for(int i=l; i<r; i++) if(pivot>a[i])ans++;
//     return ans;
// }
// template<class T>
// T find_kth(T* a, int k, int l, int r){
//     T pivot = a[rand()%(r-l+1)+l];
//     int L=countLessThen(a, pivot, l, r);
//     if(L+1==k) return pivot;
//     else if(L>=k) return find_kth()
// }
template<class T>
void QuickSort(T* a, const int left, const int right){
    if(left<right){
        // int pivot=a[left+rand()%(right-left+1)];
        // int pivotIndex=left+rand()%(right-left+1);
        // find(guess) median, use median of medians algorithm
        // use find kth 
        //quick sort main code
        int i = left, j=right+1, pivot=a[left];
        do{
            do{
                i++;
            }while(a[i]<pivot);
            do{
                j--;
            }while(a[j]>pivot);
            if(i<j) swap(a[i], a[j]);
        }while(i<j);
        swap(a[left], a[j]);
        QuickSort(a, left, j-1);
        QuickSort(a, j+1, right);
    }
}

int main(){
    srand(time(NULL));
    int* a = new int[5];
    for(int i=0; i<5; i++) cin>>a[i];
    QuickSort(a, 0, 4);
    for(int i=0; i<5; i++) cout<<a[i]<<"\n";
    return 0;
}

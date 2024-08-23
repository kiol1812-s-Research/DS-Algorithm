/* binerySearch */

#include <iostream>
using namespace std;

int binerySearch(int *arr, int target, const int n){
    int c=n, f=0, min=0;
    while(c>f){
        min = (c+f)/2;
        if(arr[min]==target) return min;
        else if(arr[min]>target) c=min;
        else f=min;
    }
    return -1;
}

int main(){
    int S=0, L=0;
    while(cin>>S>>L){
        if(S==0&&L==0) break;
        int a[L]={0};
        for(int i=0; i<L; i++) cin>>a[i];
        cout<<binerySearch(a, S, L)<<"\n";
    }
    return 0;
}
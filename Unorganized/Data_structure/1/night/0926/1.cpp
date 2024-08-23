/* insert sort */

#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int n=0;
    while(cin>>n){
        if(n==0) break;
        int a[n]={0};
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++){
            int min=i;
            for(int j=i+1; j<n; j++){
                if(a[min]>a[j]) min = j;
            }
            swap(a[min], a[i]);
        }
        for(int i=0; i<n; i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
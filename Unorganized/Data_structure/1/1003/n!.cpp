/*
排列abcd...
*/


#include <iostream>
using namespace std;

void swap(char *a, char *b){
    char c = *a;
    *a = *b;
    *b = c;
}

void sort(char* str, int k, int m){//cb..在ca..前面，得改
    for(int i=k; i<m; i++){
        int index=i;
        for(int j=i+1; j<=m; j++) if(str[j]<str[index]) index=j;
        swap(str[index], str[i]);
    }
}

void res(char* list, int k, int m){
    // sort(list, k+1, m);
    if(k==m){
        for(int i=0; i<=m; i++) cout<<list[i];
        cout<<"\n";
    }else{
        for(int i=k; i<=m; i++){
            swap(list[i], list[k]);
            res(list, k+1, m);
            swap(list[i], list[k]);
        }
    }
}

int main(){
    int n=4;
    char list[n]={'a'};
    for(int i=1; i<n; i++) list[i] = list[i-1]+1;
    res(list, 0, n-1);
    return 0;
}
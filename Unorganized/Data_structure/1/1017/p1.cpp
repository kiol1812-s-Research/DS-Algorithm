/*  1017 hw1 資工二乙 41143264 楊育哲
    A(m, n) 遞迴 
*/
#include <iostream>
using namespace std;

int recA(int m, int n){//以if-else實作遞迴版本
    if(m==0) return n+1;
    else if(n==0) return recA(m-1, 1);
    else return recA(m-1, recA(m, n-1));
}

int nonrecA(int m, int n){//以stack實作蝶帶版本
    int stackOfM[100]={0}, current=0;
    stackOfM[0] = m;
    while(current>=0){
        m = stackOfM[current--];
        if(m==0) n++;
        else if(n==0){
            n=1;
            stackOfM[++current]=m-1;
        }else{
            stackOfM[++current]=m-1;
            stackOfM[++current]=m;
            n--;
        }
    }
    return n;
}

int main(){
    cout<<recA(1, 1)<<" "<<nonrecA(1, 1);
    return 0;
}
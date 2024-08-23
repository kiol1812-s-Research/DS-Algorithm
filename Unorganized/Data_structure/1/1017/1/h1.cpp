/*  1017 hw1 資工二乙 41143264 楊育哲
    A(m, n) 遞迴 
*/
#include <iostream>
using namespace std;

int A(int m, int n){//依題目敘述，以if-else實作
    if(m==0) return n+1;
    else if(n==0) return A(m-1, 1);
    else return A(m-1, A(m, n-1));
}

int main(){
    cout<<A(2, 3);
    return 0;
}
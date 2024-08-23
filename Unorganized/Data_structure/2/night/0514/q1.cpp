/* 2024/05/14 41143264 楊育哲 
 * CSES Building Roads 
 * reference: https://cses.fi/problemset/task/1666
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    int* set = new int[n];
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        // join(a-1, b-1);
        set[a-1]=b-1;
    }
    // for(int i=0; i<n;i++) cout<<set[i]<<" ";
    // vector<pair<int, int>> brige;
    return 0;
}
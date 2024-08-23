#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    vector<int> a(n);
    for(auto &v:a) cin>>v;
    
    for(auto &v:a) //auto &v=a[k], 參考 (語法糖?) (syntax suger)
    for(auto v:a) // auto v=a[k], 副本

    // for(auto &v:a) cout<<" "+(&v==&a[0])<<v; // 去除第一個空格
    // a b c d e\r\n
    return 0;
}
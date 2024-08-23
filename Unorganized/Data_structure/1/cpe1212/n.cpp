/* 12/12 楊育哲
    CPE1212 忘了第幾題，求f(n), f(n)=連加(p+q), lcm(p, q)=n 、 1<=p<=q<=n
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int p, int q){
    while(q>0){
        int tmp=p%q;
        p = q;
        q = tmp;
    }return p;
}
int LCM(int p, int q){return p*q/(gcd(p, q));}
int f(vector<int> a, int n){
    int ans=n*2; for(int i=0; i<a.size(); i++){for(int j=i+1; j<a.size(); j++) if(LCM(a[i], a[j])==n)ans+=a[i]+a[j];}
    return ans;
}
int main(){
    int T=0; cin>>T;
    for(int cases=1; cases<=T; cases++){
        int C=0; cin>>C; vector<int> a; a.push_back(1);
        for(int i=0; i<C; i++){
            int pi=0, ai=0; cin>>pi>>ai;
            while(ai--) a.push_back(pi);
        }const int size=a.size(); int n=1;
        for(int i=1; i<size; i++){
            n*=a[i];
            for(int j=i+1; j<size; j++) a.push_back(a[i]*a[j]);
        }a.push_back(n);
        auto p=unique(a.begin(), a.end()); a.resize(p-a.begin());
        // for(auto &v:a) cout<<" "+(&v==&a[0])<<v; cout<<"\n";
        cout<<"Case "<<cases<<": "<<f(a, n)<<"\n";
    }
    return 0;
}
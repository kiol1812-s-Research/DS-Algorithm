/* 1212 楊育哲
    實作uva10161
*/
#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int N=0; while(cin>>N, N){
        int floor=(int)sqrt(N); int ceil=(floor*floor==N)?floor:floor+1;
        int ceil_2=ceil*ceil, floor_2=floor*floor;
        if(ceil_2-N<=N-floor_2){
            if(ceil%2) cout<<1+ceil_2-N<<" "<<ceil<<"\n";
            else cout<<ceil<<" "<<1+ceil_2-N<<"\n";
        }else{
            if(ceil%2) cout<<ceil<<" "<<N-floor_2<<"\n";
            else cout<<N-floor_2<<" "<<ceil<<"\n";
        }
    }
    return 0;
}
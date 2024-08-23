/* 1212 楊育哲
    實作uva11576
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int T=0; cin>>T; while(T--){
        int r, c; cin>>r>>c;
        string s; cin>>s;
        vector<string> a(c-1); for(auto &v:a){ cin>>v;
            bool flag=true;
            for(int i=s.length()-r; i<s.length(); i++){ flag=true;
                for(int j=0; j<r&&i+j<s.length(); j++){if(v[j]!=s[i+j]){flag=false; break;}}
                if(flag){for(int j=s.length()-i; j<r; j++)s+=v[j]; break;}
            }if(!flag) s+=v;
        }
        cout<<s.length()<<"\n";
    }
    return 0;
}
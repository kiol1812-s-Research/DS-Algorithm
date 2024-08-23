/*  1212 楊育哲
    實作uva10093
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    map<char, int> mp;
    for(int i=0; i<10; i++) mp['0'+i]=i;
    for(int i=0; i<26; i++) mp['A'+i]=i+10;
    for(int i=0; i<26; i++) mp['a'+i]=i+36;
    mp['-'] = 0; //?
    string s; while(cin>>s){
        int n=s.length(), total=0, maxnum=1;
        for(int i=n-1; i>=0; i--){
            int tmp=mp[s[i]]; total+=tmp;
            maxnum=(maxnum>tmp)?maxnum:tmp;
        }string output="such number is impossible!";
        for(int i=maxnum+1; i<=62; i++){
            if(total%(i-1)==0){output=to_string(i); break;}
        }cout<<output<<"\n";
    }return 0;
}
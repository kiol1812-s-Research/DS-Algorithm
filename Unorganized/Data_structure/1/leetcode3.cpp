#include <iostream>
#include <string>
using namespace std;
int main(){
    string s="";
    int min=1;
    cin>>s;
    for(int i=0; i<s.length(); i++){
        string sub="";
        sub+=s[i];
        int subLength=0, j=i+1;
        bool flag=true;
        while(flag&&j<s.length()){
            subLength++;
            sub+=s[j];
            for(int k=0; k<subLength; k++)
                if(s[j]==sub[k]) flag=false;
            j++;
        }
        // cout<<sub<<"\n";
        if(min<subLength) min=subLength;
    }
    cout<<min;
    return 0;
}
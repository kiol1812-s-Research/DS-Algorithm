/* 11/21 楊育哲 實作uva11035, stack */
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string s;
    stack<string> myStack;
    int n=0;
    cin>>n;
    while(n--){
        cin>>s;
        if(s[0]=='T'&&s[1]=='e'&&s[2]=='s'&&s[3]=='t'){
            if(myStack.empty()) cout<<"Not in a dream\n";
            else cout<<myStack.top();
        }else if(s[0]=='K'&&s[1]=='i'&&s[2]=='c'&&s[3]=='k') if(!myStack.empty()) myStack.pop();
        else if(s[0]=='S'&&s[1]=='l'&&s[2]=='e'&&s[3]=='e'&&s[4]=='p'){
            cin>>s;
            myStack.push(s);
        }
    }
    return 0;
}
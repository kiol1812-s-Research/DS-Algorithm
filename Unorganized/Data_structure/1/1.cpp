/* 大數乘法 */
#include <iostream>
#include <string>
using namespace std;

string intToString(int int_){
    string str="";
    while(int_>0){
        str+=int_%10+'0';
        int_/=10;
    }
    return str;
}

string mul(string A, string B){
    string temp="", result="";
    int part[A.length()+B.length()+1]={0}, carry=0, index=0;
    for(int i=0; i<B.length(); i++){
        for(int j=0; j<A.length(); j++) part[i+j]+=(A[j]-'0')*(B[i]-'0');
    }
    for(int i=0; i<=A.length()+B.length(); i++){
        temp+=(part[i]+carry)%10+'0';
        carry=(part[i]+carry)/10;
    }
    for(int i=temp.length()-1; i>=0; i--){
        if(temp[i]=='0') temp[i]='\0';
        else break;
    }
    while(temp[index]!='\0') result+=temp[index++];
    return result;
}

int main(){
    // string powerN="1", factorialN="1";

    // cout<<"2^100:\n";
    // for(int k=0; k<100; k++) powerN=mul(powerN, "2");
    // for(int i=powerN.length()-1; i>=0; i--) cout<<powerN[i];
    // cout<<"\n";

    // cout<<"100!:\n";
    // for(int k=2; k<=100; k++) factorialN=mul(factorialN, intToString(k));
    // for(int i=factorialN.length()-1; i>=0; i--) cout<<factorialN[i];

    string s="1";
    for(int k=0; k<100; k++) s=mul(s, "2");
    for(int i=s.length()-1; i>=0; i--) cout<<s[i];

    return 0;
}
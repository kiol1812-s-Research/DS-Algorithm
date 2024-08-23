#include <iostream>
#include <string>
using namespace std;
int main(){
    string str; int r, s;
    cin>>r>>s;
    getline(cin, str); getline(cin, str);
    for(int i=r; i<=s; i++) cout<<str[i];
    return 0;
}
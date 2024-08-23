/* fi = fi-1 + fi-2 */
#include <iostream>
#include <string>
using namespace std;

string add(string A, string B){
    int value=0, carry=0;
    string C="";
    if(A.length()>B.length()) B+='0';
    for(int index=0; index<A.length(); index++){
        value = (A[index]-'0')+(B[index]-'0')+carry;
        if(value>9){
            value-=10;
            carry = 1;
        }else carry=0;
        C+=value+'0';
    }
    if(carry==1) C+='1';
    return C;
}

int main(){
    string S[100];
    S[1] = S[2] = "1";
    for(int i=3; i<100; i++){
        S[i] = add(S[i-1], S[i-2]);
    }
    int n=0;
    while(cin>>n){
        cout<<"ans of "<<n<<" is ";
        for(int i=S[n].length()-1; i>=0; i--) cout<<S[n][i];
        cout<<"\n";
    }
    return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

string add(string A, string B){
	string C="";
	int value=0, carry=0;
	if(A.length()>B.length()) B+='0';
	for(int index=0; index<A.length(); index++){
		value = A[index]-'0'+B[index]-'0'+carry;
		if(value>9){
			carry = 1;
			value-=10;
		}else carry=0;
		C+=value+'0';
	}
	if(carry==1) C+='1';
	return C;
}

int main(){
	string S[100];
	S[1] = s[2] = "1";
	for(int i=3; i<100; i++){
		S[i] = add(S[i-1], S[i-2]);
	}
	int n=0;
	while(cin>>n){
		cout<<"The Fibonacci number for "<<n<<" is ";
		for(int i=S[n].length()-1; i>=0; i--)cout<<S[n][i];
		cout<<"\n";
	}
	return 0;
}
*/
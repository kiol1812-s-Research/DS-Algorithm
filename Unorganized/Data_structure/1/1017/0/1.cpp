/*多項式表示 1013 楊育哲*/
#include <iostream>
using namespace std;

class fx{
private:
    int terms[10]={0};
public:
    void inputTerms(int n){
        for(int i=n; i>=0; i--) cin>>terms[i];
    }
    int F(int x){
        int ans=0, power=1;
        for(int i=0; i<10; i++){
            ans+=power*terms[i];
            power*=x;
        }
        return ans;
    }
};

class fx2{
private:
    int terms[10][2]={0};
public:
    void inputTerms(int n){
        for(int i=n; i>=0; i--) cin>>terms[i][1]>>terms[i][0];
    }
    int power(int x, int n){
        int xn=1;
        for(int i=0; i<n; i++){
            xn*=x;
        }
        return xn;
    }
    int F(int x){
        int ans=0;
        for(int i=0; i<10; i++){
            ans+=terms[i][1]*power(x, i);
        }
        return ans;
    }
};

int main(){
    fx f1;
    f1.inputTerms(2); //x^2+x+1
    cout<<f1.F(1);
    return 0;
}
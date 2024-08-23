/* 1212 楊育哲
    實作uva442
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
struct Matrix{
    string name;
    int first;
    int second;
};
class MatrixStack{ public:
    vector<Matrix> stack;
    int pairCheck;
    MatrixStack(){pairCheck=0;}
    bool operator()(){
        if(pairCheck<=0||stack.size()<2) return false;
        if(stack[stack.size()-1].first!=stack[stack.size()-2].second) return false;
        return true;
    }
    int multis(){
        int value=stack[stack.size()-1].first*stack[stack.size()-1].second*stack[stack.size()-2].first;
        stack.pop_back(); stack.pop_back(); pairCheck--;
        return value;
    }
};
int main(){
    int n=0; cin>>n; vector<Matrix> a(n);
    for(auto &v:a) cin>>v.name>>v.first>>v.second;
    string s; while(getline(cin, s)){
        if(s.length()==1){cout<<0<<"\n"; continue;}
        istringstream sin(s); MatrixStack matrixStack;
        char c; int ans=0; while(sin>>c){
            if(c==')'){
                if(matrixStack()){cout<<"error\n";continue;}
                ans+=matrixStack.multis();
                continue;
            }else if(c=='('){matrixStack.pairCheck++;continue;}
            for(int i=0; i<a.size(); i++){if(a[i].name[0]==c)matrixStack.stack.push_back(a[i]);}
        }
        if(matrixStack.pairCheck<=0) cout<<ans<<"\n";
        else cout<<"error\n";
    }return 0;
}
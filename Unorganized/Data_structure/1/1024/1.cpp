/* 多像式表示 1024 */
#include <iostream>
using namespace std;

class Term{
friend 
private:
    int coef;
    int exp;
};
class Poly{
private:
    int capacity;
    int terms;
public:
    void polyAdd(){}
    //newTerms <- O(log2(k)), capcaity<=2^k
    //copy <- 次數<=2*非零項*2, 因為2^0+2^1+...+2^n=2^(n+1)-1
    //動態配置的時間複雜度跟空間複雜度都較小
    void newTerms(){}
}

int main(){
    return 0;
}
#include<bits/stdc++.h>
using namespace std; 

class Polynomial;
class Term{
    friend Polynomial;
    friend ostream& operator<<(ostream& os, const Polynomial& p);
    private:
        float coef;//係數
        int term;//次方項
};

class Polynomial{
    friend ostream& operator<<(ostream& os, const Polynomial& p);
    private:
        Term *termArray;
        int capacity;//空間大小  
        int terms;//非零項數量 
    public:
        Polynomial();//建構子  
        float Eval(float f);//求值  
        void NewTerm(const float newCoef,const int newExp);//新增非零項   
        Polynomial Mult(Polynomial poly);//多項式乘法  
};

Polynomial::Polynomial():capacity(2),terms(0){
    termArray = new Term[capacity];
}

void Polynomial::NewTerm(const float newCoef,const int newExp){
	//空間不足時重新配置空間
    if(capacity==terms){
        capacity*=2;
        Term *temp = new Term[capacity];
        copy(termArray, termArray+terms, temp);
        delete[] termArray;
        termArray = temp;
    }
    termArray[terms].coef = newCoef;
    termArray[terms++].term = newExp;
}

float Polynomial::Eval(float f){
	//多項式求值
    float ans=0;
    for(int i=0; i<terms; i++){
        ans+=termArray[i].coef*pow(f, termArray[i].term);
    }
    return ans;
}

Polynomial Polynomial::Mult(Polynomial poly){
	//多項式乘法
    Polynomial c;
    for(int i=0; i<terms; i++){
        for(int j=0; j<poly.terms; j++){
            bool flag=true;
            int cpos=0, Exp=termArray[i].term+poly.termArray[j].term;
            while(flag&&cpos<c.terms){
                if(Exp==c.termArray[cpos].term){
                    flag=false;
                    c.termArray[cpos].coef+=termArray[i].coef*poly.termArray[j].coef;
                }
                cpos++;
            }
            if(flag) c.NewTerm(termArray[i].coef*poly.termArray[j].coef, Exp);
        }
    }
    return c;
}

ostream& operator<<(ostream& os, const Polynomial& p){
    for(int i = 0;i<p.terms;i++){
        if(p.termArray[i].term == 0){
            os<<p.termArray[i].coef;
            continue;
        }
        if(i == p.terms-1){
            os<<p.termArray[i].coef<<"X^"<<p.termArray[i].term;
        }
        else{
            os<<p.termArray[i].coef<<"X^"<<p.termArray[i].term<<"+";
        }
    }
    
    return os;
}

int main(){
    Polynomial poly1;
    Polynomial poly2;
  
    poly1.NewTerm(2,2);
	poly1.NewTerm(2,1);
	poly1.NewTerm(2,0);
	
	poly2.NewTerm(2,2);
	poly2.NewTerm(2,1);
	poly2.NewTerm(2,0);
    
    cout<<"("<<poly1<<") X ("<<poly2<<") = ";
    cout<<poly1.Mult(poly2)<<endl;
    return 0;
}
/*  10/31 楊育哲
    題目: 多項式加減乘除
*/
#include <iostream>
#include <math.h>
using namespace std;

class Polynomial;
class Term{
friend ostream& operator<<(ostream& os, const Polynomial& p);
friend istream& operator>>(istream& is, Polynomial &p);
friend Polynomial;
private:
    float coef;
    int exp;
};
class Polynomial{
friend ostream& operator<<(ostream& os, const Polynomial& p);
friend istream& operator>>(istream& is, Polynomial &p);
private:
    int capacity;
public:
    int terms;//運算要用到
    Term *termsArray;
    Polynomial();
    Polynomial Add(Polynomial b);
    Polynomial Mult(Polynomial b);
    float Eval(float f);
    void newTerm(float coef, int exp);
};

int main(){
    Polynomial A;
    Polynomial B;
    cin>>A>>B;
    // cout<<A.Mult(B)<<"\n";
    cout<<A.Add(B)<<"\n";
    return 0;
}
Polynomial::Polynomial():capacity(2),terms(0){
    termsArray = new Term[capacity];
}
void Polynomial::newTerm(float coef, int exp){
    if(capacity==terms){
        capacity*=2;
        Term *temp = new Term[capacity];
        copy(termsArray, termsArray+terms, temp);
        delete[] termsArray;
        termsArray = temp;
    }
    termsArray[terms].coef = coef;
    termsArray[terms++].exp = exp;
}
Polynomial Polynomial::Add(Polynomial b){
    int apos=0, bpos=0;
    Polynomial c;
    while(apos<terms&&bpos<b.terms){
        if(termsArray[apos].exp==b.termsArray[bpos].exp){
            float tmp=termsArray[apos++].coef+b.termsArray[bpos++].coef;
            if(tmp) c.newTerm(tmp, termsArray[apos-1].exp);
        }else if(termsArray[apos].exp>b.termsArray[bpos].exp){
            c.newTerm(termsArray[apos].coef, termsArray[apos].exp);
            apos++;
        }else{
            c.newTerm(b.termsArray[bpos].coef, b.termsArray[bpos].exp);
            bpos++;
        }
    }
    for(int i=apos; i<terms; i++) c.newTerm(termsArray[i].coef, termsArray[i].exp);
    for(int i=bpos; i<b.terms; i++) c.newTerm(b.termsArray[i].coef, b.termsArray[i].exp);
    return c;
}
Polynomial Polynomial::Mult(Polynomial b){
    Polynomial c;
    for(int apos=0; apos<terms; apos++){
        for(int bpos=0; bpos<b.terms; bpos++){
            int Exp=termsArray[apos].exp+b.termsArray[bpos].exp, cpos=0;
            bool flag=true;
            while(flag&&cpos<c.terms){
                if(c.termsArray[cpos].exp==Exp){
                    flag=false;
                    c.termsArray[cpos].coef+=termsArray[apos].coef*b.termsArray[bpos].coef;
                }
                cpos++;
            }
            if(flag) c.newTerm(termsArray[apos].coef*b.termsArray[bpos].coef, Exp);
        }
    }
    return c;
}
float Polynomial::Eval(float f){
    float ans;
    for(int i=0; i<terms; i++){
        ans+=termsArray[i].coef*pow(f, termsArray[i].exp);
    }
    return ans;
}
ostream& operator<<(ostream& os, const Polynomial& p){
    for(int i=0; i<p.terms; i++){
        if(p.termsArray[i].exp==0){
            os<<p.termsArray[i].coef;
        }else if(i==p.terms-1) os<<p.termsArray[i].coef<<"x^"<<p.termsArray[i].exp;
        else os<<p.termsArray[i].coef<<"x^"<<p.termsArray[i].exp<<"+";
    }
    return os;
}
istream& operator>>(istream& is, Polynomial &p){
    float newCoef;
    int newExp;
    cout<<"start input coef and exp to Polynomial\n";
    while(true){
        cout<<"input coef and exp([0, 0] to end): ";
        is>>newCoef>>newExp;
        if(newCoef==0&&newExp==0) break;
        p.newTerm(newCoef, newExp);
    }
    return is;
}

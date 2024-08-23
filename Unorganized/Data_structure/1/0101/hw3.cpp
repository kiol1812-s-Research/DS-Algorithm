#include <iostream>
#include <math.h>
using namespace std;

struct Term{
    float coef;
    int exp;
    struct Term* next;
};

class Available{
private:
    struct Term *av;
public:
    void getBack(Term* node);
    Term* get();
    Available(){av=NULL;}
};
Available* list = new Available();
void Available::getBack(Term* node){
    Term* p=node;
    while(p->next) p=p->next;
    p->next=av;
    av=node;
}
Term* Available::get(){
    if(av!=NULL){
        Term* ret=av;
        av=av->next;
        ret->next=NULL;
        return ret;
    }
    return (struct Term*)malloc(sizeof(struct Term));
}

class Polynomial{
friend ostream& operator<<(ostream& os, Polynomial& p);
friend istream& operator>>(istream& is, Polynomial& p);
private:
    struct Term *first;
public:
    void newTerm(float c, int e);
    Polynomial(){ first=NULL; }
    Polynomial(const Polynomial& B);
    ~Polynomial();
    Polynomial& operator=(const Polynomial& a);
    Polynomial operator+(const Polynomial& a);
    Polynomial operator-(const Polynomial& a);
    Polynomial operator*(const Polynomial& a);
    float Evaluate(const float x)const;
};
Polynomial::Polynomial(const Polynomial& B){
    first=NULL;
    Term* p=B.first;
    while(p!=NULL){
        this->newTerm(p->coef, p->exp);
        p=p->next;
    }
}
Polynomial::~Polynomial(){
    list->getBack(first);
}
void Polynomial::newTerm(float c, int e){
    if(first==NULL){
        first = list->get();
        first->coef=c;
        first->exp=e;
        first->next=NULL;
    }else{
        struct Term* p=first;
        while(p->next!=NULL) p=p->next;
        p->next = list->get();
        p=p->next;
        p->coef=c;
        p->exp=e;
        p->next=NULL;
    }
}
ostream& operator<<(ostream& os, Polynomial& p){
    Term* current=p.first; bool flag=true;
    while(current!=NULL){
        if(current->coef!=0){
            flag=false;
            if(current->coef>0) os<<"+";
            else os<<"-";
            os<<abs(current->coef)<<"X^"<<current->exp;
        }
        current = current->next;
    }
    if(flag) os<<0;
    return os;
}
istream& operator>>(istream& is, Polynomial& p){
    float c, e;
    while(is>>c>>e, c||e){
        p.newTerm(c, e);
    }
    return is;
}
Polynomial& Polynomial::operator=(const Polynomial& a){
    list->getBack(first);
    first=NULL;
    Term* current = a.first;
    while(current!=NULL){
        newTerm(current->coef, current->exp);
        current = current->next;
    }
    return *this;
}
Polynomial Polynomial::operator+(const Polynomial& a){
    Term *i=this->first, *j=a.first;
    Polynomial C;
    while(i!=NULL&&j!=NULL){
        if(i->exp==j->exp){
            C.newTerm(i->coef+j->coef, i->exp);
            i=i->next; j=j->next;
        }else if(i->exp>j->exp){
            C.newTerm(i->coef, i->exp);
            i = i->next;
        }else{
            C.newTerm(j->coef, j->exp);
            j = j->next;
        }
    }
    while(i!=NULL){ C.newTerm(i->coef, i->exp);i=i->next; }
    while(j!=NULL){ C.newTerm(j->coef, j->exp);j=j->next; }
    return C;
}
Polynomial Polynomial::operator-(const Polynomial& a){
    Term *i=this->first, *j=a.first;
    Polynomial C;
    while(i!=NULL&&j!=NULL){
        if(i->exp==j->exp){
            C.newTerm(i->coef-j->coef, i->exp);
            i=i->next; j=j->next;
        }else if(i->exp>j->exp){
            C.newTerm(i->coef, i->exp);
            i = i->next;
        }else{
            C.newTerm(-1*j->coef, j->exp);
            j = j->next;
        }
    }
    while(i!=NULL){ C.newTerm(i->coef, i->exp);i=i->next; }
    while(j!=NULL){ C.newTerm(-1*j->coef, j->exp);j=j->next; }
    return C;
}
Polynomial Polynomial::operator*(const Polynomial& a){
    Polynomial C;
    for(Term* i=this->first; i!=NULL; i=i->next){
        for(Term* j=a.first; j!=NULL; j=j->next){
            int e=i->exp+j->exp;bool flag=true;
            for(Term* k=C.first; k!=NULL; k=k->next){
                if(k->exp==e){
                    k->coef+=i->coef*j->coef;
                    flag=false;
                    break;
                }
            }
            if(flag) C.newTerm(i->coef*j->coef, e);
        }
    }
    return C;
}
float Polynomial::Evaluate(const float x)const{
    float ans=0; Term* current=first;
    while(current!=NULL){
        ans+=current->coef*pow(x, current->exp);
        current=current->next;
    }
    return ans;
}

int main(){
    Polynomial test;
    cin>>test;
    test.~Polynomial();
    Polynomial test2; cin>>test2;
    // cout<<test;
    // Polynomial* copyt = new Polynomial(test);
    // cout<<*copyt<<"\n";
    // Polynomial opt=test;
    // cout<<opt;
    Polynomial a; cin>>a;
    Polynomial b = test2+a;
    Polynomial b2 = test2-a;
    Polynomial b3 = test2*a;
    cout<<b<<"\n";
    cout<<b2<<"\n";
    cout<<b3<<"\n";
    cout<<b3.Evaluate(2);
    return 0;
}
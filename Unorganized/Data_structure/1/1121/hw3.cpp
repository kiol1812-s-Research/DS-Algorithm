/* 11/21 楊育哲 以linked list 實作polynomals */
#include<iostream>
using namespace std;
/* ------------------------------------------------------------------------------------------------ */
struct Term{
    float coef;
    int exp;
    Term set(float c, int e){coef=c;exp=e;return *this;}
};
/* ------------------------------------------------------------------------------------------------ */
// class Chain; class Available; class Polynomal; class Iterator;
template<class T>
class Chain<T>{
private:
    T term;
    Chain<T>* next;
public:
    Chain();
    Chain(const Term& t, const Chain<Term> link){this->term=t; this->next=link;}
    Chain(const float c, const int e, const Chain<Term> link){this->term.coef=c; this->term.exp=e; this->next=link;}
    ~Chain();   
};
/* ------------------------------------------------------------------------------------------------ */
template<class T>
class Available<T>{
private:
    Chain<Term>* av;
public:
    Available();
    ~Available();
    void getBack(Chain<Term>* node);
    Chain<Term>* getNode(int n);
};
/* Available linked list */
template<class T>
void Available<T>::getBack(Chain<Term>* node){
    Chain<Term>* current = node;
    while(current.next) current=current.next;
    current.next = av;
    av = node;
}
template<class T>
Chain<Term>* Available<T>::getNode(int n){
    Chain<Term>* current = av;
    Chain<Term>* returnNode = av;
    while(av&&n--) av=av.next;
    current.next = NULL;//截斷
    if(n&&!av){
        while(n--){
            current = current.next;
            current = new Chain<Term>();
        }
        av = NULL;
    }
    return returnNode;
}
/* ------------------------------------------------------------------------------------------------ */
class Polynomal{
    // friend Available;// ?
    friend Iterator;
    friend istream& operator>>(istream& is, Polynomal& p);
    friend ostream& operator<<(ostream& os, Polynomal& p);
    friend Polynomal& operator+(const Polynomal& B)const;
    friend Polynomal& operator-(const Polynomal& B)const;
    friend Polynomal& operator*(const Polynomal& B)const;
    friend bool operator==(const Polynomal& B)const;
    friend bool operator!=(const Polynomal& B)const;
    private:
        Chain<Term>* poly;
        Chain<Term>* last;
        int terms;
    public:
        Polynomal();
        ~Polynomal();
        void newTerm(float c, int e);
};
class Iterator{
    private:
        Chain<Term>* current;
    public:
        Iterator(Chain<Term>* startNode){ current=startNode; }
        ~Iterator();
        Chain<Term>& operator*()const{ return current->term; }
        Chain<Term>* operator->()const{ return &current->term; }
        Iterator& operator++()const{ current=current->next;return *this; };
        Iterator& operator++(int n)const{ Chain<Term> old=*this;current=current->next;return old; }
        Iterator& operator--()const;
        Iterator& operator--(int n)const;
        bool operator==(const Iterator B)const{ return current==B.current; }
        bool operator!=(const Iterator B)const{ return current!=B.current; }
        // Chain<Term> Begin()const;
        // Chain<Term> End()const;
        void _copy(Iterator start, Iterator end, Iterator to){ while(start!=end;){*to=*start;start++;to++;} }
        void _deleteAll(Iterator start, Iterator end){ while(start!=end){ Chain<Term>* getBackNode=start;Available::getBack(getBackNode);start++; } }
};
/*-----------------------------------------------------------------------------------*/
/* polynomal */
Polynomal::Polynomal(){
    terms=0;
    last = poly = null;
}
void Polynomal::newTerm(float c, int e){
    if(!poly){ last=poly=new Chain(c, e, null);return; }
    if(!last.next) last=last->next=Available::getNode(1);
    else last=last.next;
    last->term.coef = c;
    last->term.exp = e;
    terms++;
}
istream& operator>>(istream& is, Polynomal& p){
    float newCoef=0; int newExp=0;
    cout<<"start input coef and exp to Polynomial\ninput coef and exp([0, 0] to end): ";
    while(is>>newCoef>>newExp, newCoef&&newExp){
        p.newTerm(newCoef, newExp);
        cout<<"input coef and exp([0, 0] to end): ";
    }
    return is;
}
ostream& operator<<(ostream& os, Polynomal& p){
    Iterator it = Iterator(p);
    while(it!=null){
        if(it.term->coef){
            if(it.term->exp==0){ char c=(it.term->coef>0)?'+':'-';os<<c<<it.term->coef; }
            else if(it.term->coef>0)os<<"+"<<it.term->coef<<"x^"<<it.term->exp;
            else os<<"-"<<it.term->coef<<"x^"<<it.term->exp;
        }
        ++it;
    }
    return os;
}
Polynomal& operator+(const Polynomal& B)const{
    Polynomal C;
    // Iterator ai=new Iterator(this.poly); Iterator bi=new Iterator(B.poly);
    // while(ai&&bi){
    //     if(ai.current->term->exp==bi.current->term->exp){
    //         float tmp=ai.current->coef+bi.current->coef;
    //         if(tmp) C.newTerm(tmp, ai.current->exp);
    //         ++ai; ++bi;
    //     }else if(ai.current->exp>bi.current->exp){
    //         C.newTerm(ai.current->coef, ai.current->exp);
    //         ++ai;
    //     }else{
    //         C.newTerm(bi.current->coef, bi.current->exp);
    //         ++bi;
    //     }
    //     while(ai++) C.newTerm(ai.current->coef, ai.current->exp);
    //     while(bi++) C.newTerm(bi.current->coef, bi.current->exp);
    // }
    return C;
}

/*-----------------------------------------------------------------------------------*/
/* Iterator */
// Iterator& operator--()const{
//     Iterator it = new Iterator(Polynomal::poly);
//     while(it.current.next!=this) ++it;
//     current=it.current;
//     return *this;
// }
// Iterator& operator--(int n)const{
//     Iterator it = new Iterator(Polynomal::poly);
//     while(it.current.next!=this) ++it;
//     current=it.current; ++it;
//     return *it;
// }
/*------------------------------------------------------------------------------------*/

int main(){
    // Polynomal A = new Polynomal();
    // cin>>A; cout<<A;
    return 0;
}
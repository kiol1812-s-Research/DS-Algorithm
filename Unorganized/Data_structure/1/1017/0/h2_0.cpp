/* 1017 hw2 組合 */
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int setPriority(string str){//組合優先度
    int count=0;
    for(int h=0; h<str.length(); h++) count=count*10+str[h]-'a'+1; //+1 是為了區別 'a' 跟 ' '
    return count;
}

void setSort(string* s, int size){//依組合優先度排列
    for(int i=0; i<size-1; i++){
        int index=i;
        for(int j=i+1; j<size; j++){
            if(setPriority(s[index])>setPriority(s[j])) index=j;
        }
        string temp=s[index];
        s[index] = s[i];
        s[i] = temp;
    }
}

void S(int n){// ~2^(n-1)
    int len=pow(2, n-1), binList[n]={0}, index=0;
    string s[len*2];// 00 01 10 11 len=bin(11)->2==len , 組合數: 4==len*2
    for(int i=1; i<=len; i*=2) binList[index++]=i;
    for(int i=0; i<len*2; i++){
        for(int j=0; j<index; j++){
            if(i&binList[j]) s[i]+=j+'a';
        }
    }
    setSort(s, len*2);
    for(int i=0; i<len*2; i++) cout<<s[i]<<"\n";
}

int main(){
    S(4);
    return 0;
}
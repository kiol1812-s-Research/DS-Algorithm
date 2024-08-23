/*  10/17 hw2 power set 資工二乙 41143264 楊育哲
    S(a, b) => powerset(S)={' ', a, b, ab}
*/
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int setPriority(string str){//計算組合優先度，運用於排列時
    int count=0;//似26進位，將每組字串編上唯一的編號
    for(int h=0; h<str.length(); h++) count=count*26+str[h]-'a'+1; //+1 是為了區別 'a' 跟 ' '
    return count;
}
void setSort(string* power_set, int size){//依組合優先度排列
    for(int i=0; i<size-1; i++){
        int index=i;//選擇排序
        for(int j=i+1; j<size; j++){//找優先度最小的排到未排列的最前面
            if(setPriority(power_set[index])>setPriority(power_set[j])) index=j;
        }
        string temp=power_set[index];
        power_set[index] = power_set[i];
        power_set[i] = temp;
    }
}
void powerSet(char* S, int n, string* power_set){// ~2^(n-1)
    int len=pow(2, n-1), binList[n]={0}, index=0;
    power_set = new string[len*2];// 00 01 10 11 len=bin(11)->2==len , 組合數: 4==len*2
    for(int i=1; i<=len; i*=2) binList[index++]=i;
    for(int i=0; i<len*2; i++){//(ex:n=4)=>0b0000~0b1111，
        for(int j=0; j<index; j++){//與binList[0b0001, 0b0010, 0b0100, 0b1000, ...]做and運算
            if(i&binList[j]) power_set[i]+=S[j];//若&結果為1，就將集合S對應字元加進power_set
        }
    }
    setSort(power_set, len*2);//將power_set依字典順序排列
}
int main(){
    char S[4]={'a', 'c', 'f', 'z'};//初始設定集合S
    string* power_set;//用以讀取集合S的power set
    powerSet(S, 4, power_set);//丟入集合S, 集合長度n, 讀取用power set
    // for(int i=0; i<len*2; i++) cout<<power_set[i]<<"\n";//輸出顯示power set內容
    return 0;
}
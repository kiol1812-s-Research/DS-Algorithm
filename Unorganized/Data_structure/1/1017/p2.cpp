/*  1017 hw2 資工二乙 41143264 楊育哲
    遞迴產生排列 ex. S=[a, b] => powerset(S)={' ', a, b, ab}
*/
#include <iostream>
#include <string>
using namespace std;

class Powerset{
private:
    string power_set[100];//最多可能有2^26個組合, 此處預設測資組合數低於一百
    char S[26], comb[27];//26個字母+'\0'
    int top, end, Sindex;//top協助comb成為stack, end為資料集大小, Sindex協助power_set存資料
public:
    Powerset(char *s, int size){//初始化, s為資料集, size為資料集長度
        top = 0;
        Sindex = 0;
        end = size;
        copy(s, s+size, S);
    }
    void rec_PS(int start){//遞迴主程式, 運作方式與課本舉例之排列遞迴類似
        for(int i=0; i<start; i++) power_set[Sindex]+=comb[i];
        Sindex++;
        for(int i=start; i<end; i++){
            comb[top++] = S[i];
            rec_PS(i+1);
            comb[--top]='\0';
        }
    }
    int strPriority(string str){//計算字串依字典的優先度, 協助排列函式運作
        int count=0;
        for(int h=0; h<str.length(); h++){
            if(str[h]!='\0') count=count*26+str[h]-'a'+1;
        }
        return count;
    }
    void setSort(){//依字典順序將power_set排列
        for(int i=0; i<Sindex-1; i++){
            int index=i;
            for(int j=i+1; j<Sindex; j++){
                if(strPriority(power_set[index])>strPriority(power_set[j])) index=j;
            }
            string tmp=power_set[index];
            power_set[index] = power_set[i];
            power_set[i] = tmp;
        }
    }
    void outputSet(){//輸出，輸出前先作排列
        // setSort();
        for(int i=0; i<Sindex; i++) cout<<power_set[i]<<"\n";
    }
};

int main(){
    char A[3]={'a', 'b', 'c'};
    Powerset test(A, 3);
    test.rec_PS(0);
    test.outputSet();
    return 0;
}
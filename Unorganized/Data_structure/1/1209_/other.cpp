//data coding

// cs.find(c) 取index

//decode
// string cs="123456789abcdefghi";
// string ds="123456789123456789";
// while(cin>>c) cout<<ds[cs.find(c)];

//            abcdefg
// string _1="0110000";

// #include <iostream>
// using namespace std;
// void dispay(int n){
//     string cs = "11111100110000110110111110010110111011011101111111100011111111111011";
//     for(int i=n*7; i<n*7+7; i++) cout<<cs[i];
// }
// int main(){
//     dispay(0);
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main(){
//     string cs="", ds=""; char c;
//     for(int i=(int)'A'; i<=(int)'Z'; i++)cs+=(char)i; cs+='A';
//     for(int i=(int)'a'; i<=(int)'z'; i++)ds+=(char)i; ds+='a';
//     while(cin.get(c)){
//         if(islower(c)) cout<<ds[ds.find(c)+1]<<"\n";
//         else cout<<cs[cs.find(c)+1]<<"\n";
//     }
//     return 0;
// }


// int main(){
//     string R="neswn", L=nwsen;
//     int x=0, y=0;char d, string s;
//     while(cin>>x>>y>>d>>s>>s){
//         for(auto &c:s){
//             if(c=='R'){d=R[R.find(d)+1];continue;}
//             if(c=='L'){d=L[L.find(d)+1];continue;}
//             if(c=='m'){//move}
//         }
//     }
//     return 0;
// }

//---------------------------
// while(cin>>_){}
// while(1){
//     input check ouput
// }
// while(1){
//     cin>>_;
//     if(!cin) break;
// }

//-------------------
// vector<int> a, b;
// a: 5 5 4 3 2
// b: 5 4 4 2 1
// (a>b) <- return true, 有內建多載運算子
// sort(a.begin(), a.end(), [](int b, int c){return c>b});//倒轉排列



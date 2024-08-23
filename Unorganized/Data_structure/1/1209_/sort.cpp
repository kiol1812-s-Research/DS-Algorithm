//"ABC" -> 41 42 43 00
// " " -> 20
// " "+1 -> ""
// for(auto &v:a){
//     cout<<" "+(&v==&a[0])<<v; //去開頭空白
// }


//---------------------
// #include <set>
// multiset<int> a;
// a.Insert(v);//加入直接排序


//-------------------
// vector<int> a;
// unique(a.begin(), a.end()); //去重複項 to set, 但重複項會待在後面
//解法 : auto q = unique(..);a.resize(q-a.begin()); //因為會回傳到重覆向為止的位址、並複寫不重複的在原vector

//-------------------
// sort(a.begin(), a.end(), flag); // 以flag[truefalse]排a、b位置  
//注意-3%2 = -1 != 3%2 = 1

//+lambda
// sort(a.begin(), a.end(), [](int a, int b){ // (const int &a, const int &b)->傳參考，較快(尤其參數是string之類的時候)
//     if(a%2!=b%2) return a%2>b%2;
//     if(a%2) return a<b;
//     else return a>b;
// });

//using class
// class Less{
//     public:
//         bool operator()(int a, int b){
//             if(a%2!=b%2) return a%2>b%2;
//             if(a%2) return a<b;
//             else return a>b;
//         }
// }
// Less cmp;
// sort(a.begin(), a.end(), cmp);


//-------------
// sort(a.begin(), a.end(), [](const string &a, const string &b){
//     if(a.size()!=b.size()) return a.size()>b.size();
//     return a<b;
// });







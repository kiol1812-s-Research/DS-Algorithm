// vector<int> a;
//  1 2 2 3 3 3 
//  b           e
//    L   U
// [b, e), 含前不含後(b=a.begin(), e=a.end())
// L = lower_bound(a.begin(), a.end(), 2);
// U = upper_bound(a.begin(), a.end(), 2);
//  1 3 4 5 5
//    L
//    U      <- 沒找到2的話

// lower_bound(a.begin(), a.end(), s, Less); //多載

// 1A 2C 1B 3A , 兩權重排序，但字母不排，直接插在片段前面
// auto p=lower_bound(a.begin(), a.end(), s, [](const string &a, const string &b){
//     int ia;istringstream(a)>>ia;
//     int ib;istringstream(b)>>ib;
//     return ia<ib;
// });
// a.insert(p, s);
// using upper_bound , 可以保住原本順序, lower_bound則片段倒序

//------------------

// template<class IT>
// void SORT(IT as, IT ae){ // void SORT(vector<int>::iterator a, vector<int>::iterator a);
//     if(ae-as==0) return;
//     swap(*min_element, *as);
//     SORT(as+1, ae);
// }
// SORT(a.begin(), a.end());


//------------------
//除秩排序 O(n^2)
// template<class IT>
// void SORT(IT as, IT ae){
//     for(IT p=as; p!=ae; p++){
//         for(IT q=as; q!=ae; q++) if(p<q&&*p>*q)swap(*p, *q);
//     }
// }
// SORT(a.begin(), a.end());

//--------------------
//遞迴插入
// template<class IT>
// void SORT(IT as, IT m, IT ae){//as~m已排序過
//     if(m==e) return;
//     auto p = upper_bound(as, m, *m);
//     auto tmp=*m;copy(p, m, p+1);*p=tmp;
//     SORT(as, m+1, ae);
// }
// SORT(a.begin(), a.end());

//20240429改善(遞迴插入)
// template<class IT>
// void SORT(IT as, IT m, IT ae){//as~m已排序過
//     if(m==ae) return;
//     auto p = upper_bound(as, m, *m);
//     auto tmp=*m;copy(p, m, p+1);*p=tmp;
//     SORT(as, m+1, ae);
// }





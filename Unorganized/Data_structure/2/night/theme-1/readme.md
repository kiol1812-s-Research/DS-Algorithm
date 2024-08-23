# 排序 + 雙指針 + 遞迴 + 其他補充

### 排序
```cpp
sort(arr, arr+size, less<typename>)    //遞減
sort(arr, arr+size, greater<typename>) //遞增
```

### 雙指針
```cpp
// 解區間和 ...
```
### 遞迴
- 拆分問題
```cpp
// 解區間和 - CSES# 1640
int sun(int l, int r){
    if(l==r) return arr[l];
    int mid = (l+r)/2;
    int L = sum(l, mid), R = sum(mid, r);
    return L+R;
}
```
```cpp
// 解合成函數 - AP325 P-1-1 合成函數(1)
int func(){
    String s;
    cin>>s;
    if(s=="f"){
        return 2*func()+1;
    }else if(s=="g"){
        int x=func(), y=func();
        return x+2*y-3;
    }
    return atoi(s.c_str());
}
```

### 其他補充:
1S : 10^7~8左右行指令
> #include<bits/stdc++.h> //萬用標頭黨









 
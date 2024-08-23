// while(cin>>a>>b)
        // ~~~~~~~~~~ ->上筆資料讀入成功傳true

// while(time--){}
// time 最後會=-1

// while(cin>>n,n) //輸入n且n不等於0
//while(cin>>str, str!='#') //先做前，再判斷(同上)

// ------------------------------------------------
// cin>>c; || cin>>s; //掠過空格
// cin.get(c)       getline(cin, s);//解法


// while(getline(cin, s)){
    // istringstream sin(s); //fin, include <sstream>
    //查一下sin fin sout fout
// }


//sin.peek() 回傳字串流下一字元，且字串流未更動


//----------------------
// cin>>Int;
// getline(cin, s);
// s -> "",  因為未換行

//解法 : cin.igone();(加在兩輸入之間) or getline(cin, buffer);<-用以換行

// 略過
// while(cin.get(c)){
//     if(c=='<'){flag=false;continue;}
//     if(c=='>'){flag=true;continue;}
//     if(flag) cout<<c;
// }



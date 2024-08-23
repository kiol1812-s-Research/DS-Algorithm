#include <iostream>
using namespace std;
int main(){
    int T, r, c; cin>>T;
    int[4][2] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while(T--){
        cin>>r>>c;
        char[][] m = new char[r][c];
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>m[i][j];
            }
        }
    }
    return 0;
}
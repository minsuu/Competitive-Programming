#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int R,C,b[22][22];
string S;
int f[4][2] = {0,1,0,-1,1,0,-1,0};
int rec(int x,int y,int s){
    if(!(0<=x && x<R && 0<=y && y<C)) return -INF;
    if(s & (1<<b[x][y])) return -INF;
    s |= (1<<b[x][y]);
    int r = 1;
    for(int i=0;i<4;i++){
        r = max(r, 1+rec(x+f[i][0],y+f[i][1],s)); 
    }
    return r;
}
int main(){
	cin>>R>>C;
    for(int i=0;i<R;i++){
        cin>>S;
        for(int j=0;j<C;j++)
            b[i][j]=S[j]-'A';
    }
    cout<<rec(0,0,0);
	return 0;
}

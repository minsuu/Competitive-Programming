#include <bits/stdc++.h>
using namespace std;
int N,M,r,bd[101][101];
int f[4][2]={0,1,0,-1,1,0,-1,0};
int rec(int x,int y){
    int s = 0;
    for(int i=0;i<4;i++){
        int nx = x+f[i][0];
        int ny = y+f[i][1];
        if(!(0<=nx && nx<N && 0<=ny && ny<M))
            continue;
        if(bd[nx][ny]==1){
            s++; bd[nx][ny]=r;
        }
        else if(bd[nx][ny]<r){
            bd[nx][ny] = r;
            s+=rec(nx,ny);
        }
    }
    return s;
}
int main(){
    cin>>N>>M;
    int s = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>bd[i][j];
            s+=bd[i][j];
        }
    }
    for(r=2;;r++){
        int c=rec(0,0);
        if(s==c) break;
        s-=c;
    }
    cout<<r-1<<"\n"<<s;
	return 0;
}

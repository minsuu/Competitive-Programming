#include <bits/stdc++.h>
using namespace std;
int N,b[101][101],v[101][101];
int f[4][2]={0,1,0,-1,1,0,-1,0};
void rec(int x,int y,int h){
    if(v[x][y]==h) return;
    if(b[x][y]<h) return;
    v[x][y]=h;
    for(int i=0;i<4;i++){
        int nx=x+f[i][0], ny=y+f[i][1];
        if(0<=nx && nx<N && 0<=ny && ny<N)
            rec(nx,ny,h);
    }
}
int main(){
	cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>b[i][j];
    int A=0;
    for(int h=1;h<=100;h++){
        int C=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++){
                if(b[i][j]>=h && v[i][j]!=h){
                    C++;
                    rec(i,j,h);
                }
            }
        A = max(A,C);
    }
    cout<<A;
	return 0;
}

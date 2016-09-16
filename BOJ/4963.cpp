#include <bits/stdc++.h>
using namespace std;
int N,M,m[55][55],vis[55][55];
int f[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
void rec(int i,int j){
    if(!(0<=i&&i<N&&0<=j&&j<M)) return;
    if(m[i][j]==0) return;
    if(vis[i][j]) return;
    
    vis[i][j]=1;
    for(int k=0;k<8;k++)
        rec(i+f[k][0],j+f[k][1]);
}

int main(){
    while(1){
        cin>>M>>N;
        if(N==0 && M==0) break;
        memset(vis,0,sizeof vis);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                cin>>m[i][j];
        }
        int ans = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(m[i][j] && !vis[i][j]){
                    ans++;
                    rec(i,j);
                }
            }
        }
        cout<<ans<<'\n';
    }
	return 0;
}

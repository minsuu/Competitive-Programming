#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int M,N,n,c,d[1010][1010];
int f[4][2]={0,1,0,-1,-1,0,1,0};
queue<ii> que;
int main(){
    cin>>N>>M;
    memset(d, -1, sizeof d);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>n;
            if(n==1){
                que.push(ii(i,j));
                d[i][j]=0;
            }else if(n==-1){
                d[i][j]=0;
            }else{
                c++;
            }
        }
    }
    if(c==0){
        cout<<0;
        return 0;
    }
    int ans = -1;
    while(!que.empty()){
        if(c==0) break;
        int i = que.front().first;
        int j = que.front().second;
        que.pop();
        for(int k=0;k<4;k++){
            int ni = i+f[k][0];
            int nj = j+f[k][1];
            if(!(0<=ni && ni<M && 0<=nj && nj<N)) continue;
            if(d[ni][nj]==-1){
                c--;
                d[ni][nj] = d[i][j]+1;
                que.push(ii(ni,nj));
                if(c==0) ans = d[ni][nj];
            }
        }
    }
    cout<<ans;
	return 0;
}

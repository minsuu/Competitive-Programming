#include <bits/stdc++.h>
using namespace std;
struct st{ int x,y; };
int L,W;
char bd[55][55];
int f[4][2]={0,1,0,-1,1,0,-1,0};
int bfs(int x,int y){
    int d[55][55];
    memset(d, -1, sizeof d);
    
    queue<st> q;
    q.push({x,y});
    d[x][y]=0;
    int ret = 0;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        ret = max(ret, d[x][y]);
        for(int i=0;i<4;i++){
            int nx=x+f[i][0], ny=y+f[i][1];
            if(0<=nx && nx<L && 0<=ny && ny<W && bd[nx][ny]=='L' && d[nx][ny]==-1){
                d[nx][ny] = d[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    return ret;
}
int main(){
	cin>>L>>W;
    for(int i=0;i<L;i++)
        cin>>bd[i];
    int ans =0;
    for(int i=0;i<L;i++) for(int j=0;j<W;j++)
        if(bd[i][j]=='L')
            ans = max(ans, bfs(i,j));
    cout<<ans;
	return 0;
}

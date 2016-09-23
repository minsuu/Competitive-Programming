#include <bits/stdc++.h>
using namespace std;
int d[303][303];
int T,N,A,B,C,D;
int f[8][2]={1,2,2,1,1,-2,2,-1,-1,2,-2,1,-1,-2,-2,-1};
struct st{int x,y;};
int main(){
	cin>>T;
    while(T--){
        cin>>N>>A>>B>>C>>D;
        memset(d,-1,sizeof d);
        queue<st> q;
        q.push({A,B});
        d[A][B]=0;
        while(!q.empty()){
            int x=q.front().x;
            int y=q.front().y;
            q.pop();
            for(int i=0;i<8;i++){
                int nx=x+f[i][0], ny=y+f[i][1];
                if(0<=nx && nx<N && 0<=ny && ny<N && d[nx][ny]==-1){
                    d[nx][ny] = d[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        cout<<d[C][D]<<"\n";
    }
	return 0;
}

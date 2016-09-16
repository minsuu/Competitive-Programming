#include <bits/stdc++.h>
using namespace std;
int mp[33][33], vis[33][33];
int f[4][2] = {0,-1,0,1,-1,0,1,0};
int rec(int x,int y){
    if(mp[x][y]==0) return 0;
    if(vis[x][y]) return 0;
    vis[x][y]=1;
    int r = 1;
    for(int i=0;i<4;i++)
        r += rec(x+f[i][0],y+f[i][1]);
    return r;
}
int N;
string S;
vector<int> ans;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>S;
        for(int j=0;j<N;j++){
            mp[i][j] = (S[j]=='1');
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int r = rec(i,j);
            if(r) ans.push_back(r);
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<'\n';
    for(int i : ans) cout<<i<<"\n";
	return 0;
}

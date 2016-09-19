#include <bits/stdc++.h>
using namespace std;
const int LIM = 987654321;
int n,m,a,b,c;
int adj[101][101];
int main(){
	cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j] = LIM;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c; a--;b--;
        adj[a][b] = min(adj[a][b], c);
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j || adj[i][j]==LIM){
                cout<<0<<" ";
                continue;
            }
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
	return 0;
}

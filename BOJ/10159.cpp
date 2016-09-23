#include <bits/stdc++.h>
using namespace std;
int N,M,a,b;
int adj[101][101];
int main(){
	cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>a>>b; a--;b--;
        adj[a][b] = 1;
    }
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                adj[i][j] |= adj[i][k]&adj[k][j];
    for(int i=0;i<N;i++){
        int c=0;
        for(int j=0;j<N;j++) if(i!=j)
            c+=!(adj[i][j] || adj[j][i]);
        cout<<c<<"\n";
    }
	return 0;
}

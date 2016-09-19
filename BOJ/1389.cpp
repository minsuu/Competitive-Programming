#include <bits/stdc++.h>
using namespace std;
int N,M,adj[101][101];
int main(){
	cin>>N>>M;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++)
        adj[i][j] = 987654321;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b; a--;b--;
        adj[a][b]=adj[b][a]=1;
    }
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                adj[i][j] = min(adj[i][j],
                    adj[i][k]+adj[k][j]);
    int min=987654321, mp=-1;
    for(int i=0;i<N;i++){
        int s=0;
        for(int j=0;j<N;j++){
            if(i!=j)
                s+=adj[i][j];
        }
        //cout<<s<<"\n";
        if(min>s){
            min=s; mp=i;
        }
    }
    cout<<mp+1;
	return 0;
}

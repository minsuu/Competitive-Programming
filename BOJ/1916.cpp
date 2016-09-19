#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int N,M;
lld adj[1010][1010];
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++)
        adj[i][j]=1987654321LL;
    for(int i=0;i<M;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c); a--;b--;
        adj[a][b]=min(adj[a][b],(lld)c);
    }
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(adj[i][j]>adj[i][k]+adj[k][j])
                    adj[i][j]=adj[i][k]+adj[k][j];
    int A,B; scanf("%d%d",&A,&B); A--;B--;
    cout<<adj[A][B];
	return 0;
}

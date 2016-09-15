#include <bits/stdc++.h>
using namespace std;
int N;
int adj[111][111];
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin>>adj[i][j];
    }
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                adj[i][j] |= adj[i][k] && adj[k][j];
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<adj[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}

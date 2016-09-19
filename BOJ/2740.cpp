#include <bits/stdc++.h>
using namespace std;
int N,M,K,a[101][101],b[101][101],c[101][101];
int main(){
	cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>a[i][j];
    cin>>M>>K;
    for(int i=0;i<M;i++)
        for(int j=0;j<K;j++)
            cin>>b[i][j];
    for(int i=0;i<N;i++)
        for(int j=0;j<K;j++)
            for(int k=0;k<M;k++)
                c[i][j]+=a[i][k] * b[k][j];

    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++)
            cout<<c[i][j]<<" ";
        cout<<"\n";
    }
	return 0;
}

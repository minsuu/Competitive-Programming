#include <bits/stdc++.h>
using namespace std;
int N,M,b[1010][1010],d[1010][1010];
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>b[i][j];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            d[i][j]=b[i][j];
            if(i)
                d[i][j]=max(d[i][j],d[i-1][j]+b[i][j]);
            if(j)
                d[i][j]=max(d[i][j],d[i][j-1]+b[i][j]);
        }
    }
    cout<<d[N-1][M-1];
	return 0;
}

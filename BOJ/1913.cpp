#include <bits/stdc++.h>
using namespace std;
int N,n,B[1010][1010];
int f[4][2]={-1,0,0,1,1,0,0,-1};
int main(){
    cin>>N>>n;
    int a=N/2,b=N/2,c=2,d=0,e=0;
    for(int i=1;i<=N*N;i++){
        B[a][b]=i;
        a+=f[e][0]; b+=f[e][1];
        d++;
        if(d==c/2){
            d=0; c++; e++; e%=4;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<B[i][j]<<' ';
        cout<<'\n';
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(B[i][j]==n)
                cout<<i+1<<' '<<j+1;
	return 0;
}

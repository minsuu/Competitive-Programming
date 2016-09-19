#include <bits/stdc++.h>
using namespace std;
int N,M,a[101][101];
int main(){
	cin>>N>>M;
    for(int k=0;k<2;k++){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int n; cin>>n;
            a[i][j]+=n;
        }
    }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
	return 0;
}

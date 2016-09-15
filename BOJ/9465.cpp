#include <bits/stdc++.h>
using namespace std;
int T,N,a[100100][2],d[100100][3];
int max(int a,int b,int c){
    return max(a,max(b,c));
}
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        for(int j=0;j<2;j++)
            for(int i=0;i<N;i++)
                cin>>a[i][j];

        d[0][0] = 0;
        d[0][1] = a[0][0];
        d[0][2] = a[0][1];
        for(int i=1;i<N;i++){
            d[i][0] = max(d[i-1][0], d[i-1][1], d[i-1][2]);
            d[i][1] = max(d[i-1][0], d[i-1][2]) + a[i][0];
            d[i][2] = max(d[i-1][0], d[i-1][1]) + a[i][1];
        }
        cout<<max(d[N-1][0],d[N-1][1],d[N-1][2])<<'\n';
    }
    return 0;
}

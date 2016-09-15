#include <bits/stdc++.h>
using namespace std;

int N,a[10100],d[10100][3];
int max(int a,int b,int c){
    return max(a,max(b,c));
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++) cin>>a[i];
    
    d[0][1] = a[0];
    for(int i=1; i<N; i++){
        d[i][0] = max( d[i-1][0], d[i-1][1], d[i-1][2] );
        d[i][1] = d[i-1][0] + a[i];
        d[i][2] = d[i-1][1] + a[i];
    }
    cout<<max(d[N-1][0],d[N-1][1],d[N-1][2]);
    return 0;
}

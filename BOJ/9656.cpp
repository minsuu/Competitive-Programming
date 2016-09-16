#include <bits/stdc++.h>
using namespace std;
int N,d[1010];
int main(){
    cin>>N;
    d[0]=1; d[1]=d[3]=0; d[2]=1;
    for(int i=4;i<=N;i++){
        d[i] = (!d[i-1]) | (!d[i-3]);
    }
    cout<<(d[N]? "SK" : "CY");
    return 0;
}

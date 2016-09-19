#include <bits/stdc++.h>
using namespace std;
const int MOD = 10007;
int N, d[1010][10];
int main(){
	cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<=9;j++){
            if(i==0){
                d[i][j]=1;
                continue;
            }
            for(int k=0;k<=j;k++){
                d[i][j] += d[i-1][k];
                d[i][j] %= MOD;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=9;i++){
        ans+=d[N-1][i];
        ans%=MOD;
    }
    cout<<ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int N,K,ans;
int main(){
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        if(N%i==0){
            K--;
            if(K==0){
                ans = i;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}

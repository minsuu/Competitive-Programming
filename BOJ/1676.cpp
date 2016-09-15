#include <bits/stdc++.h>
using namespace std;
int N,fiv;
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=i;j%5==0;j/=5)
            fiv++;
    }
    cout<<fiv;
    return 0;
}

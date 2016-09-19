#include <bits/stdc++.h>
using namespace std;
int N,d[100100];
int main(){
    cin>>N;
    for(int i=1;i<=N;i++) d[i] = 987654321;
    for(int i=0;i<N;i++){
        for(int j=1;i+j*j<=N;j++){
            d[i+j*j] = min(d[i+j*j], d[i]+1);
        }
    }
    cout<<d[N];
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int LIM=10100;
int M,N, siv[LIM];
int main(){
    siv[1]=1;
	for(int i=2;i*i<LIM;i++){
        if(siv[i]) continue;
        for(int j=i*2;j<LIM;j+=i)
            siv[j]=1;
    }
    cin>>M>>N;
    int s=0,m=987654321;
    for(int i=M;i<=N;i++){
        if(siv[i]) continue;
        s+=i; m=min(m,i);
    }
    if(s==0) cout<<-1;
    else cout<<s<<"\n"<<m;
	return 0;
}

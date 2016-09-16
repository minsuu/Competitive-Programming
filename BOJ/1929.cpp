#include <bits/stdc++.h>
using namespace std;
const int L = 1000100;
int siv[L],M,N;
int main(){
    siv[1]=1;
    for(int i=2;i*i<L;i++){
        if(siv[i]) continue;
        for(int j=i*2;j<L;j+=i)
            siv[j]=1;
    }
    cin>>M>>N;	
    for(int i=M;i<=N;i++)
        if(siv[i]==0)
            cout<<i<<"\n";
	return 0;
}

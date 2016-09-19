#include <bits/stdc++.h>
using namespace std;
int N,j,c[1010];
int main(){
	cin>>N;
    for(int i=0;i<N;i++){
        cout<<j+1<<" "; c[j]=1;
        if(i==N-1) break;
        while(c[j])j=(j+1)%N; j=(j+1)%N;
        while(c[j])j=(j+1)%N;
    }
	return 0;
}

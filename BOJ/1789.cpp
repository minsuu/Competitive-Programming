#include <bits/stdc++.h>
using namespace std;
long long N,n;
int main(){
    cin>>N;	
    for(n=1;n<=N;N-=n++);
    cout<<n-1;
	return 0;
}

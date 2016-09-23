#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    cin>>N;
    long long s=0;
    for(int i=0;i<N;i++)
        s+= i*1LL*N+i;
    cout<<s;
	return 0;
}

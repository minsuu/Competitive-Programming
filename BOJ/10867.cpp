#include <bits/stdc++.h>
using namespace std;
int N,a[100100];
int main(){
	cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    sort(a,a+N);
    N=unique(a,a+N)-a;
    for(int i=0;i<N;i++) cout<<a[i]<<" "; 
	return 0;
}

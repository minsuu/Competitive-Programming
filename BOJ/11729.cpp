#include <bits/stdc++.h>
using namespace std;
int N;
void rec(int n,int a,int b){
    if(n==0) return;
    int c = 6-a-b; 
    rec(n-1,a,c);
    cout<<a<<" "<<b<<"\n";
    rec(n-1,c,b);
}
int main(){
	cin>>N;
    cout<<((1<<N)-1)<<"\n";
    rec(N,1,3);
	return 0;
}

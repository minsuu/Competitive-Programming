#include <bits/stdc++.h>
using namespace std;
const int LIM = 1000;
bool chk(int n){
    if(n<100) return true;
    if(n==1000) return false;
    int c=n%10; n/=10;
    int b=n%10; n/=10;
    int a=n;
    return (b-a) == (c-b);
}
int N;
int main(){
    cin>>N;
    int s=0;
    for(int i=1;i<=N;i++)
        s+=chk(i);
    cout<<s;
	return 0;
}

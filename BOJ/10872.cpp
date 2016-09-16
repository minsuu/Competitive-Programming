
#include <bits/stdc++.h>
using namespace std;
int N;
long long a = 1;
int main(){
    cin>>N;	
    for(int i=1;i<=N;i++) a*=i;
    cout<<a;
	return 0;
}

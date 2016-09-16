
#include <bits/stdc++.h>
using namespace std;
int N,S,a[22],c;
int main(){
    cin>>N>>S;
    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=1;i<(1<<N);i++){
        int s = 0;
        for(int j=0;j<N;j++){
            if(i & (1<<j)) s += a[j];
        }
        if(S==s) c++;
    }
    cout<<c;
	return 0;
}

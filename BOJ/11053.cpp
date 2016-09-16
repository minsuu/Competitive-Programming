#include <bits/stdc++.h>
using namespace std;
int N,a[1010],d[1010],ans;
int main(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<N;i++){
        d[i]=1;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                d[i] = max(d[i], d[j]+1);
            }
        }
        ans = max(ans, d[i]);
    }
    cout<<ans; 
	return 0;
}

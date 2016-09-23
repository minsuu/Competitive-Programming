#include <bits/stdc++.h>
using namespace std;
int N,a[1010],b[1010],c[1010],d[1010];
int main(){
	cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i];
        c[i]=a[i];
    }
    reverse(c,c+N);

    for(int i=0;i<N;i++){
        b[i]=1; d[i]=1;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                b[i] = max(b[i], b[j]+1);
            }
            if(c[j]<c[i]){
                d[i] = max(d[i], d[j]+1);
            }
        }
    }
    int ans=0;
    for(int i=0;i<N;i++){
        ans = max(ans, b[i] + d[N-i-1]-1);
    }
    cout<<ans;
	return 0;
}

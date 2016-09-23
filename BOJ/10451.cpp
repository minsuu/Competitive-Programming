#include <bits/stdc++.h>
using namespace std;
int T,N,a[1010],b[1010];
void r(int n){
    if(b[n]) return;
    b[n] = 1;
    r(a[n]);
}
int main(){
	cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>a[i];
            a[i]--;
        }
        memset(b,0,sizeof b);
        int c=0;
        for(int i=0;i<N;i++){
            if(b[i]==0){
                c++;
                r(i);
            }
        }
        cout<<c<<"\n";
    }
	return 0;
}

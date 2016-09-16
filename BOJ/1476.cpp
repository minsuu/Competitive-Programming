#include <bits/stdc++.h>
using namespace std;

int E,S,M, e,s,m;
int main(){
    cin>>E>>S>>M;
    for(int ans=1;;ans++){
        e++; s++; m++;
        if(e>15) e=1;
        if(s>28) s=1;
        if(m>19) m=1;
        if(E==e && S==s && M==m){
            cout<<ans;
            break;
        }
    }
	return 0;
}

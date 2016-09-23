#include <bits/stdc++.h>
using namespace std;
int N,M,A,B,par[101];
vector<int> cd[101];
typedef pair<int,int> ii;

int ans=987654321;
ii rec(int i){
    ii r={-1,-1};
    if(i==A) r.first=0;
    if(i==B) r.second=0;
    for(auto j:cd[i]){
        ii l=rec(j);
        if(l.first!=-1) r.first=l.first+1;
        if(l.second!=-1) r.second=l.second+1;
    }
    if(r.first!=-1 && r.second!=-1)
        ans=min(ans,r.first+r.second);
    return r;
}

int main(){
	cin>>N>>A>>B>>M; A--;B--;
    for(int i=0;i<M;i++){
        int a,b; cin>>a>>b; a--;b--;
        par[b]=a; cd[a].push_back(b);
    }
    for(int i=0;i<N;i++) rec(i);
    if(ans==987654321) ans=-1;
    cout<<ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int N,M;
struct edg{
    int a,b,c;
    bool operator<(const edg& r) const{
        return c<r.c;
    }
};
int par[1010], ranks[1010];
int find(int x){
    return par[x]==x? x: (par[x]=find(par[x]));
}
void join(int x,int y){
    x=find(x); y=find(y);
    if(x==y) return;
    if(ranks[x]>ranks[y]) swap(x,y);
    par[x]=y;
    if(ranks[x]==ranks[y]) ranks[x]++;
}
bool same(int x,int y){
    return find(x)==find(y);
}

vector<edg> e;
int main(){
	cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e.push_back({a,b,c});
    }
    sort(e.begin(),e.end());
    for(int i=0;i<N;i++){
        par[i]=i; ranks[i]=0;
    }
    long long ans = 0;
    for(auto i : e){
        if(!same(i.a, i.b)){
            join(i.a, i.b);
            ans += i.c;
        }
    }
    cout<<ans;
	return 0;
}

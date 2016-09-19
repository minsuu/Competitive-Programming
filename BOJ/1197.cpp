#include <bits/stdc++.h>
using namespace std;
int par[10010], irank[10010];
int find(int x){
    return x==par[x]?x: par[x]=find(par[x]);
}
void join(int x,int y){
    x=find(x); y=find(y);
    if(x==y) return;
    if(irank[x]>irank[y]) swap(x,y);
    par[x] = y;
    if(irank[x]==irank[y]) irank[y]++;
}
bool same(int x,int y){
    return find(x) == find(y);
}

struct edg{
    int a,b,c;
    bool operator<(const edg& e) const{
        return c<e.c;
    }
} e[100100];
int V,E;
long long ans;
int main(){
	cin>>V>>E;
    for(int i=0;i<V;i++) par[i]=i;
    for(int i=0;i<E;i++){
        cin>>e[i].a>>e[i].b>>e[i].c;
        e[i].a--; e[i].b--;
    }
    sort(e, e+E);
    for(int i=0;i<E;i++){
        if(!same(e[i].a, e[i].b)){
            join(e[i].a, e[i].b);
            ans += e[i].c;
        }
    }
    cout<<ans;
	return 0;
}

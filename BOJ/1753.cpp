#include <bits/stdc++.h>
using namespace std;
const int LIM=987654321;
int V,E,K,a,b,c,d[20020];
vector<pair<int,int> > l[20020];
priority_queue<pair<int,int> > pq;

int main(){
	cin>>V>>E>>K; K--;
    for(int i=0;i<E;i++){
        cin>>a>>b>>c; a--;b--;
        l[a].push_back({b,c});
    }
    pq.push({0,K});
    for(int i=0;i<V;i++) d[i]=LIM;
    d[K]=0;
    while(!pq.empty()){
        int i=pq.top().second;
        int c=-pq.top().first;
        pq.pop();
        if(d[i]<c) continue;
        for(pair<int,int> j : l[i]){
            if(c+j.second < d[j.first]){
                d[j.first] = c+j.second;
                pq.push({-(c+j.second), j.first});
            }
        }
    }
    for(int i=0;i<V;i++){
        if(d[i]==LIM) cout<<"INF\n";
        else cout<<d[i]<<"\n";
    }
	return 0;
}

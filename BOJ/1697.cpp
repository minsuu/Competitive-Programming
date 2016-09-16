
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int LIM = 200200;
int N,K,t,d[LIM];
priority_queue<ii> pq;
int main(){
    for(int i=0;i<LIM;i++) d[i]=LIM;
    cin>>N>>K;
    pq.push(ii(0,N)); d[N]=0;
    while(!pq.empty()){
        int a = -pq.top().first;
        int b = pq.top().second; pq.pop();
        if(b==K){ cout<<a; break; } 
        if(a>d[b]) continue;
        if(a+1<d[b+1]){
            d[b+1] = a+1;
            pq.push(ii(-a-1,b+1));
        }
        if(a+1<d[b-1]){
            d[b-1] = a+1;
            pq.push(ii(-a-1,b-1));
        }
        if(b*2 < LIM && a+1<d[b*2]){
            d[b*2] = a+1;
            pq.push(ii(-a-1,b*2));
        }
    }
	return 0;
}

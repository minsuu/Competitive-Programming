#include <bits/stdc++.h>
using namespace std;
const int LIM=10010;
int T,A,B;
int siv[LIM],d[LIM];

int main(){
    for(int i=2;i*i<LIM;i++){
        if(siv[i]) continue;
        for(int j=i*2;j<LIM;j+=i){
            siv[j]=1;
        }
    }
	cin>>T;
    while(T--){
        cin>>A>>B;
        memset(d, -1, sizeof d);
        d[A] = 0;
        queue<int> q;
        q.push(A);
        while(!q.empty()){
            int x = q.front(); q.pop();
            if(x==B) break;
            for(int i=1;i<=1000;i*=10){
                int j=x/i%10, k=x-j*i;
                for(int l=0;l<=9;l++){
                    if(i==1000 && l==0) continue;
                    int m=k+l*i;
                    if(siv[m]==0 && d[m]==-1){
                        d[m]=d[x]+1;
                        q.push(m);
                    }
                }
            }
        }
        cout<<d[B]<<"\n";
    }
    
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int T,K;
bool a[1010],b[1010],c[1010];
vector<int> t;
int main(){
	cin>>T;
    int s=1;
    for(int i=1;s<1010;s+=++i){
        t.push_back(s);
        a[s]=1;
    }
    for(int i=0;i<1010;i++){
        if(!a[i]) continue;
        for(int j:t){
            if(i+j>=1010) break;
            b[i+j]=1;
        }
    }
    for(int i=0;i<1010;i++){
        if(!b[i]) continue;
        for(int j:t){
            if(i+j>=1010) break;
            c[i+j]=1;
        }
    }
    
    while(T--){
        cin>>K;
        cout<<c[K]<<"\n";
    }
	return 0;
}

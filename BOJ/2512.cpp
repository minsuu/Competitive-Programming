#include <bits/stdc++.h>
using namespace std;
int n,m;
map<int,int> e;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int j; cin>>j;
        e[j]++;
    }
    int s=0;
    for(auto it=e.rbegin();it!=e.rend();++it){
        it->second=(s+=it->second);
    }
    cin>>m;
    int ans = -1, cur = 0, last = 0;
    for(auto i : e){
        int lim = i.first;
        if((m-cur)/i.second<=lim-last){
            ans = last + (m-cur)/i.second;
            break;
        }
        cur += (lim-last)*i.second;
        last = lim;
    }
    if(ans==-1) ans=e.rbegin()->first;
    cout<<ans;
	return 0;
}

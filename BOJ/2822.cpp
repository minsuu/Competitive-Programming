#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[8];
vector<int> al;
int main(){
	for(int i=0;i<8;i++){
        cin>>a[i].first;
        a[i].second = i+1;
    }
    sort(a,a+8); reverse(a,a+8);
    int ans = 0;
    for(int i=0;i<5;i++){
        ans+=a[i].first;
        al.push_back(a[i].second);
    }
    sort(al.begin(),al.end());
    cout<<ans<<"\n";
    for(auto i : al) cout<<i<<"\n";
	return 0;
}

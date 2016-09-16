#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int L,C;
char c[26],v[256];
vector<string> vs;
int main(){
    v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = 1;
    cin>>L>>C;
    for(int i=0;i<C;i++){
        cin>>c[i];
    }
    sort(c,c+C);
    for(int i=(1<<C);i>=0;i--){
        int cc=0,V=0,NV=0;
        string s="";
        for(int j=0;j<C;j++)
            if(i&(1<<j)){
                cc++;
                s.push_back(c[j]);
                if(v[c[j]]) V++;
                else NV++;
            }
        if(cc!=L) continue;
        if(V>=1 && NV>=2){
            vs.push_back(s);
        }
    }
    sort(vs.begin(),vs.end());
    for(auto s : vs) cout<<s<<"\n";
	return 0;
}

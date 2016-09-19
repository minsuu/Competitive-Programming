
#include <bits/stdc++.h>
using namespace std;
struct CS{
    bool operator()(const string& a,const string& b) const{
        if(a.size()==b.size()){
            return a<b;
        }
        return a.size()<b.size();
    }
};

int N;
set<string,CS> vs;
int main(){
	cin>>N;
    while(N--){
        string a; cin>>a;
        vs.insert(a);
    }
    for(string a : vs) cout<<a<<"\n";
	return 0;
}

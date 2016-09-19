#include <bits/stdc++.h>
using namespace std;
int T,X;
int main(){
    cin>>T;
    while(T--){
        cin>>X;
        set<int> s;
        for(;X;X/=10) s.insert(X%10);
        cout<<s.size()<<"\n";
    }
	return 0;
}

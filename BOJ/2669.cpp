#include <bits/stdc++.h>
using namespace std;
int A,B,C,D;
set<pair<int,int> > s;
int main(){
    for(int k=0;k<4;k++){
        cin>>A>>B>>C>>D;
        for(int i=A;i<C;i++)
            for(int j=B;j<D;j++)
                s.insert({i,j});
    }
    cout<<s.size();
	return 0;
}

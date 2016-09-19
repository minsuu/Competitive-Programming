#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> J;
int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int& j : J) j=(j+M)%i;
        J.push_back((M-1)%i); 
    }
    cout<<"<";
    for(int i=(int)J.size()-1;i>=0;i--){
        if(i) cout<<J[i]+1<<", ";
        else cout<<J[i]+1<<">";
    }
	return 0;
}

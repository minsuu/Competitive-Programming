#include <bits/stdc++.h>
using namespace std;
int N,M;
string s[11];
int main(){
	cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>s[i];
        reverse(s[i].begin(), s[i].end());
    }
    for(int i=0;i<N;i++){
        cout<<s[i]<<"\n";
    }
	return 0;
}

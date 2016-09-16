#include <bits/stdc++.h>
using namespace std;
string S,A;
int main(){
    cin>>S;
    reverse(S.begin(),S.end());
    while(S.size()%3) S.push_back('0');
    for(int i=0;i<S.size();i+=3){
        int j=(S[i]-'0')+2*(S[i+1]-'0')+4*(S[i+2]-'0');
        A.push_back(j+'0');
    }
    reverse(A.begin(),A.end());
    cout<<A;
	return 0;
}

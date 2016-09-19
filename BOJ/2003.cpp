#include <bits/stdc++.h>
using namespace std;
int N,M,a[10100],c,sum;
map<int,int> s;
int main(){
    cin>>N>>M;
    s[0]=1;
    for(int i=0;i<N;i++){
        cin>>a[i];
        sum+=a[i]; s[sum]++;
        if(s.count(sum-M)){
            c+=s[sum-M];
        }
    }
    cout<<c;
	return 0;
}

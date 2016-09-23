#include <bits/stdc++.h>
using namespace std;
string a,b;
int d[1010][1010];
int n,m;
int main(){
	cin>>a>>b;
    n=a.size(), m=b.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i] == b[j]){
                d[i][j] = (i&&j? d[i-1][j-1]:0) + 1;
            }else{
                d[i][j] = max(i?d[i-1][j]:0, j?d[i][j-1]:0);
            }
        }
    }
    cout<<d[n-1][m-1];
	return 0;
}

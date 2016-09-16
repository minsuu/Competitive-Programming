#include <bits/stdc++.h>
using namespace std;
int N,a,b,B[110][110];
int main(){
    cin>>N;
    while(N--){
        cin>>a>>b;
        for(int i=a;i<a+10;i++){
            for(int j=b;j<b+10;j++){
                B[i][j] = 1;
            }
        }
    }
    int s = 0;
    for(int i=0;i<110;i++)
        for(int j=0;j<110;j++)
            s += B[i][j];
    cout<<s;
	return 0;
}

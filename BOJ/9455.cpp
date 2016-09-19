#include <bits/stdc++.h>
using namespace std;
int T,M,N,b[101][101];
int main(){
	cin>>T;
    while(T--){
        cin>>M>>N;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                cin>>b[i][j];
            }
        }
        int c=0;
        for(int j=0;j<N;j++){
            int s=M-1;
            for(int i=M-1;i>=0;i--){
                if(b[i][j]){
                    c+=(s-i);
                    s--;
                }
            }
        }
        cout<<c<<"\n";
    }
	return 0;
}

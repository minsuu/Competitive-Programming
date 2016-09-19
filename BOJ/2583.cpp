#include <bits/stdc++.h>
using namespace std;
int M,N,K, bd[101][101];
int rec(int x,int y){
    if(!(0<=x && x<N && 0<=y && y<M)) return 0;
    if(bd[x][y]) return 0;
    bd[x][y]=1;
    return 1 + rec(x+1,y) + rec(x,y+1) + rec(x-1,y) + rec(x,y-1);
}
int main(){
	cin>>M>>N>>K;
    for(int i=0;i<K;i++){
        int A,B,C,D;
        cin>>A>>B>>C>>D; 
        for(int j=A;j<C;j++)
            for(int k=B;k<D;k++)
                bd[j][k]=1;
    }
    vector<int> ans;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(bd[i][j]==0)
                ans.push_back(rec(i,j));
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(int i:ans)cout<<i<<" ";
	return 0;
}

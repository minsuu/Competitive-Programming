#include <bits/stdc++.h>
using namespace std;
int N,a[8];
int abs(int x){return x<0?-x:x;}
int main(){
	cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    sort(a,a+N);
    int ans=0;
    do{
        int s=0;
        for(int i=1;i<N;i++){
            s+=abs(a[i-1]-a[i]);
        }
        if(ans<s){
            ans=s;
            /*
            for(int i=0;i<N;i++)
                cout<<a[i]<<" ";
            cout<<"\n";
            */
        }
    }while(next_permutation(a,a+N));
    cout<<ans;
	return 0;
}

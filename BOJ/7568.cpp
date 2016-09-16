#include <bits/stdc++.h>
using namespace std;
int N;
int a[55],b[55];
int main(){
    cin>>N;	
    for(int i=0;i<N;i++) cin>>a[i]>>b[i];
    for(int i=0;i<N;i++){
        int c=1;
        for(int j=0;j<N;j++){
            if(a[i]<a[j] && b[i]<b[j])
                c++;
        }
        cout<<c<<" ";
    }
	return 0;
}

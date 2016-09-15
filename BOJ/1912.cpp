#include <bits/stdc++.h>
using namespace std;

int a[100100], b,c, ans=-987654321;
int N;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i];
        c+=a[i];
        ans=max(ans,c-b);
        b=min(b,c);
    }
    cout<<ans;
    return 0;
}

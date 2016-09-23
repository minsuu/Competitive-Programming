#include <bits/stdc++.h>
using namespace std;
int M,X,Y;
int a[4];
int main(){
    a[1]=1;
	cin>>M;
    while(M--){
        cin>>X>>Y;
        swap(a[X],a[Y]);
    }
    cout<<(a[1]?1:a[2]?2:a[3]?3:(-1));
	return 0;
}

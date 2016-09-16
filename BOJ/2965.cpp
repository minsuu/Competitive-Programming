#include <bits/stdc++.h>
using namespace std;
int A,B,C;
int main(){
    cin>>A>>B>>C;
    cout<<max(B-A-1,C-B-1);
	return 0;
}

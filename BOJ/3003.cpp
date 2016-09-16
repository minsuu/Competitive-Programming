#include <bits/stdc++.h>
using namespace std;
int P[6] = {1,1,2,2,2,8};
int p[6];
int main(){
    for(int i=0;i<6;i++){
        cin>>p[i];
        cout<<P[i] - p[i]<<' ';
    }
	return 0;
}

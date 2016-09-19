#include <bits/stdc++.h>
using namespace std;
int a[11],S;
int main(){
	for(int i=0;i<9;i++){
        cin>>a[i];
        S+=a[i];
    }
    bool f = false;
    for(int i=0;i<9 && !f;i++){
        for(int j=i+1;j<9 && !f;j++){
            if(S-a[i]-a[j] == 100){
                a[i] = -1;
                a[j] = -1;
                f = true;
            }
        }
    }
    for(int i=0;i<9;i++){
        if(a[i] != -1)
            cout<<a[i]<<"\n";
    }
	return 0;
}

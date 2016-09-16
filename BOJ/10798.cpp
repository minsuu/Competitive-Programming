#include <bits/stdc++.h>
using namespace std;
char b[5][16];
string ans;
int main(){
    for(int i=0;i<5;i++)
        scanf("%s",b[i]);
    for(int i=0;i<15;i++){
        for(int j=0;j<5;j++){
            if(b[j][i]) 
                ans.push_back(b[j][i]);
        }
    }
    cout<<ans;
	return 0;
}

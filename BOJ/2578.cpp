#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
map<int, ii> v;
int c[5][5];

int chk(){
    int r=0;
    for(int i=0;i<5;i++){
        bool a=true, b=true;
        for(int j=0;j<5;j++){
            a &= c[i][j];
            b &= c[j][i];
        }
        r+=a+b;
    }
    bool a=true, b=true;
    for(int i=0;i<5;i++){
        a &= c[i][i];
        b &= c[i][4-i];
    }
    return r+a+b;
}
int main(){
	for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int n;
            cin>>n;
            v[n] = {i,j};
        }
    }
    for(int i=0;i<5;i++) for(int j=0;j<5;j++){
        int n; cin>>n;
        c[v[n].first][v[n].second]=1;
        if(chk()>=3){
            cout<<i*5+j+1;
            return 0;
        }
    }
	return 0;
}

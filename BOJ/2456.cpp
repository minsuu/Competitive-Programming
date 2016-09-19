#include <bits/stdc++.h>
using namespace std;
int N;
struct st{
    int c[4],i;
    int s() const{ return 3*c[3]+2*c[2]+c[1]; }
    bool operator==(const st& r)const{
        return c[1]==r.c[1] && c[2] == r.c[2] && c[3] == r.c[3];
    }
    bool operator<(const st& r)const{
        return !(s()==r.s()?c[3]==r.c[3]?c[2]<r.c[2]:c[3]<r.c[3]:s()<r.s());
    }
}s[3];

int main(){
	cin>>N;
    for(int i=0;i<3;i++) s[i].i=i+1;
    for(int i=0;i<N;i++){
        int a,b,c;
        cin>>a>>b>>c;
        s[0].c[a]++;
        s[1].c[b]++;
        s[2].c[c]++;
    }
    sort(s,s+3);
    if(s[0]==s[1]) cout<<0<<" "<<s[0].s();
    else cout<<s[0].i<<" "<<s[0].s();
	return 0;
}

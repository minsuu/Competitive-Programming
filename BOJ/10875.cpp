#include <bits/stdc++.h>
using namespace std;
const int LIM = 987654321;
typedef long long lld;

struct Pts{
    int x,y;
    bool operator<(const Pts& rhs) const{
        return (x==rhs.x)? y<rhs.y : x<rhs.x;
    }
    bool operator==(const Pts& rhs) const{
        return (x==rhs.x && y==rhs.y);
    }
};
struct Seg{
    Pts a,b; // a-->b
    void flip(){
        swap(a.x, a.y);
        swap(b.x, b.y);
    }
};
bool ins(Pts a,Pts b,Pts p){
    if(b<a) swap(a,b);
    return (p==a) || (p==b) || (a<p && p<b);
}
bool ins(int a,int b,int p){
    if(b<a) swap(a,b);
    return (p==a) || (p==b) || (a<p && p<b);
}
int abs(int x){ return x<0?(-x):x;}

int inter(Seg u,Seg v){
    bool ud = u.a.y == u.b.y;
    bool vd = v.a.y == v.b.y;
    // 1-d case
    if( (ud && vd) || (!ud && !vd)){
        if(ud) {u.flip(); v.flip();}
        // asserted u:same-x, v:same-x;
        assert(u.a.x == u.b.x);
        assert(v.a.x == v.b.x);
        if(u.a.x != v.a.x) return LIM;
        if(ins(v.a, v.b, u.a)) return 0;
        int ad = abs(v.a.y-u.a.y);
        int bd = abs(v.b.y-u.a.y);
        Pts c = ad<bd? v.a : v.b;
        if(ins(u.a,u.b,c)) return min(ad,bd);
        return LIM;
    // 2-d case    
    }else{
        if(vd) {u.flip(); v.flip();}
        // aserted u:same-y, v:same-x;
        assert(u.a.y == u.b.y);
        assert(v.a.x == v.b.x);
        if(ins(u.a.x, u.b.x, v.a.x) &&
           ins(v.a.y, v.b.y, u.a.y)){
            return abs(u.a.x-v.a.x);
        }
        return LIM;
    }
}
vector<Seg> chk;
int L,N,t,ax,ay,af;
string dir;
const int f[4][2]={0,1,-1,0,0,-1,1,0};
bool fin;
void deb(Seg a){
    cout<<a.a.x<<","<<a.a.y<<" "<<a.b.x<<","<<a.b.y<<"\n";
}
/*
struct naive{
    int bd[3010][3010] = {0,};
    int ax=0,ay=0,af=0;
    lld ans=0;
    bool fin=false;
    void go(int t, string dir){
        if(fin) return;
        bd[ax+L][ay+L]=1;
        for(int i=1;i<=t;i++){
            ans++;
            int bx = ax + i*f[af][0];
            int by = ay + i*f[af][1];
            // cout<<bx<<","<<by<<"\n";
            if(!(-L<=bx && bx<=L && -L<=by && by<=L)
               || bd[bx+L][by+L]){
                fin = true; return;
            }
            bd[bx+L][by+L]=1;
        }
        ax+=t*f[af][0]; ay+=t*f[af][1];
        if(dir=="L") af=(af+3)%4;
        else af=(af+1)%4;
    }
};*/

int main(){
	cin>>L>>N;
    chk.push_back({{-L-1,-L-1},{-L-1,+L+1}});
    chk.push_back({{-L-1,-L-1},{+L+1,-L-1}});
    chk.push_back({{+L+1,+L+1},{-L-1,+L+1}});
    chk.push_back({{+L+1,+L+1},{+L+1,-L-1}});
    lld ans = 0;
    for(int i=0;i<=N;i++){
        //cout<<ans<<" "<<ns.ans<<"\n";
        cin>>t>>dir;
        if(i==N) t=LIM;
        //ns.go(t,dir);
        if(fin) continue;
        Seg step = {{ax,ay},{ax+t*f[af][0],ay+t*f[af][1]}};
        // deb(step);
        int mt = LIM;
        for(int k=0;k<(int)chk.size()-1;k++){
            auto& j = chk[k];
            mt = min(mt, inter(step,j));
            /*if(mt==0){
                deb(step); deb(j);
                cout<<"\n";
            }*/
        }
        if(mt!=LIM){
            //cout<<"*"<<mt<<"\n";
            ans += mt; fin=true; continue;
        }
        ans += t;
        ax += t*f[af][0]; ay += t*f[af][1];
        chk.push_back(step);
        if(dir=="L") af=(af+3)%4;
        else af=(af+1)%4;
    }
    cout<<ans; //<<"\n"<<ns.ans;
	return 0;
}

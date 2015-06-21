#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RREP(I, N) for (int I= (N)-1; I>=0; --I)
#define RREPP(I, A, B) for(int I = (B)-1; I>=A; --I)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
#define debug(A) REP(i, A.size()) cerr << A[i] << ' '; cerr << '\n'
using namespace std;
  
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
  
typedef long long lld;
typedef unsigned long long ulld;
typedef pair<lld, lld> plld;
typedef vector<lld> vlld;
typedef vector<vlld> vvlld;
  
typedef long double ld;
typedef vector<ld> vld;
typedef vector<vld> vvld;
 
const int MAXN=5e5+10;
const int MAXK=1e6+10;
const int INF=987654321;
struct Edge{ int to, co; };
typedef vector< vector<Edge> > vve;
vve linked; vi deleted;
int n, k, size[MAXN], par[MAXN], A[MAXK], AR[MAXK];
 
int solve(int root){
    struct Sres{ int now, nowk, len, iter, par; };
    int ret=INF;
    for(auto it : linked[root]){
        if( deleted[it.to] ) continue;
        vii paths; stack<Sres> st; st.push({it.to, it.co, 1, 0, root});
        while(!st.empty()){
            Sres& here=st.top();
            if(SZ(linked[here.now]) == here.iter) {
                paths.PB( {here.nowk, here.len} );
                st.pop(); continue;
            }
            Edge there=linked[here.now][here.iter]; here.iter++;
            if( there.to==here.par || deleted[there.to] ) { continue; }
            if( here.nowk + there.co <= k )
                st.push({there.to, here.nowk + there.co, here.len+1, 0, here.now});
        }
        for(auto it : paths)
            if(AR[k-it.F]==root && A[k-it.F]) ret=min(ret, A[k-it.F] + it.S);
        for(auto it : paths){
            A[it.F]=min( ( ( AR[it.F] != root || A[it.F]==0 ) ? INF : A[it.F] ), it.S);
            AR[it.F]=root;
        }
    } if(AR[k]==root && A[k]) ret=min(ret, A[k]);
    return ret;
}
int dnc(int root){
    struct Sres{ int now, iter; };
    vi vs; stack<Sres> st; st.push({root, 0}); par[root]=-1; size[root]=1;
    while(!st.empty()){
        Sres& here=st.top();
        if(SZ(linked[here.now])==here.iter){
            vs.PB(here.now);
            if(par[here.now]!=-1) size[par[here.now]]+=size[here.now];
            st.pop(); continue;
        }
        Edge there=linked[here.now][here.iter]; here.iter++;
        if(deleted[there.to] || there.to==par[here.now]) { continue; }
        par[there.to]=here.now; st.push({there.to, 0}); size[there.to]=1;
    }
    int sn=SZ(vs), nroot=-1;
    if(sn==1) return INF;
    for(auto it : vs){
        int maxi=0;
        for(auto there : linked[it]){
            if(deleted[there.to]) continue;
            if(par[it] == there.to) maxi=max(maxi, sn-size[it]);
            else maxi=max(maxi, size[there.to]);
        }
        if(maxi<=sn/2) { nroot=it; break; }
    } assert(nroot!=-1);
    int ret=solve(nroot); deleted[nroot]=1;
    for(auto it : linked[nroot]){
        if(deleted[it.to]) continue;
        ret=min(ret, dnc(it.to));
    }
    return ret;
}
int best_path(int N, int K, int H[][2], int L[]){
    vve(N).swap(linked); vi(N, 0).swap(deleted); MS0(A); MS0(AR);
    for(int i=0;i<N-1;i++){
        linked[H[i][0]].PB({H[i][1], L[i]});
        linked[H[i][1]].PB({H[i][0], L[i]});
    } n=N, k=K;
    int ret=dnc(0);
    return ( ret==INF )? -1 : ret;
}
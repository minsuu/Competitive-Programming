// Aug 25 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
struct EDGE{
    int to, co;
    bool operator<( const EDGE& rhs ) const {
        return co < rhs.co;
    }
};
typedef vector<EDGE> ve;
  
vector<ve> linkd; 
int T,N,M,a,b,c, lim,sel;
  
int dfs( int now, int par ){
    vector<int> cand;
    for( auto it : linkd[now] ){
        if( it.to == par ) continue;
        int nxt = it.to, cc = dfs(nxt, now) + it.co;
        if( cc <= lim ) cand.push_back( cc );
    }
    sort( cand.begin(), cand.end() );
  
    int lst = 0;
    for( auto it : cand ){
        assert( it >= 0 );
        if( lst + it > lim ) break;
        sel++; lst = it;
    }
    return lst;
}

bool decision( int l ){
    lim = l; sel = 0;
    dfs( 0, -1 );
    if( sel >= M ) return true;
    else return false;
}
  
int main(){
    scanf("%d",&T); 
    while(T--){
        scanf("%d%d",&N,&M);
        vector<ve>(N).swap( linkd );
          
        int lo = 0, hi = 0;
        for(int i=0; i<N-1; i++){
            scanf("%d%d%d",&a,&b,&c); a--;b--;
            linkd[a].push_back( {b, c} );
            linkd[b].push_back( {a, c} );
            hi += c;
        }
        assert( hi >= 0 );
  
        for(int i=0; i<N; i++)
            sort( linkd[i].begin(), linkd[i].end() );
  
        // lo : false, hi : true
        while( lo + 1 < hi ){
            int mid = ( lo + 0LL + hi ) / 2;
            if( decision(mid) )
                hi = mid;
            else
                lo = mid;
        }
        printf("%d\n",hi);
    }
    return 0;
}
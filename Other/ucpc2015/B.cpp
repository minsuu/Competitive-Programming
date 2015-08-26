// Aug 23 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld A,B;
const lld LIM = 1e18;
lld pre(lld X, lld k){
    if( X == 0 || k == 0 ) return 0LL;
  
    lld r = X/10, dig = 1LL, ret = 0LL;
    while( r ) r/=10, dig*=10;
    if( dig == LIM ){
    	lld ld = dig;
    	bool pl = true;
    	while( ld ){
    		if( ld == k ) pl = false;
    		ld/=10;
    	}
    	ret = pl; dig/=10;
    }

    r = k;
    while( r < dig ) r*=10;
    while( r/10 >= dig ) r/=10;
    while( dig ){
        lld l = min( X, r );
        if( l >= k && l == r ) l--;
        ret += max( 0LL, l - dig + 1 );
        dig /= 10; r /= 10;
    }
    return ret;
}

int T;
lld cal(lld k){
    lld ret = pre(B, k) - pre(A-1, k);
    assert( ret >= 0 );
    // if( ret < 0 ) { printf("%lld %lld %lld\n",k,pre(B,k),pre(A-1,k) ); T = 0; return 0; }
    //printf("calculated [%lld..%lld] pre %lld : %lld\n",A,B,k,ret);
    return min( ret+1, B-A+1 );
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&A,&B);
        lld ans = max( cal(A), cal(A-1) );
        ans = max( ans, cal(B) );
        ans = max( ans, cal(B+1) );
        printf("%lld\n",ans);
    }
    return 0;
}
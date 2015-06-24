#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld mpow(lld a, lld b, lld m){
    lld bb = 1LL, ret = 1LL;
    while( bb<=b ){
        if( b & bb ) ret = ret*a%m;
        a = a*a%m; bb<<=1;
    }
    return ret;
}
class ColorfulLineGraphs{
public:
    int countWays(long long N, long long K, int M){
        lld tmp = 1LL; K = K%M + M;
        for(int i=1; i<=M; i++)
            tmp = tmp * ( (K-1)*i + 1 ) % M;
        lld tmp2 = 1LL, r = N%M;
        for(int i=1; i<=r; i++)
            tmp2 = tmp2 * ( (K-1)*i + 1 ) % M;
        return mpow(tmp, N/M, M) * tmp2 % M;
    }
};
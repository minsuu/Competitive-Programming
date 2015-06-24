#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int MOD = 1e9+7;
const int MAXN = 1111111;
int dp[5555][2];
int inv[MAXN], fact[MAXN], ifact[MAXN];
int mcomb(int a, int b){
    return fact[a] * 1LL * ifact[b] % MOD * ifact[a-b] % MOD;
}
class PermutationCounts{
public:
    int countPermutations(int N, vector<int> pos){
        inv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
        for (int i=2;i<MAXN;i++){
            inv[i]=(long long)(MOD-MOD/i)*inv[MOD%i]%MOD;
            fact[i]=(long long)fact[i-1]*i%MOD;
            ifact[i]=(long long)ifact[i-1]*inv[i]%MOD;
        }
        vector<int> block;
       	int last = 0;
        sort( pos.begin(), pos.end() );
        for(auto it : pos){
            if( it - last ) block.push_back( it - last );
            last = it;
        } if( N - last ) block.push_back( N - last );
        int bn = block.size(); vector<int> bpsum(bn+1);
        for(int i=0; i<bn; i++) bpsum[i+1] = bpsum[i] + block[i];
        
        dp[0][0] = 1; dp[0][1] = 0;
        for(int i=0; i<bn; i++){
            for(int j=0; j<2; j++){
                for(int k=i, l=j; k<bn; k++, l^=1){
                    dp[k+1][l] = ( dp[k+1][l] + 0LL + dp[i][j]*1LL*mcomb( bpsum[k+1], bpsum[k+1] - bpsum[i] )%MOD ) %MOD;
                }
            }
        }
        return ( dp[bn][0] - dp[bn][1] + MOD ) %MOD;
    }
};
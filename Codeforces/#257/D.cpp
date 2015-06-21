// Jun 20 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int LGN = 20, MOD = 1e9+7;
int N,num,twop[1111111];
long long ans;
vector<int> a(1<<LGN), b(1<<LGN);
int main(){
	twop[0] = 1;
	for(int i=1;i<1111111;i++) twop[i] = twop[i-1]*2LL % MOD;

	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&num);
		a[num]++;
	}
	for(int i=0;i<LGN;i++){
		for(int j=0;j<1<<LGN;j++){
			b[j] = a[j];
			if( !( j & 1<<i ) ) b[j] += a[j^(1<<i)];
		} a.swap(b);
	}
	for(int i=0;i<1<<LGN;i++){
		int cnt = 0;
		for(int j=0;j<LGN;j++)
			if( i & (1<<j ) ) cnt++;
		if( cnt % 2 ){
			ans -= twop[a[i]];
		}else{
			ans += twop[a[i]];
		}
		ans %= MOD;
		if( ans < 0 ) ans += MOD;
	}
	printf("%lld",ans);
	return 0;
} 
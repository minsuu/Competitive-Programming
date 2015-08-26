// Aug 11 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7+10;
typedef long long lld;
bool siv[MAXN];
int pi[MAXN], P,Q;
vector<int> rub;
char buf[10];

int main(){
	for(int i=2; i*i<MAXN; i++){
		if( siv[i] ) continue;
		for(int j=i*2; j<MAXN; j+=i)
			siv[j] = true;
	}
	for(int i=2; i<MAXN; i++)
		pi[i] = pi[i-1] + !siv[i];

	for(int i=1; i<MAXN; i++){
		sprintf(buf,"%d",i); int sz = strlen(buf);
		bool isp = true;
		for(int i=0; i<sz && isp; i++)
			if( buf[i] != buf[sz-i-1] ) isp = false;
		if(isp) rub.push_back(i);
	}
	// for(int i=0; i<20; i++) printf("%d ",rub[i]);

	scanf("%d%d",&P,&Q);
	int ans, ret=0;
	for(ans=1; ans<MAXN-10; ans++){
		int r = lower_bound( rub.begin(), rub.end(), ans+1 ) - rub.begin();
		if( (lld)Q*pi[ans] <= (lld)P*r ){
			ret = max( ret, ans );
		}
	}
	printf("%d",ret);
	return 0;
} 
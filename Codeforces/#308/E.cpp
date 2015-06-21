// Jun 19 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef vector<lld> vi;
typedef vector<vi> vvi;
char str[5555]; int l;
vvi comps; vi psum;
int main(){
	scanf("%s",str); l = strlen(str);
	comps.push_back(vi(1, str[0]-'0'));
	for(int i=1;i<l;i+=2){
		if( str[i] == '+' ){
			lld agg = 0;
			while( !comps.empty() && comps.back().size() == 1 ){
				agg += comps.back()[0];
				comps.pop_back();
			} if(agg!=0) comps.push_back(vi(1, agg));
			comps.push_back(vi(1, str[i+1]-'0'));
		}else if( str[i] == '*' )
			comps.back().push_back( str[i+1]-'0');
	}
	psum.push_back(0LL);
	for(auto it : comps){
		lld t = 1LL;
		for(auto jt : it) t*=jt;
		psum.push_back( psum.back() + t );
	}
	lld maxi = psum.back();
	for(int bg = 0; bg < comps.size(); bg++){
		for(int en = bg+1; en < comps.size(); en++){
			int bgs = comps[bg].size(), ens = comps[en].size();
			lld ans = 1LL, midsum = 0LL;
			
			for(int j=0; j<bgs-1; j++)
				ans *= comps[bg][j];
			
			midsum += comps[bg].back();
			midsum += psum[en] - psum[bg+1];
			midsum += *comps[en].begin();
			ans *= midsum;

			for(int j=1; j<ens; j++)
				ans *= comps[en][j];

			maxi = max( maxi, psum[bg] + ans + ( psum.back() - psum[en+1] ) );
		}
	}
	printf("%lld",maxi);
	return 0;
}
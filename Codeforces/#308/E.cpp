// Jun 19 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef vector<lld> vi;
typedef vector<vi> vvi;
char str[5555]; int l;
vvi comps;
int main(){
	scanf("%s",str); l = strlen(str);
	comps.push_back(vi(1, str[0]-'0'));
	for(int i=1;i<l;i+=2){
		if( str[i] == '+' )
			comps.push_back(vi(1, str[i+1]-'0'));
		else if( str[i] == '*' )
			comps.back().push_back( str[i+1]-'0');
	}
	lld ans = 0LL;
	for(auto it : comps){
		lld t = 1LL;
		for(auto jt : it) t*=jt;
		ans += t;
	}
	printf("%lld ",ans);
	return 0;
} 
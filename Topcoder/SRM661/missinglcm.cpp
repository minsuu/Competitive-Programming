// Jun 24 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1111111;
class MissingLCM{
public:
	int sieve[MAXN];
	vector<int> pp;
	int getMin(int N){
		sieve[1] = 1;
		for(int i=2; i<MAXN; i++){
			if(sieve[i] != 0) continue;
			for(int j=i; j<MAXN; j+=i)
				sieve[j]++;
		}
		for(int i=1; i<MAXN; i++) {
			if(sieve[i] == 1) pp.push_back(i);
		}
		int p = lower_bound( pp.begin(), pp.end(), N+1 ) - pp.begin();
		return p==0? 1 : pp[p-1]*2;
	}
};

MissingLCM test;
int N;
int main(){
	scanf("%d",&N);
	printf("%d",test.getMin(N));
	return 0;
} 
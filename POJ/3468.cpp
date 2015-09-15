// Aug 28 2015, minsu( github : https://github.com/minsuu/ )
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct FenwickTree{
	int n;
	vector<long long> d;
	FenwickTree(int n) : n(n), d(n+1, 0) { }
	long long sum(int pos){
		long long res = d[0];
		for( ++pos; pos>0; pos&=(pos-1) ) res+=d[pos];
		return res;
	}
	void add(int pos, long long x) {
		for( ++pos; pos<=n; pos+=(pos&(-pos))) d[pos]+=x;
	}
};
struct FenwickRURQ{
	FenwickTree B1, B2;
	FenwickRURQ(int n) : B1(n), B2(n) {}
	long long query(int b) { return B1.sum(b) * b - B2.sum(b); }
	long long rquery(int a,int b) { return query(b) - query(a-1); }
	void radd(int i, int j, long long v) {
		B1.add(i, v); B1.add(j+1, -v);
		B2.add(i, v*(i-1)); B2.add(j+1, -v*j);
	}
};

char buf[8];
int N,Q, a,b,c;

int main(){
	scanf("%d%d",&N,&Q);
	FenwickRURQ ftree(N);
	for(int i=0; i<N; i++){
		scanf("%d",&a);
		ftree.radd( i, i, a );
	}
	while(Q--){
		scanf("%s", buf);
		if( *buf == 'Q' ){
			scanf("%d%d",&a,&b); a--; b--;
			printf("%lld\n",ftree.rquery(a,b));
		}
		if( *buf == 'C' ){
			scanf("%d%d%d",&a,&b,&c); a--; b--;
			ftree.radd(a,b,c);
		}
	}
	return 0;
}

/* 
4
55
9
15
*/
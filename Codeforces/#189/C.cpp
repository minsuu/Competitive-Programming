#include <bits/stdc++.h>
#define SZ(X) ( (int) X.size() )
using namespace std;
typedef long long lld;
typedef array<lld,2> line; // linear equation ax + b = y

int N, A[100100], B[100100];
inline bool cvx( const line& Q, const line& W, const line& E ){
	// compare QW && QE
	lld a = W[1] - Q[1], b = Q[0] - W[0];
	lld c = E[1] - Q[1], d = Q[0] - E[0];
	return c*b <= a*d;
}

// minimum convex
struct Convex{
	vector<line> cls;
	void put( const line& inp ){
		while( SZ(cls)>=2 && cvx( cls[SZ(cls)-2], cls[SZ(cls)-1], inp) ){
			cls.pop_back();
		}
		cls.push_back( inp );
	}
}

int main(){
		
	return 0;
}

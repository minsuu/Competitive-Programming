// Jun 19 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;

template<typename Ty> inline Ty abs(Ty a) { return a<0?-a:a; }
template<typename Ty> Ty gcd(Ty a, Ty b)
{
    while(b) { Ty tmp = a % b; a = b; b = tmp; }
    return a;
}
template<typename Ty>
struct v2 {
    Ty x,y,z;
    v2(Ty x=0, Ty y=0, Ty z=1) : x(x),y(y),z(z) {}
    bool operator < (const v2 &rhs) const {
    	if( x == rhs.x ){
    		if( y == rhs.y ) return z<rhs.z;
    		else return y<rhs.y;
    	}else return x<rhs.x;
    }
    bool operator == (const v2 &rhs) const{
        return (x==rhs.x) && (y==rhs.y) && (z==rhs.z);
    }
    v2 simplify() const {
        Ty gcdval = gcd(gcd(abs(x),abs(y)),abs(z));
        if(gcdval == 0) return *this;
        if(z<0 || (z==0 && x<0) || (z==0 && x==0 && y<0)) gcdval = -gcdval;
        return v2(x/gcdval, y/gcdval, z/gcdval);
    }
    Ty dot(const v2 &rhs) const{
        return x*rhs.x+y*rhs.y+z*rhs.z;
    }
    v2 cross(const v2 &rhs) const {
        return v2(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
    }
};
typedef v2<long long> P;

int N, a,b,c; vector<P> ps, ed;
int COMB[2222];
int main(){
	for(int i=0;i<2222;i++) COMB[i] = i*(i-1)/2;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",&a,&b);
		ps.push_back( P(a,b) );
	}
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			ed.push_back( ps[i].cross( ps[j] ).simplify() );
	sort( ed.begin(), ed.end() );

	long long ans = N*1LL*(N-1)*(N-2)/3/2/1;
	P last(0,0,0); int lastc=0; ed.push_back(P(0,0,0));
	for(int i=0; i<ed.size(); i++){
		// printf("(%lld,%lld,%lld) ",ed[i].x,ed[i].y,ed[i].z);
		if( !( last == ed[i] ) ){
			int n = lower_bound( COMB, COMB+2222, lastc ) - COMB;
			ans -= n*1LL*(n-1)*(n-2)/3/2/1;
			last = ed[i]; lastc = 0;
		} lastc++;
	}
	printf("%lld",ans);
	return 0;
} 
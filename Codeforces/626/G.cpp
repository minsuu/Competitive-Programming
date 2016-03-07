#include <cstdio>
#include <queue>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-10;

typedef pair<double, int> di;
int n,t,q, p[200200], a[200200], b[200200];

double dd( int i ){
	return p[i] * ( (b[i]+1.0)/(a[i]+b[i]+1.0) - (b[i]+0.0)/(a[i]+b[i]) );
}
double bb( int i ){
	return p[i] * ( (b[i]-1.0)/(a[i]+b[i]-1.0) - (b[i]+0.0)/(a[i]+b[i]) );
}

priority_queue<di> ins, del;
void put( int y ) {
	if( b[y] < a[y] ) ins.push( di( dd(y), y) );
	if( b[y] > 0 ) del.push( di( bb(y), y ) );
}
double ans = 0.0;
bool go(){
	while( !ins.empty() ){
		di tt = ins.top();
		if( fabs( tt.first - dd(tt.second) ) < eps && b[tt.second] < a[tt.second] )
			break;
		ins.pop();
	}
	if( ins.empty() ) return false;
	di tt = ins.top(); ins.pop();
	ans += tt.first; b[tt.second]++;
	put(tt.second);
	return true;
}
bool ba(){
	while( !del.empty() ){
		di tt = del.top();
		if( fabs( tt.first - bb(tt.second) ) < eps && b[tt.second] > 0 )
			break;
		del.pop();
	}
	if( del.empty() ) return false;
	di tt = del.top(); del.pop();
	ans += tt.first; b[tt.second]--;
	put(tt.second);
	return true;
}

int x,y,z;
int main(){
	scanf("%d%d%d",&n,&t,&q);
	for(int i=0; i<n; i++) scanf("%d",&p[i]);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	
	for(int i=0; i<n; i++)
		ins.push( di( dd(i), i ) );
	for(int i=0; i<t; i++)
		z += go();
	
	for(int i=0; i<q; i++){
		scanf("%d%d",&x,&y); y--;
		ans -= p[y] * (b[y]+0.0) / (a[y]+b[y]);
		if( x==1 ) a[y]++;
		if( x==2 ) a[y]--;
		if( 0<b[y] ) { z--; b[y]--; }
		ans += p[y] * (b[y]+0.0) / (a[y]+b[y]);
		put(y);
		z -= ba();
		for(int j=0; j<3 && z < t; j++)
			z += go();
		printf("%.10f\n",ans);
	}
	return 0;
}

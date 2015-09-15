// Aug 27 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef complex<double> Complex;
typedef long long lld;
const Complex I(0,1);
const double PI = acos(0) * 2;

int N, M;
int a[8888], b[8888], ans[8888];
int L[64][8888], R[64][8888];
Complex fl[8888], fr[8888];

double cosa[8888], sina[8888];

int rev (int num, int lg_n) {
    int res = 0;
    for (int i=0; i<lg_n; ++i)
        if (num & (1<<i))
            res |= 1<<(lg_n-1-i);
    return res;
}

void fft (Complex *a, int n, bool invert) {
    int lg_n = 0;
    while ((1 << lg_n) < n)  ++lg_n;
 
    for (int i=0; i<n; ++i)
        if (i < rev(i,lg_n))
            swap (a[i], a[rev(i,lg_n)]);
 
    for (int len=2; len<=n; len<<=1) {
        Complex wlen (cosa[len], sina[len] * (invert ? -1 : 1));
        for (int i=0; i<n; i+=len) {
            Complex w (1);
            for (int j=0; j<len/2; ++j) {
                Complex u = a[i+j],  v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w = w * wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] = a[i] * (1.0/n);
}

void muladd ( int n ){
	fft(fl, n, false); fft(fr, n, false);
	for(int i=0; i<n; i++) fl[i] *= fr[i];
	fft(fl, n, true);
	while( n>0 && fabs(fl[n-1].real()) < 1e-9 ) n--;

	for( int i=2; i<n; i++){
		ans[i] = ( ans[i] + lld(round(fl[i].real())) ) % M;
	}
}

int roundUp(int n) { int p=1; while(p<n) p*=2; return p; }
void dnc(int l, int r){
	if( r-l == 1 ){
		if( a[l] == 0 ) ans[1]++;
		if( b[l] == 0 ) ans[1]++;
		return;
	}
	if( r-l == 2 ){
		if( (a[l]^a[l+1]) == 0 ) ans[2]++;
		if( (a[l]^b[l+1]) == 0 ) ans[2]++;
		if( (b[l]^a[l+1]) == 0 ) ans[2]++;
		if( (b[l]^b[l+1]) == 0 ) ans[2]++;
		return;
	}

	int m = (l+r)/2, lc = 1, rc = 1;
	// add the count which contains m-1, m
	for(int i=m-1; i>=l; i--, lc++ ){
		int j = m-i;
		for(int k=0; k<64; k++) L[k][j] = 0;
		for(int k=0; k<64; k++){
			L[ k^a[i] ][ j ] += ( j==1 ? (k==0) : L[ k ][ j-1 ] );
			L[ k^a[i] ][ j ] %= M;
			L[ k^b[i] ][ j ] += ( j==1 ? (k==0) : L[ k ][ j-1 ] );
			L[ k^b[i] ][ j ] %= M;
		}
	}
	for(int i=m; i<r; i++, rc++ ){
		int j = i-m+1;
		for(int k=0; k<64; k++) R[k][j] = 0;
		for(int k=0; k<64; k++){
			R[ k^a[i] ][ j ] += ( j==1 ? (k==0) : R[ k ][ j-1 ] );
			R[ k^a[i] ][ j ] %= M;
			R[ k^b[i] ][ j ] += ( j==1 ? (k==0) : R[ k ][ j-1 ] );
			R[ k^b[i] ][ j ] %= M;
		}
	}

	int n = roundUp(max(lc, rc)) * 2;
	for(int i=0; i<64; i++){
		for(int j=0; j<n; j++)
			fl[j] = fr[j] = 0;
		for(int j=0; j<lc; j++)
			fl[j] = L[i][j];
		for(int j=0; j<rc; j++)
			fr[j] = R[i][j];
		muladd( n );
	}
	// dnc(l, m); dnc(m, r);
}

typedef pair<int,int> ii;
vector<ii> cand;

int main(){
	for(int i=1; i<8888; i++) cosa[i] = cos(2 * PI / i), sina[i] = sin(2 * PI / i);

	scanf("%d%d",&N,&M);
	for(int i=0; i<N; i++) scanf("%d",&a[i]);
	for(int i=0; i<N; i++) scanf("%d",&b[i]);
	cand.push_back( {0, N} );
	for(int i=0; i<cand.size(); i++){
		int l = cand[i].first, r = cand[i].second;
		dnc( l, r );
		int m = (l+r)/2;
		if( r - l != 1 ){
			cand.push_back( { l, m } );
			cand.push_back( { m, r } );
		}
	}
	for(int i=1; i<=N; i++) printf("%d\n",ans[i]);	
	return 0;
}
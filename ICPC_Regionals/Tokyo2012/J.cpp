#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<double, double> XY;
typedef pair<XY, double> XYZ;

set<double> divs;
map<XYZ, int> enc;

int gcd(int a,int b){
    if(a && b)
        while(a%=b^=a^=b^=a);
    return a+b;
}

void init(){
    divs.insert( 0.0 );
    for(int i=1; i<12; i++)
        for(int j=1; i+j<=12; j++)
            if( gcd(i, i+j) == 1 )
                divs.insert( (double)i/(i+j) );
    divs.insert( 1.0 );
    
    set<double> d( divs );
    for( auto it : divs ){
        d.insert( 1.0 + it ); d.insert( 2.0 + it );
    }
    for( auto k : d ){
        for(double i=0; i<=3.0; i+=1.0)
            for(double j=0; j<=3.0; j+=1.0){
                enc[ XYZ( XY( i, j ) , k ) ];
                enc[ XYZ( XY( i, k ) , j ) ];
                enc[ XYZ( XY( k, i ) , j ) ];
            }
    }
    int sz = 0;
    for( auto& it : enc ){
        it.S = sz++;
    }
}
const int MAXE = 5555555;
int eprev[MAXE], eto[MAXE], elast[7777], ecnt;
double ecost[MAXE];
char br[9][9][9];
int a,b,c,d,e,f;

#define SQ(X) ((X)*(X))
double dist( XYZ a, XYZ b ){
    return pow( SQ(a.F.F-b.F.F) + SQ(a.F.S-b.F.S) + SQ(a.S-b.S) , 0.5 );
}

inline void addEdge( XYZ a, XYZ b ){
    assert( enc.count(a) ); assert( enc.count(b) );
    int u = enc[ a ], v = enc[ b ]; double c = dist(a,b);
    if( u==v ) return;
    assert( ecnt+1 <= MAXE );
    eprev[ ecnt ] = elast[ u ]; eto[ ecnt ] = v; ecost[ ecnt ] = c; elast[ u ] = ecnt++;
    eprev[ ecnt ] = elast[ v ]; eto[ ecnt ] = u; ecost[ ecnt ] = c; elast[ v ] = ecnt++;
}
char buf[9];

int main(){
    init();
    while( 1 ){
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
        if( a==0 && b==0 && c==0 && d==0 && e==0 && f==0 ) break;
        for(int i=1; i<=3; i++){
            for(int j=1; j<=3; j++){
                scanf("%s", buf+1 );
                for(int k=1; k<=3; k++)
                    br[k][j][i] = ( buf[k] == '#' );
            }
        }
        memset( elast, -1, sizeof elast ); ecnt = 0;
        for(int x=0; x<=3; x++){
            for(int y=1; y<=3; y++){
                for(int z=1; z<=3; z++){
                    if( br[x][y][z] ^ br[x+1][y][z] ){ // only one blocks
                        // plane with fixed x, [y-1, y], [z-1, z];
                        for( auto it : divs )
                            for( auto jt : divs ){
                                addEdge( XYZ( XY( x, y-1+it ), z-1 ) , XYZ( XY( x, y-1+jt ), z ) );
                                addEdge( XYZ( XY( x, y-1 ), z-1+it ) , XYZ( XY( x, y ), z-1+jt ) );
                            }
                    }
                }
            }
        }
        for(int x=1; x<=3; x++){
            for(int y=0; y<=3; y++){
                for(int z=1; z<=3; z++){
                    if( br[x][y][z] ^ br[x][y+1][z] ){ // only one blocks
                        // plane with fixed y, [x-1, y], [z-1, z];
                        for( auto it : divs )
                            for( auto jt : divs ){
                                addEdge( XYZ( XY( x-1+it, y ), z-1 ) , XYZ( XY( x-1+jt, y ), z ) );
                                addEdge( XYZ( XY( x-1, y ), z-1+it ) , XYZ( XY( x, y ), z-1+jt ) );
                            }
                    }
                }
            }
        }
        for(int x=1; x<=3; x++){
            for(int y=1; y<=3; y++){
                for(int z=0; z<=3; z++){
                    if( br[x][y][z] ^ br[x][y][z+1] ){ // only one blocks
                        // plane with fixed z, [y-1, y], [z-1, z];
                        for( auto it : divs )
                            for( auto jt : divs ){
                                addEdge( XYZ( XY( x-1+it, y-1 ), z ) , XYZ( XY( x-1+jt, y ), z ) );
                                addEdge( XYZ( XY( x-1, y-1+it ), z ) , XYZ( XY( x, y-1+jt ), z ) );
                            }
                    }
                }
            }
        }
        vector<double> dist(7777, -1.0);
        int bg = enc[ XYZ( XY( a, b ), c ) ], en = enc[ XYZ( XY( d, e ), f ) ];
        priority_queue< pair<double, int> > pq; pq.push( { 0.0, bg } ); dist[bg] = 0.0;
        while( !pq.empty() ){
            double nd = -pq.top().F; int nw = pq.top().S; pq.pop();
            if( dist[nw] < nd ) continue;
            if( nw == en ) break;
            for( int e = elast[nw]; e != -1; e = eprev[e] ){
                double nc = ecost[e]; int nxt = eto[e];
                if( dist[nxt] == -1.0 || dist[nxt] > nd+nc ){
                    dist[nxt] = nd+nc;
                    pq.push( { -dist[nxt], nxt } );
                }
            }
        }
        printf("%.20f\n",dist[en]);
    }
    return 0;
}
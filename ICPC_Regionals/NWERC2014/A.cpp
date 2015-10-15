#include <bits/stdc++.h>
using namespace std;
struct v2{
    int x,y;
    explicit v2(int x_=0.0, int y_=0.0) : x(x_), y(y_) {}
    bool operator==(const v2& rhs){
        return (x==rhs.x) && (y==rhs.y);
    }
    bool operator<(const v2& rhs){
        return (x==rhs.x)? y<rhs.y : x<rhs.x;
    }
    v2 operator+(const v2& rhs){
        return v2(x+rhs.x, y+rhs.y);
    }
    v2 operator-(const v2& rhs){
        return v2(x-rhs.x, y-rhs.y);
    }
    v2 operator*(const int rhs){
        return v2(x*rhs, y*rhs);
    }
    double norm() const { return hypot(x,y); }
 
    int dot(const v2& rhs){
        return x*rhs.x+y*rhs.y;
    }
    int cross(const v2& rhs){
        return x*rhs.y-y*rhs.x;
    } 
};
double ccw(v2 a,v2 b){
    return a.cross(b);
}
double ccw(v2 p,v2 a,v2 b){
    return ccw(a-p,b-p);
}
bool segmentIntersects(v2 a,v2 b,v2 c,v2 d){
    double ab=ccw(a,b,c)*ccw(a,b,d);
    double cd=ccw(c,d,a)*ccw(c,d,b);
    if(ab==0 && cd==0){
        if(b<a) swap(a,b);
        if(d<c) swap(c,d);
        return !(b<c || d<a);
    }
    return ab<=0 && cd<=0;
}

v2 IN[55], OUT[55];
int N,M;

vector<v2> chull;
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d%d",&IN[i].x, &IN[i].y );
    scanf("%d",&M);
	for(int i=0; i<M; i++)
		scanf("%d%d",&OUT[i].x, &OUT[i].y );

	IN[N] = IN[0]; N++;
    OUT[M] = OUT[0]; M++;

	for(int i=0; i<N; i++){
		while( chull.size() >= 2 ){
			v2 ppr = chull[ (int) chull.size() - 2 ];
			v2 pr = chull[ (int) chull.size() - 1 ];
			if( ccw( ppr, pr, IN[i] ) < 0 ){
                chull.pop_back();
                int bg = -1, en = -1;
				for(int j=0; j<M; j++){
                    if( segmentIntersects( OUT[j], OUT[j+1], ppr, IN[i] ) ){
                        if( bg == -1 ) bg = j;
                        else en = j;
                    }
                } en++;

                if( bg != -1 ){
                    bg++;
                    // OUT[bg] and OUT[en] should be in hull
                    while( chull.size() >= 2 && ccw( chull[(int)chull.size()-2], chull[(int)chull.size()-1], OUT[bg] ) < 0 ) chull.pop_back();
                    vector<v2> phull;
                    phull.push_back( OUT[bg] );
                    for(int j=bg+1; j<=en; j++){
                        while( phull.size() >= 2 && ccw( phull[(int)phull.size()-2], phull[(int)phull.size()-1], OUT[j] ) < 0 ) phull.pop_back();
                        phull.push_back( OUT[j] );
                    }
                    chull.insert( --chull.end(), phull.begin(), phull.end() );
                    break;
                }
			}else break;
		}
		chull.push_back( IN[i] );
	}
    double total = 0.0;
	for(int i=0; i<( chull.size() - 1 ); i++){
        printf("%d %d\n",chull[i].x, chull[i].y );
        v2 d = chull[i+1] - chull[i];
        total += d.norm();
    }
    printf("%.10f",total);
	return 0;
}
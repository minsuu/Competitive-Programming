#include <bits/stdc++.h>
// #include "elephants.h"
using namespace std;
#define MAXE 150051
#define BLOCK 400

int n, bn, l, ele[MAXE], tmp[MAXE], cooltime;
int p[BLOCK][BLOCK*2], sz[BLOCK][BLOCK*2], la[BLOCK][BLOCK*2], pn[BLOCK], pl[BLOCK];

void calc(int b){
  for(int i=pn[b]-1; i>=0; i--){
    int nxt = lower_bound( p[b]+i+1, p[b]+pn[b], p[b][i] + l + 1 ) - p[b];
    if( nxt == pn[b] ) sz[b][i] = 1, la[b][i] = p[b][i] + l + 1;
    else sz[b][i] = sz[b][nxt] + 1, la[b][i] = la[b][nxt];
  }
//  for(int i=0; i<pn[b]; i++) printf("%d ",p[b][i]);   printf("\n");
//  for(int i=0; i<pn[b]; i++) printf("%d ",sz[b][i]);  printf("\n");
//  for(int i=0; i<pn[b]; i++) printf("%d ",la[b][i]);  printf("\n");
}

void mkblock( int X[] ){
  for(int i=0; i<bn; i++) pn[i] = 0;
  for(int i=0; i<n; i++){
    int b = i / BLOCK;
    int& bs = pn[b];
    p[b][bs++] = X[i];
  } bn = ( n-1 ) / BLOCK + 1;
  for(int i=0; i<bn; i++)
    calc(i), pl[i] = p[i][pn[i]-1];
}

void init(int N, int L, int X[]){
  n = N; l = L;
  for(int i=0;i<n;i++) ele[i] = X[i];
  mkblock( X );
}

int update(int i, int y)
{
  if( ++cooltime == BLOCK ){
    cooltime = 0;
    bool xd = false, ya = false; int tn = 0, x;
    x = ele[i]; ele[i] = y;
    for(int i=0; i<bn; i++)
      for(int j=0; j<pn[i]; j++){
        if( !xd && p[i][j] == x ) { xd = true; continue; }
        if( !ya && p[i][j] > y ) { ya = true; tmp[tn++] = y; }
        tmp[tn++] = p[i][j];
      }
    if(!ya) tmp[tn++] = y;
    mkblock( tmp );   
  }else{
    int xb = lower_bound( pl, pl + bn, ele[i] ) - pl;
    int xp = lower_bound( p[xb], p[xb] + pn[xb], ele[i] ) - p[xb];
    pn[xb]--; for(int i=xp; i<pn[xb]; i++) p[xb][i] = p[xb][i+1];
    calc(xb); if(pn[xb]!=0) pl[xb] = p[xb][pn[xb]-1];

    ele[i] = y;
    int yb = lower_bound( pl, pl + bn, ele[i] ) - pl; if(yb == bn) yb--;
    int yp = lower_bound( p[yb], p[yb] + pn[yb], ele[i] ) - p[yb];
    for(int i=pn[yb]; i>yp; i--) p[yb][i] = p[yb][i-1]; pn[yb]++; p[yb][yp] = ele[i];
    calc(yb); pl[yb] = p[yb][pn[yb]-1];
  }

  int ret = 0, pos = -1;
  for(int i=0; i<bn; i++){
    int j = lower_bound( p[i], p[i] + pn[i], pos ) - p[i];
    if( j == pn[i] ) continue;
    ret += sz[i][j]; pos = la[i][j];
  }
  return ret;
}

#define MAX_N 1000000
#define MAX_M 1000000

static int N,L,M;
static int X[MAX_N];
static int ii[MAX_M];
static int yy[MAX_M];
static int sol[MAX_M];

inline 
void my_assert(int e) {if (!e) abort();}

void read_input()
{
  int i;
  my_assert(3==scanf("%d %d %d",&N,&L,&M));
  for(i=0; i<N; i++)
  my_assert(1==scanf("%d",&X[i]));
  for(i=0; i<M; i++)
  my_assert(3==scanf("%d %d %d",&ii[i],&yy[i],&sol[i]));
}

int main()
{
  int i, ans;

  read_input();
  init(N,L,X);
  for(i=0; i<M; i++) {
  ans = update(ii[i],yy[i]);
  if(ans==sol[i])continue;
  printf("Incorrect.  In %d-th move, answered %d (%d expected).\n",
   i+1, ans, sol[i]);
  return 0;
  }
  printf("Correct.\n");
  return 0;
}

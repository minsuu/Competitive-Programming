// #include "ricehub.h"
#include <bits/stdc++.h>
using namespace std;
const int MAXR = 111111;
typedef long long lld;
lld psum[MAXR];
lld interval( int i, int j ) {
  // [i, j]
  int m = (i + j)/2, x = psum[m] - psum[m-1];
  return ( 2*m - i - j ) * 1LL * x - psum[m-1] + psum[i-1] + psum[j] - psum[m];
}
int besthub(int R, int L, int X[], long long B)
{
  for(int i=1; i<=R; i++) psum[i] = psum[i-1] + X[i-1];
  int j = 1, ret = 0;
  for(int i=1; i<=R; i++)
    while( j<=R && interval(i, j) <= B ) ret = max( ret, j-i+1), j++;
  return ret;
}



#define MAX_R  1000000

static int R, L;
static long long B;
static int X[MAX_R];
static int solution;

inline 
void my_assert(int e) {if (!e) abort();}

static void read_input()
{
  int i;
  my_assert(3==scanf("%d %d %lld",&R,&L,&B));
  for(i=0; i<R; i++)
    my_assert(1==scanf("%d",&X[i]));
  my_assert(1==scanf("%d",&solution));
}

int main()
{
  int ans;
  read_input();
  ans = besthub(R,L,X,B);
  if(ans==solution)
    printf("Correct.\n");
  else
    printf("Incorrect.  Returned %d instead of %d.\n",ans,solution);

  return 0;
}

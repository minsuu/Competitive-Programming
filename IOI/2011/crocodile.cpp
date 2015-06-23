#include <bits/stdc++.h>
// #include "crocodile.h"
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vi;
const int MAXN = 111111;
int visit[MAXN]; vi linkd[MAXN]; priority_queue<ii> pq;
int travel_plan(int N, int M, int R[][2], int L[], int K, int P[])
{
  for(int i=0; i<N; i++) linkd[i].clear();
  memset( visit, 0, sizeof visit);
  for(int i=0; i<M; i++){
    linkd[ R[i][0] ].push_back( { R[i][1], L[i] } );
    linkd[ R[i][1] ].push_back( { R[i][0], L[i] } );
  }
  for(int i=0; i<K; i++) pq.push( { 0, P[i] } ), visit[ P[i] ] = 1;
  while(!pq.empty()){
    int here = pq.top().second, d = -pq.top().first; pq.pop();
    if( ++visit[here] != 2 ) continue;
    if( here == 0 ) return d;
    for(auto it : linkd[here])
      pq.push( { -d-it.second, it.first } );
  }
  return -1;
}



#define MAX_N 50000
#define MAX_M 10000000

static int N, M;
static int R[MAX_M][2];
static int L[MAX_M];
static int K;
static int P[MAX_N];
static int solution;

inline 
void my_assert(int e) {if (!e) abort();}

void read_input()
{
  int i;
  my_assert(3==scanf("%d %d %d",&N,&M,&K));
  for(i=0; i<M; i++)
    my_assert(3==scanf("%d %d %d",&R[i][0],&R[i][1],&L[i]));
  for(i=0; i<K; i++)
    my_assert(1==scanf("%d",&P[i]));
  my_assert(1==scanf("%d",&solution));
}

int main()
{
  int ans;
  read_input();
  ans = travel_plan(N,M,R,L,K,P);
  if(ans==solution)
    printf("Correct.\n");
  else
    printf("Incorrect. Returned %d, Expected %d.\n",ans,solution);

  return 0;
}

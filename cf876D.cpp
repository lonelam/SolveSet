#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 10;
int sum[maxn];
int cir[maxn];
int n;
int fa[maxn];
int rnk[maxn];
int sz[maxn];
map<int,int> cnt;
void del(int x)
{
  if (--cnt[x] == 0)
  {
    cnt.erase(x);
  }
}
void add(int x)
{
  cnt[x]++;
}
int fnd(int x)
{
  if (fa[x] == x)
  {
    return x;
  }
  return fa[x] = fnd(fa[x]);
}
void join(int x, int y)
{
  int fx = fnd(x), fy = fnd(y);
  if (rnk[fx] == rnk[fy])
  {
    rnk[fx]++;
    fa[fy] = fx;
    del(sz[fy]);
    del(sz[fx]);
    sz[fx] += sz[fy];
    add(sz[fx]);
  }
  else if (rnk[fx] > rnk[fy])
  {
    fa[fy] = fx;
    del(sz[fy]);
    del(sz[fx]);
    sz[fx] += sz[fy];
    add(sz[fx]);
  }
  else
  {
    fa[fx] = fy;
    del(sz[fy]);
    del(sz[fx]);
    sz[fy] += sz[fx];
    add(sz[fy]);
  }
  fx = fnd(x);
  /*
  if (fx == fnd(n))
  {
    del(sz[fx]);
    sz[fx] = 0;
    add(0);
  }
  */
}
void init()
{
  for (int i = 1; i <= n; i++)
  {
    rnk[i] == 1;
    fa[i] = i;
    sz[i] = 1;
  }
  cnt[1] = n-1;
  cnt[0] = 1;
}
int main()
{
  while(~scanf("%d", &n))
  {
    n++;
    cir[n] = 1;
    int segnum = 1;
    int segmax = 1;
    int rep;
    init();
    sz[n] = 0;
    printf("1 ");
    for (int i = 1; i < n; i++)
    {
      scanf("%d", &rep);
      cir[rep] = 1;
      if ((rep != 1 && cir[rep-1]) && (cir[rep+1]))
      {
        join(rep-1, rep);
        join(rep+1, rep);
        segnum--;
      }
      else if ((rep == 1 || !cir[rep-1]) && !cir[rep+1])
      {
        segnum++;
      }
      else if (cir[rep+1])
      {
        join(rep, rep+1);
      }
      else if (rep != 1 && cir[rep-1])
      {
        join(rep, rep-1);
      }

      segmax = max(cnt.rbegin()->first, 1);
    //  cout << segnum << endl;
      printf("%d%c", i - sz[fnd(n)] + 1, (i==n-1)?'\n':' ');
    }
  }
}

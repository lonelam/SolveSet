#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
const int maxk = 80 + 10;
int n, k;
int targetk;
int leftlen[maxn][maxk];
// int rightlen[maxn][maxk];
//first k plus one node
//deque<int> first_k[maxn << 2];
pair<int, deque<int> > lazy[maxn << 2];
void update(pair<int, deque<int> >& tar, int x)
{
  tar.second.push_front(x);
  if (tar.second.size() > 2)
  {
    tar.second.pop_back();
  }
  tar.first++;
}
void pushdown(int x)
{
  if (!lazy[x].first)
  {
    for (int i = lazy[x].second.size() - 1; i >= 0; i--)
    // for (int v: lazy[x])
    {
      int v = lazy[x].second[i];
      update(lazy[x << 1], v);
      update(lazy[x << 1 | 1], v);
      // update(first_k[x << 1| 1], v);
      // update(first_k[x << 1], v);
    }
    if (lazy[x].second.size() >= 2)
    {
      lazy[x << 1] += lazy[x].second.size() - 2;
    }
    lazy[x].second.clear();
  }
}
void ins(int ql, int qr, int val, int L = 1, int R = n, int o = 1)
{
  if (qr < L || ql > R)
  {
    return;
  }
  if (ql <= L && R <= qr)
  {
    update(lazy[o], val);
    return;
    // update(first_k[o], val);
  }
  const int mid = (L + R) / 2;
  pushdown(o);
  if (R >= ql)
  {
    ins(ql, qr, val, L, mid, o << 1);
  }
  if (L <= qr)
  {
    ins(ql, qr, val, mid + 1, R, o << 1 | 1);
  }
}
void clear(int L = 1, int R = n, int o = 1)
{
  lazy[o].clear();
  if (L == R)
  {
    return;
  }
  const int mid = (L + R) / 2;
  clear(L, mid, o << 1);
  clear(mid + 1, R, o << 1 | 1);
}
deque<int> & query(int qx, int L = 1, int R = n, int o = 1)
{
  if (L == R)
  {
    return lazy[o];
  }
  const int mid = (L + R) / 2;
  pushdown(o);
  if (qx <= mid)
  {
    return query(qx, L, mid, o << 1);
  }
  return query(qx, mid + 1, R, o << 1 | 1);
}
ll ans;
int A[maxn];
void work()
{
  // memset(rightlen, 0,sizeof(rightlen));
  memset(leftlen,0,sizeof(leftlen));
  clear();
  for (int i = 1; i <= n; i++)
  {
    deque<int> & Q = query(A[i]);
    if (Q.empty())
    {
      leftlen[i][0] = i;
    }
    else
    {
      leftlen[i][0] = i - Q[0];
    }
    for (int j = 1; j < Q.size(); j++)
    {
      leftlen[i][j] = Q[j-1] - Q[j];
    }
    if (!Q.empty())leftlen[i][Q.size()] = Q.back();
    ins(1, A[i], i);
  }
  clear();
  for (int i = n; i >= 1; i--)
  {
    deque<int> & Q = query(A[i]);
    if (Q.empty())
    {
      // rightlen[i][0] = n - i + 1;
        ans += (ll) leftlen[i][k-1] * (ll)(n-i+1) * (ll)i;
    }
    else
    {
      // rightlen[i][0] = Q[0] - i;
      ans += (ll)leftlen[i][k-1] * (ll)(Q[0] - i) * (ll)i;
    }
    for (int j = 1; j < Q.size(); j++)
    {
      // rightlen[i][j] = Q[j] - Q[j-1];
      ans += (ll)leftlen[i][k - j - 1] * (ll)(Q[j] - Q[j-1]) *(ll)i;
    }
    if (!Q.empty() && Q.size() < k) //rightlen[i][Q.size()] = n + 1 - Q.back();
    {
      ans += (ll) leftlen[i][k - 1 - Q.size()] * (ll)(n + 1 - Q.back()) * (ll)i;
    }
    ins(1,A[i],i);
  }
  // for (int i = 1; i <= n; i++)
  // {
  //   for (int j = 0; j < k; j++)
  //   {
  //     int s = k - j - 1;
  //       ans += (ll)leftlen[i][j] * rightlen[i][s] * (ll)i;
  //   }
  // }
}
int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d%d", &n, &k);
      for (int i = 1; i <= n; i++)
      {
        scanf("%d", A + i);
      }
      ans = 0;
      work();
      printf("%lld\n", ans);
    }
  }
}

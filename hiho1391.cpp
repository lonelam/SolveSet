#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 20000 + 100;
struct seg
{
  int l, r, dam;
  bool operator<(const seg & rhs) const
  {
    return l > rhs.l;
  }
} segs[maxn];
bool cmp(const seg & lhs, const seg & rhs)
{
  return lhs.r < rhs.r;
}
int Ta, Tb, X, N, M;
int Tl[maxn], Tc[maxn], D[maxn];
int main()
{
  while(scanf("%d%d%d%d%d", &Ta, &Tb, &X, &N, &M) != EOF)
  {
    int tot = 0;
    int ans = inf;
    int suffer = 0;
    for (int i = 0; i < N; i++)
    {
      scanf("%d%d%d", Tl + i, Tc + i, D + i);
      if (Tl[i] + Tc[i] >= X && Tl[i] + Tc[i] <= X + Tb)
      {
        segs[tot].l = Tl[i] + 2 * Tc[i];
        const int term =(X + Tb - Tl[i] - Tc[i] ) / (2 * Tc[i]) ;
        segs[tot].r = segs[tot].l + term * 2 * Tc[i];
        segs[tot++].dam = D[i];
        suffer += D[i];
      }
    }
    for (int i = 0; i < M; i++)
    {
      scanf("%d%d%d", Tl + i, Tc + i, D + i);
      if (Tl[i] + 2 * Tc[i] >= X && Tl[i] + 2 * Tc[i] <= X + Tb)
      {
        segs[tot].l = Tl[i] + Tc[i];
        const int term = (X + Tb - Tl[i] - 2 * Tc[i] ) / (2 * Tc[i]) + 1 ;
        segs[tot].r = segs[tot].l + term * 2 * Tc[i];
        segs[tot++].dam = D[i];
      }
      else
      {
        segs[tot].l = segs[tot].r = Tl[i] + Tc[i];
        segs[tot++].dam = D[i];
      }
      suffer += D[i];
    }
    priority_queue<seg> Q;
    sort(segs, segs + tot, cmp);
    if (tot == 0)
    {
      printf("%d\n", suffer);
    }
    else
    {
      int defr = segs[0].r, defl = defr - Ta;
      for (int i = 0; i < tot; i++)
      {
        defr = segs[i].r, defl = defr - Ta;
        if (segs[i].l >= defl)
        {
          Q.push(segs[i]);
          suffer -= segs[i].dam;
        }
        while(!Q.empty() && Q.top().l < defl)
        {
          suffer += Q.top().dam;
          Q.pop();
        }
        ans = min(ans, suffer);
      }
      printf("%d\n", ans);
    }
  }
}

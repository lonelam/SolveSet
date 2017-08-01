#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 100;
const int maxk = 81;
int A[maxn];
int rnk[maxn];
bool cmp(int lhs, int rhs)
{
  return A[lhs] < A[rhs];
}
int l[maxn], r[maxn];
int n, k;
int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d%d", &n, &k);
      for (int i = 0; i < n; i++)
      {
        scanf("%d", A + i);
        rnk[i] = i;
      }
      sort(rnk, rnk + n, cmp);
      for (int i = 1; i < n; i++)
      {
        l[i] = i-1;
      }
      l[0] = -1;
      for (int i = 0; i + 1< n; i++)
      {
        r[i] = i + 1;
      }
      r[n-1] = -1;
      ll ans = 0;
      for (int i = 0; i < n; i++)
      {
        int p = rnk[i];
        static ll tmpleft[maxk], tmpright[maxk];
        memset(tmpleft,0,sizeof(tmpleft));
        memset(tmpright,0,sizeof(tmpright));
        for (int j = 0; j < k && p != -1; j++)
        {
          if (l[p] != -1) tmpleft[j] = p - l[p];
          else tmpleft[j] = p+1;
          p = l[p];
        }
        p = rnk[i];
        for (int j = 0; j < k && p != -1; j++)
        {
          if (r[p] != -1) tmpright[j] = r[p] - p;
          else tmpright[j] = n - p;
          p =  r[p];
        }
        for (int j = 0; j < k; j++)
        {
          int s = k - 1 - j;
          ans += tmpleft[j] * tmpright[s] * A[rnk[i]];
        }
        if (l[rnk[i]] != -1)
        {
          r[l[rnk[i]]] = r[rnk[i]];
        }
        if (r[rnk[i]] != -1)
        {
          l[r[rnk[i]]] = l[rnk[i]];
        }
      }
      printf("%lld\n", ans);
    }
  }

}

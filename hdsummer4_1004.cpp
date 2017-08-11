#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 60000 + 100;
int a[maxn], b[maxn];
int n;
int lsb(int x)
{
  return x & (-x);
}
void add(int pos, int x)
{
  while(pos <= n)
  {
    a[pos] += x;
    pos += lsb(pos);
  }
}
int query(int pos)
{
  int ret = 0;
  while(pos)
  {
    ret += a[pos];
    pos -= lsb(pos);
  }
  return ret;
}
bool is_AC[maxn];
vector<int> G[maxn];
int A[maxn];
int last[maxn];
int pool[maxn], top, sz, tot;
int L[maxn], R[maxn];
int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      for (int i = 1; i <= n; i++)
      {
        G[i].clear();
      }
      for (int i = 1; i <= n; i++)
      {
        scanf("%d", A + i);
        G[A[i]].push_back(i);
      }
      tot = 0;
      set<int> instk;
      memset(last, -1, sizeof(last));
      memset(a, 0, sizeof(a));
      memset(b, 0, sizeof(b));
      memset(is_AC, 0, sizeof(is_AC));
      top = 0;
      sz = 1;
      L[0] = -1;
      R[0] = -1;
      ld ans = 1;
      // stk[top++] = 0;
      for (int i = 1; i <= n; i++)
      {
        if (last[A[i]] != -1)
        {
          add(last[A[i]], -1);
          auto it = instk.lower_bound(last[A[i]]);
          if (it != instk.end() && L[*it] != -1)
          {
            int mid = *it;
            while(R[mid] != -1 && (query(R[mid]) - query(mid)) * (mid - L[mid]) >= (query(mid) - query(L[mid])) * (R[mid] - mid))
            {
              R[L[mid]] = R[mid];
              L[R[mid]] = L[mid];
              instk.erase(mid);
              mid = R[mid];
              sz--;
            }
          }
        }
        else
        {
          tot++;
        }
        add(i, 1);
        last[A[i]] = i;
        while(sz > 1)
        {
          if ( (query(i) - query(top)) * (top - L[top]) >= (query(top) - query(L[top])) * (i - top))
          {
            sz--;
            instk.erase(top);
            top = L[top];
            R[top] = -1;
          }
          else
          {
            break;
          }
        }
        R[top] = i;
        L[i] = top;
        R[i] = -1;
        top = i;
        sz++;
        // stk[top++] = i;
        if (sz > 1)
        {
          ans = min(ans, (ld)(query(i) - query(L[i])) / (ld)(i - L[i]));
        }
      }
      printf("%.10llf\n", (double)ans);
    }
  }
}

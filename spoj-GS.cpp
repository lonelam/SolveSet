#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
struct mat
{
  double a[16][16];
  int sz;
  mat(int _sz):sz(_sz) {memset(a,0,sizeof(a));}
  mat operator *(mat & rhs)
  {
    mat ret(sz);
    for (int k = 0; k < sz; k++)
    {
      for (int i = 0; i < sz; i++)
      {
        for (int j = 0; j < sz; j++)
        {
          ret.a[i][j] += a[i][k] * rhs.a[k][j];
        }
      }
    }
    return ret;
  }
  void output()
  {
    for (int i = 0; i < sz; i++)
    {
      for (int j = 0; j < sz; j++)
      {
        cout << a[i][j] << "\t";
      }
      cout <<endl;
    }
  }
};
int T;
int n;
int main()
{
  scanf("%d", &T);
  while(T--)
  {
    int s,t;
    scanf("%d%d%d", &n, &s, &t);
    mat base(n);
    s--;t--;
    for (int i = 1; i < n; i++)
    {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--;v--;
      base.a[v][u] += w;
      base.a[u][v] += w;
    }
    for (int i = 0; i < n; i++)
    {
      double cnt = 0;
      for (int j = 0; j < n; j++)
      {
        cnt += base.a[i][j];
      }
      if (cnt != 0)
      for (int j = 0; j < n; j++)
      {
        base.a[i][j] /= cnt;
      }
    }
    for (int i = 0; i < n; i++)
    {
      base.a[t][i] = 0;
    }
    double pos = 0;
    mat ans(n);
    // base.output();
    ans.a[s][s] = 1;
    for (int i = 1; i < 10000; i++)
    {
      ans = ans * base;
      pos += ans.a[s][t] * (double)i;
      // printf("%lf\n", ans.a[s][t] * i);
    }
    printf("%.5lf\n", pos);
  }
}

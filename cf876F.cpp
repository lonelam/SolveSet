#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
vector<int> G[100];
int last[100];
int a[maxn];
set<int> rem, lblb;
int main()
{
  int n;
  while(~scanf("%d", &n))
  {
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", a + i);
    }
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n; i++)
    {
      int lbrb = -1;
      for (int j = 0; j < 32; j++)
      {
        if ((a[i] >> j) & 1)
        {
          last[j] = i;
          for (int k : G[j])
          {
            if (rem.find(k) != rem.end())
            {
              rem.erase(k);
            }
          }
          G[j].clear();
        }
        else
        {
          lbrb = max(lbrb, last[j]);
        }
      }
      if (rem.empty())
      {
        ans += lbrb + 1;
        //cout << i << endl;
      }
      else
      {
        ans += max(lbrb - *rem.rbegin(), 0);
      }
      for (int j = 0; j < 32; j++)
      {
        if (!((a[i] >> j) & 1))
        {
          G[j].push_back(i);
        }
      }
      rem.insert(i);
    }
    printf("%lld\n", ans);
  }
}

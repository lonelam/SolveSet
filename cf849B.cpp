#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int n;
int y[maxn];
int vis[maxn];

bool lineup(pii a, pii b, pii c)
{
  return (ll)(a.x - b.x) * (c.y - b.y) == (ll)(a.y - b.y) * (c.x - b.x);
}
bool check()
{
  for (int i = 2; i <= n; i++)
  {
    memset(vis, 0, sizeof(vis));
    vector<int> unvis;
    for (int j = 1; j <= n; j++)
    {
      if (lineup({1, y[1]}, {i, y[i]}, {j, y[j]}))
      {
        vis[j]++;
      }
      else
      {
        unvis.push_back(j);
      }
    }
    bool all = true;
    if (unvis.size() == 0) continue;
    else if (unvis.size() < 3) return true;
    for (int j = 1; j <= n; j++)
    {
      
    }
  }

}
int main()
{
  scanf("%d", &n);
  for (int i = 1;  i <= n; i++)
  {
    scanf("%d", y + i);
  }
}

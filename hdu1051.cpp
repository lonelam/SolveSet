#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 5;
int vis[maxn];
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    int n;
    scanf("%d", &n);
    //cout << n << endl;
    vector<pair<int, int> > v;
    int tw, th;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d",&tw, &th);
      v.push_back({tw, th});
    }
    sort(v.begin(), v.end());
    memset(vis,0,sizeof(vis));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        vis[i] = 1;
        int o = i;
        for (int j = i+1; j < n; j++)
        {
          if (!vis[j] && v[j].first>=v[o].first && v[j].second >= v[o].second)
          {
            o = j;
            vis[j] = 1;
          }
        }
        ans++;
      }
    }
    printf("%d\n", ans);
  }

}

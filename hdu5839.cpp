#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200 + 10;
int x[maxn], y[maxn], z[maxn];
int caldis(int alpha, int beta)
{
  int dx = abs(x[alpha] - x[beta]), dy = abs(y[alpha] - y[beta]), dz = abs(z[alpha] - z[beta]);
  return dx * dx + dy * dy + dz * dz;
}
int dis[maxn][maxn];
int n;
int main()
{
  int T, kase = 1;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
        scanf("%d%d%d", x + i, y + i, z + i);
      }
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          dis[i][j] = caldis(i, j);
        }
      }
      int ans = 0;
      for (int i = 0; i < n; i++)
      {
        for (int j = i + 1; j < n; j++)
        {
          map<int, vector<int> > angles;
          for (int k = 0; k < n; k++)
          {
            if (j != k && i != k && dis[i][k] == dis[j][k])
            {
              //cout << i <<" "<< j <<" "<< k << endl;
              angles[dis[i][k]].push_back(k);
            }
          }
          for (auto p : angles)
          {
            int sz = p.second.size();
            for (int k = 0; k < sz; k++)
            {
              for (int m = k + 1; m < sz; m++)
              {
                int c = p.second[k], d = p.second[m];
                if (x[c] + x[d] == x[i] + x[j] && y[c] + y[d] == y[i] + y[j] && z[c] + z[d] == z[i] + z[j]) continue;
                if (dis[p.second[k]][p.second[m]] == dis[i][j] && dis[i][j] == dis[p.second[k]][i])
                {
                  ans += 1;
                }
                else ans += 3;
                //cout << dis[p.second[k]][p.second[m]] <<" "<< dis[i][j] << endl;
              }
            }
          }
        }
      }
      printf("Case #%d: %d\n", kase++, ans/ 6);
    }
  }
}

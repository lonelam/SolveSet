#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 2100;
vector<pair<int,int>> H[maxn];
int n, k;
int dep[maxn][maxn];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int x, y, g;
int main()
{
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++)
  {
    scanf("%d%d%d",&x, &y, &g);
    dep[x][y] = g;
    H[g].push_back({x, y});
  }
  for (int j = 2048; j >= 0; j--)
  {
    for (pair<int,int> p: H[j])
    {
      for (int d = 0; d < 4; d++)
      {
        pair<int,int> tp = {p.first + dx[d], p.second + dy[d]};
        if (tp.first >= 0 && tp.first < n && tp.second >= 0 && tp.second < n && dep[tp.first][tp.second] < j-1)
        {
          dep[tp.first][tp.second] = j-1;
          H[j-1].push_back(tp);
        }
      }
    }
  }
  for (int i = 0;i  < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d%c", dep[i][j], (j==n-1)?'\n':' ');
    }
  }
}

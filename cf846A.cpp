#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int a[maxn];
int last[2];
int cnt[maxn][2];
int rcnt[maxn][2];
int main()
{
  int n;

  cin >> n;
  last[1] = last[0] = -1;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    last[a[i]] = i;
    cnt[i][a[i]]++;
    rcnt[i][a[i]]++;
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cnt[i][j]+=cnt[i-1][j];
    }
  }
  for (int i = n - 1; i >= 1; i--)
  {
    for (int j = 0; j < 2; j++)
    {
      rcnt[i-1][j] += rcnt[i][j];
    }
  }
  int ans = max(rcnt[0][1], rcnt[0][0]);
  for (int i = 0; i < n; i++)
  {
    ans = max(ans, cnt[i][0] + rcnt[i + 1][1]);
  }
  cout << ans << endl;
}

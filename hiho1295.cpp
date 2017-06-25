#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
bool nprime[maxn];
int prime[maxn];
int tot = 0;
void init()
{
  nprime[1] = true;
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
    {
      prime[tot++] = i;
    }
    for (int j = 0; j < tot; j++)
    {
      if (i * prime[j] > maxn) break;
      nprime[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
int main()
{
  init();
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 2; i <= n; i++)
  {
    if (!nprime[i]) ans++;
  }
  cout << ans << endl;
}

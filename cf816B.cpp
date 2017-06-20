#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
int cnt[maxn];
int main()
{
  int n, k, q;
  scanf("%d%d%d", &n, &k, &q);
  int x, y;
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &x, &y);
    cnt[x]++;
    cnt[y + 1]--;
  }
  for (int i = 1; i <= 200000; i++)
  {
    cnt[i] += cnt[i - 1];
  }
  for (int i = 1; i <= 200000; i++)
  {
    cnt[i] = cnt[i] >= k;
  }
  for (int i = 1; i <= 200000; i++)
  {
    cnt[i] += cnt[i - 1];
  }
  for (int i = 0; i < q; i++)
  {
    scanf("%d%d", &x, &y);
    printf("%d\n", cnt[y] - cnt[x - 1]);
  }
  return 0;
}

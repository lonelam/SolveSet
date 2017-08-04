#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
ll phi[maxn];
int num[maxn];
int p[maxn][20];
void init()
{
  phi[1] = 1;
  for (int i = 2; i < maxn; i++)
  {
    if (!phi[i])
    {
      for (int j = i; j < maxn; j += i)
      {
        if (!phi[j])
        {
          phi[j] = j;
        }
        phi[j] = phi[j] * (i - 1) / i;
        p[j][num[j]++] = i;
      }
    }
    phi[i] += phi[i-1];
  }
}
int get(int b, int h)
{
  int ans = 0;
  for (int i = 1; i < (1 << num[b]) ; i++)
  {
    int cnt = 0, nu = 1;
    for (int j = 0; j < num[b]; j++)
    {
      if ((1 << j) & i)
      {
        cnt++;
        nu *= p[b][j];
      }
    }
    //容斥: 奇数增偶数减
    if (cnt & 1) ans += h / nu;
    else ans -= h / nu;
  }
  return ans;
}
int main()
{
  int t, a, b, c, d, k;
  init();
  scanf("%d", &t);
  int kase = 1;
  while(t--)
  {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
    printf("Case %d: ", kase++);
    if (k == 0)
    {
      puts("0");
      continue;
    }
    if (b > d) swap(b, d);
    b /= k, d /= k;
    ll ans = phi[b];
    for (int i = b + 1; i <= d; i++)
    {
      ans += b - get(i, b);
    }
    printf("%I64d\n", ans);
  }
  return 0;
}

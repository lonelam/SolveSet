#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1500 + 20;
int n;
char s[maxn];
int a[maxn];
int cnt[26], mx[26];
int ans[26][maxn];
int main()
{
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; i++) a[i] = s[i] - 'a';
  //memset(need, inf, sizeof(need));
  memset(ans, 0, sizeof(ans));
  for (int len = 1; len <= n; len++)
  {
    memset(cnt, 0, sizeof(cnt));
    memset(mx, 0, sizeof(mx));
    for (int i = 0; i < len; i++)
    {
      cnt[a[i]]++;
      mx[a[i]]++;
    }
    for (int i = len; i < n; i++)
    {
      --cnt[a[i - len]];
      ++cnt[a[i]];
      mx[a[i]] = max(mx[a[i]], cnt[a[i]]);
    }
    for (int i = 0; i < 26; i++)
    {
      ans[i][len - mx[i]] = max(ans[i][len - mx[i]], len);
    }
  }
  for (int i = 0; i < 26; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      ans[i][j] = min(n, max(ans[i][j - 1] + 1, ans[i][j]));
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    int can, x;
    char c[10];
    scanf("%d%s", &can, c);
    x = int(c[0] - 'a');
    printf("%d\n", ans[x][can]);
  }
}

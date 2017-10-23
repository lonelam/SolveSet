#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
map<int, int> pre;
int inline idx(char x)
{
  return x - 'a';
}
char s[maxn];
int n;
int main()
{
  scanf("%s", s);
  n = strlen(s);
  pre[0] = 0;
  int presum = 0;
  for (int i = 0; i < n-1; i++)
  {
    presum ^= (1 << (idx(s[i])));
    if (pre.find(presum) == pre.end())
    {
      pre[presum] = i + 1;
    }
    for (int j = 0; j < 26; j++)
    {
      if (pre.find(presum ^ (1 << j)) != pre.end())
      pre[presum] = min(pre[presum], pre[presum ^ (1 << j)] + 1);
    }
  }
  presum ^= (1 << idx(s[n-1]));
  if (pre.find(presum) == pre.end())
  {
    pre[presum] = n - 1;
  }
  int ans = pre[presum] + 1;
  for (int j = 0; j < 26; j++)
  {
      if (pre.find(presum ^ (1 << j)) != pre.end())
      ans = min(ans, pre[presum ^ (1 << j)] + 1);
  }
  printf("%d\n", ans);

}

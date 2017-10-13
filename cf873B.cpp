#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n;
char s[maxn];
int pre[maxn];
int main()
{
  while(cin >> n)
  {
    memset(pre, inf, sizeof(pre));
    cin >> s;
    int cur = 0;
    pre[0+ 100001] = -1;
    int ans =  0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '0') cur--;
      else if (s[i] == '1') cur++;
      if (pre[cur + 100001] != inf)
      {
        ans = max(ans, i - pre[cur + 100001]);
      }
      else
      {
        pre[cur + 100001] = i;
      }
    }
    cout << ans << endl;
  }
}

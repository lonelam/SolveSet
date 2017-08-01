#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
char n[maxn];
int k;
int main()
{
  while(cin >> k >> n)
  {
    int m = strlen(n);
    int sum = 0;
    map<char,int> cnt;
    for (int i = 0; i < m; i++)
    {
      sum += n[i] - '0';
      cnt[n[i]]++;
    }
    if (sum >= k)
    {
      cout << "0" << endl;
    }
    else
    {
      int need = k - sum;
      int ans = 0;
      for (char cur = '0';need && cur <= '9'; cur++)
      {
        int g = ('9'-cur) ;
        if ((int)g* cnt[cur] >= need)
        {
          ans += (need +g-1)/ g;
          break;
        }
        else
        {
          ans += cnt[cur];
          need -= cnt[cur] * g;
        }
      }
      cout << ans << endl;
    }
  }
}

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
char s[maxn];
int rpos[maxn];
char t[maxn];
int n, m;
int main()
{
  scanf("%s", s);
  n = strlen(s);
  m = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] != 'x')
    {
      rpos[m] = i;
      t[m++] = s[i];
    }
  }
  if (m == 0)
  {
      printf("0\n");
    return 0;
  }
  
  for (int i = 0, j = m-1; i < j; i++, j--)
  {
    if (t[i] != t[j])
    {
      printf("-1\n");
      return 0;
    }
  }

    int mid = (m / 2);
    int ans = 0, l = rpos[mid], r = rpos[mid];
    if (!(m & 1))
    {
      l = rpos[mid - 1];
    }
    while(l >= 0 && r < n)
    {
      //cout << l << " " << r << endl;
      if (s[l] == s[r])
      {
        l--;
        r++;
      }
      else if (s[l] == 'x')
      {
        l--;
        ans++;
      }
      else if (s[r] == 'x')
      {
        r++;
        ans++;
      }
    }
  ans += (l + 1 + (n - r));
  printf("%d\n", ans);
}

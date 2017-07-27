#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
char goods[100];
char s[maxn];
char t[maxn];
int main()
{
  int n;
  while(scanf("%s%s%d", goods, s, &n) != EOF)
  {
    int len = strlen(s);

    set<char> gset(goods, goods + strlen(goods));
    int starpos = -1;
    for (int i = 0; i < n; i++)
    {
      scanf("%s", t);
      int m = strlen(t);
      bool ans = true;
      for (int j = 0, k = 0; j < len && k < m; j++, k++)
      {
        if (s[j] == '?')
        {
          if (gset.find(t[k]) == gset.end())
          {
          //  cout << t[k]<<endl;
            ans =  false;
            break;
          }
        }
        else if (s[j] == '*')
        {
          starpos = j;
          break;
        }
        else if (s[j] != t[k])
        {
          ans = false;
          break;
        }
      }
      //cout << ans << endl;
      if (ans && starpos != -1)
      {
        int p = m - len + starpos + 1;
    //    cout << p << endl;
        for (int j = starpos; j < p && j < m; j++)
        {
          if (gset.find(t[j]) != gset.end())
          {
            ans = false;
            break;
          }
        }
      }
      if (starpos == -1 && len != m)
      {
        ans = false;
      }
      if (ans && m >= len - 1)
      {
        printf("YES\n");
      }
      else
      {
        printf("NO\n");
      }
    }
  }
}
/*

ab
??????*
1
aaaaaa
*/

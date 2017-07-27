#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
char goods[100];
char pat[maxn];
int main()
{
  int n;
  while(scanf("%s%s%d", goods, pat, &n) != EOF)
  {
    static char tar[maxn];
    int l = strlen(pat);
    set<char> gset(goods, goods + l);
    int starpos = l;
    for (int i = 0; i < l; i++)
    {
      if (pat[i] == '*')
      {
        starpos = i;
        break;
      }
    }
    for (int i = 0; i < n; i++)
    {
      scanf(
        "%s", tar
      );
      int m = strlen(tar);
      int left = 0, right = l;
      bool ans = true;
      for (int j = 0; j < starpos; j++)
      {
    //    cout << j << endl;
        if (pat[j] == '?')
        {
          if (gset.find(tar[j]) == gset.end())
          {
            ans = false;
            break;
          }
        }
        else if (pat[j] != tar[j])
        {
          ans = false;
          break;
        }
      }
    //  cout << ans << endl;
      int endj = m;
      for (int j = m - 1, kk = l - 1; kk > starpos && j > starpos; j--, kk--)
      {
        //cout <<"?" <<endl;
      //  cout << j << endl;
        endj = j;
        if (pat[kk] == '?')
        {
          if (gset.find(tar[j]) == gset.end())
          {
            ans = false;
            break;
          }
        }
        else if (pat[kk] != tar[j])
        {
          ans = false;
          break;
        }
      }
      //cout << ans << endl;
      //cout << endj<<endl;
      for (int j = starpos; j < endj && j < m; j++)
      {
    //    cout << j << endl;
        if (gset.find(tar[j]) != gset.end())
        {
          ans = false;
          break;
        }
      }
      //cout << ans << endl;
      if (l - 1 <= m && ans)
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

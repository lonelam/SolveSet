#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
string line[maxn];
string cmd[maxn];
char tmp[maxn];
int main()
{
  int n;
  while(~scanf("%d", &n))
  {
    set<char> out;
    bool det = false;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%s", tmp);
      cmd[i] = tmp;
      scanf("%s", tmp);
      line[i] = tmp;
    }
    char tar = line[n-1][0];

    for (int i = 0; i < n; i++)
    {
      map<char,int> cnt;
      for (char cc: line[i])
      {
        cnt[cc]++;
      }
      if (cmd[i][0] == '.')
      {
        for (char cc = 'a'; cc <= 'z'; cc++)
        {
          if (cnt[cc])
          {
            out.insert(cc);
          }
        }
        if (out.size() == 25)
        {
          det = true;
        }
      }
      else if (cmd[i][0] == '!')
      {
        if (det)
        {
          ans++;
        }
        for (char cc = 'a'; cc <= 'z'; cc++)
        {
          if (!cnt[cc])
          {
            out.insert(cc);
          }
        }
        if (out.size() == 25)
        {
          det = true;
        }
      }
      else if (cmd[i][0] == '?')
      {
        if (det && line[i][0] != tar)
        {
          ans++;
        }
        if (line[i][0] != tar)
        {
          out.insert(line[i][0]);
        }
        if (out.size() == 25)
        {
          det = true;
        }
      }
    }
    printf("%d\n", ans);
  }
}

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int cnt = 0;
        char ssave[100];
bool dfs(string &s, int rem)
{
  if (!rem)
  {
    cnt = 0;
    for (int i = 1; i < s.size(); i++)
    {
      if (s[i] != '0')
      {
        string prepart = s.substr(0, i);
        string postpart = s.substr(i, s.size() - i);
        int pre = stoi(prepart);
        int post = stoi(postpart);
        if (pre <= post)
        {
          for (int b = 1; b * b * pre <= post; b++)
          {
            if (b * b * pre == post )
            {
              if (++cnt == 2)
              {
                cout << ssave;
                cout << pre <<" "<< post << endl;
                return true;
              }
              else
              {
                sprintf(ssave, "%d %d\n", pre, post);
              }

            }
          }
        }
      }
    }
    return false;
  }
  bool ret = false;
  for (char cc = s.empty()?'1':'0'; cc <= '9'; cc++)
  {
    s.push_back(cc);
    ret |= dfs(s, rem - 1);
    s.pop_back();
  }
  return ret;
}
int main()
{
  for (int n = 2; n <= 100; n++)
  {
    string seat;
    cnt = 0;
    if (dfs(seat, n))
    {
      cout << n << "  true" << endl;
    }
    else
    {
      cout << n << "  false" << endl;
    }

  }
}

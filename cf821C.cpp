#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 100;
int n;
char cmd[100];
int main()
{
  scanf("%d", &n);
  stack<int> stk;
  //set<int> reorder;
  int ans = 0;
  int to_out = 1;
  for (int i = 0; i < 2 * n; i++)
  {
    scanf("%s", cmd);
    if (cmd[0] == 'a')
    {
      static int tmp;
      scanf("%d", &tmp);
      stk.push(tmp);
    }
    else if (cmd[0] == 'r')
    {
      if (stk.empty())
      {
        to_out++;
   //     reorder.erase(reorder.begin());
      }
      else if (stk.top() == to_out)
      {
        stk.pop();
        to_out++;
      }
      else
      {
        while(!stk.empty())
        {
          stk.pop();
        }
        ans++;
        to_out++;
      }
    }
  }
  printf("%d\n", ans);
}

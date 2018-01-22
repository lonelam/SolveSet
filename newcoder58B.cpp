#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
stack<int> stk;
vector<int> ans;
int ins[maxn];
int n;
int main()
{
  while(~scanf("%d", &n))
  {
    int up = n;
    int cur;
    while(up)
    {
      if (stk.size() && stk.top() > up)
      {
        ans.push_back(stk.top());
        stk.pop();
      }
      else if (!ins[up])
      {
        while (!ins[up])
        {
          scanf("%d", &cur);
          ins[cur] = true;
          if (cur != up)
          {
            stk.push(cur);
          }
          else
          {
            ans.push_back(up);
          }
        }
        up--;
      }
      else
      {
        up--;
      }
    }
    while(!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }
    for (int i = 0; i < n; i++)
    {
      printf("%d%c", ans[i], (i==(n-1)?'\n':' '));
    }
  }
}

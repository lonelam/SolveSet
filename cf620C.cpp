#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 100;
int a[maxn];
int dp[maxn];
int parti[maxn];
int main()
{
  int n;
  while(scanf("%d",&n)!=EOF)
  {
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", a + i);
    }
    map<int, int> pre;
    for (int i = 1; i <= n; i++)
    {
      dp[i] = dp[i - 1];
      parti[i] = -1;
      if (pre.find(a[i]) != pre.end() && dp[i] < dp[pre[a[i]] - 1] + 1)
      {
        dp[i] = dp[pre[a[i]] - 1] + 1;
        parti[i] = pre[a[i]];
      }
      pre[a[i]] = i;
    }
    vector<pair<int, int> > ans;
    if (dp[n] == 0)
    {
      printf("-1\n");
    }
    else
    {
      printf("%d\n", dp[n]);
      int cur = n;
      int tail = n;
      while(cur > 1)
      {
        if (parti[cur] != -1)
        {
          ans.push_back({ parti[cur], tail});
          cur = parti[cur];
          tail = --cur;
        }
        else
        {
          cur--;
        }

      }
      if (tail != 0)
      {
        ans.rbegin()->first = 1;
      }
      for (int i = 0; i < ans.size(); i++)
      {
        printf("%d %d\n", ans[i].first, ans[i].second);
      }
    //  cout << tail << endl;
    }
  }
}

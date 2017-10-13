#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

ll anslist[] = {0,	1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596, 2279184, 14772512, 95815104, 666090624, 4968057848, 39029188884, 314666222712, 2691008701644, 24233937684440, 227514171973736, 2207893435808352 };

bool vis[20];
vector<pair<int,int>> pre;
int ans, n;
void dfs(int cur)
{
  if (cur == n)
  {
    ans++;
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      bool flg = false;
      for (pair<int,int> p: pre)
      {
        if (abs(p.first - cur) == abs(p.second - i)) flg = true;;
      }
      if (!flg)
      {
        vis[i] = true;
        pre.push_back({cur, i});
        dfs(cur + 1);
        vis[i] = false;
        pre.pop_back();
      }
    }
  }
}
int main()
{
  int kase = 1;
  while(cin >> n)
  {
    cout << "Case " << kase++ << ": n=" << n << endl;
 //   ans = 0;
//    dfs(0);
    cout << "Total: " << anslist[n] << endl << endl;

  }
}

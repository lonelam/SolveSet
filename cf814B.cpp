#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 2000;
int n;
int p[2][maxn];
bool vis[maxn];
int main()
{
  while(cin >> n)
  {
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < n; i++)
      {
        cin >> p[k][i];
      }
    set<int> cont;
    for (int i = 0; i < n; i++)
    {
      if (p[0][i] != p[1][i])
      {
        cont.insert(i);
      }
    }
    if (cont.size() == 1)
    {
      memset(vis,0,sizeof(vis));
      for (int i = 0; i < n; i++)
      {
        if (i != *cont.begin())
        {
          vis[p[0][i]] = true;
        }
      }
      for (int i = 1; i <= n; i++)
      {
        if (!vis[i])
        {
          p[0][*cont.begin()] = i;
          break;
        }
      }
      for (int i = 0; i < n; i++)
      {
        cout << p[0][i] << ((i == n - 1) ? '\n' : ' ');
      }
    }
    else
    {
      swap(p[0][*cont.begin()], p[1][*cont.begin()]);
      int ans = 0;
      for (int k = 0; k < 2; k++)
      {
        set<int> st;
        for (int i = 0; i < n; i++)
        {
          st.insert(p[k][i]);
        }
        if (st.size() == n && *st.begin() == 1 && *st.rbegin() == n)
        {
          ans = k;
          break;
        }
      }
      for (int i = 0; i < n; i++)
      {
        cout << p[ans][i] << ((i == n - 1) ? '\n' : ' ');
      }
    }
  }
}

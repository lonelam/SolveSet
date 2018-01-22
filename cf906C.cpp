#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int m;
int raw[22];
int n;
bool check(vector<int> & v)
{
  for (int x : v)
  {
    if (x != (1 << n)-1)
    {
      return false;
    }
  }
  return true;
}
set<vector<int>> vis;
pair<int, vector<int> >  bfs()
{
//  queue< pair<int, vector<int> > *cur, *nex;queue< tuple<int, vector<int> , vector<int> > >
  queue< tuple<int, vector<int> , vector<int> > > *cur, *nex;
  cur = new queue< tuple<int, vector<int> , vector<int> > >();
  nex = new queue< tuple<int, vector<int> ,vector<int> > >();
  cur->push({0, vector<int>(raw, raw + n), vector<int>() });
  if (check(get<1>(cur->front())))
  {
    return {0, {}};
  }
  int d = 1;
  while(!cur->empty())
  {
    while(!cur->empty())
    {
      tuple<int, vector<int> ,vector<int> >  c = cur->front();
      cur->pop();
      for (int k = 0; k < n; k++)
      {
        if (get<0>(c) >> k & 1) continue;
        vector<int> t = get<1>(c);
        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < n; j++)
          {
            t[i] |= ((t[i]>> k & 1) & (t[k] >> j & 1)) << j;
          }
        }
        get<2>(c).push_back(k+1);
        if (check(t))
        {
          return {d, get<2>(c)};
        }
        else
        {
          if (vis.find(t) == vis.end())
          {
            nex->push({get<0>(c) | (1 << k), t, get<2>(c)});
            vis.insert(t);
          }
          get<2>(c).pop_back();
        }
      }
    }
    d++;
    swap(cur, nex);
  }
  return {-1, {}};
}
int main()
{
  int u,v;
  while(~scanf("%d%d", &n, &m))
  {
    memset(raw, 0, sizeof(raw));
    for (int i = 0; i < n; i++)
    {
      raw[i] |= 1 << i;
    }
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d", &u, &v);
      --u;--v;
      raw[u] |= 1 << v;
      raw[v] |= 1 << u;
    }
    auto ans = bfs();
    printf("%d\n", ans.first);
    for (int i = 0; i < ans.second.size(); i++)
    {
      printf("%d%c", ans.second[i], i==(ans.second.size() - 1)?'\n': ' ');
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
int N, M, K;
int C[maxn];
int liked[maxn];

vector<int> cost[3 + 1];
vector<ll> pcost[3 + 1];

int  main()
{
  ios::sync_with_stdio(false);
  cin >> N >> M >> K;
  for (int i = 0; i < N; ++i)
  {
    cin >> C[i];
  }
  int len;
  cin >> len;
  for (int i = 0; i < len; i++)
  {
    int v;
    cin >> v;
    liked[v - 1] |= 1;
  }
  cin >> len;
  for (int i = 0; i < len; ++i)
  {
    int v;
    cin >> v;
    liked[v - 1] |= 2;
  }
  for (int i = 0; i < N; i++)
  {
    cost[liked[i]].push_back(C[i]);
  }
  for (int i = 0; i <= 3; i++)
  {
    sort(cost[i].begin(), cost[i].end());
    pcost[i].assign(cost[i].size() + 1, 0);
    for (int j = 0; j < cost[i].size(); j++)
    {
      pcost[i][j + 1] = pcost[i][j] + cost[i][j];
    }
  }
  ll ans = 1LL << 60;
  for (int t = 0; t <= cost[3].size(); ++t)
  {
    if (t + min(cost[1].size(), cost[2].size()) < K ) continue;
    if (t + cost[0].size() + cost[1].size() + cost[2].size() < M) continue;
    int st = max(0, K - t);
    if (t + st * 2 > M) continue;
  }
}

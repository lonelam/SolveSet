#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

int L[maxn];
int R[maxn];
bool vis[maxn];
int main()
{
  int n;
  scanf("%d", &n);
  vector<pair<int,int> > ns;
  for (int i = 1; i <= n; i++)
  {
    scanf("%d%d", L + i, R + i);
  }
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      int lb = i, rb = i;
      vis[i] = true;
      while(L[lb])
      {
        lb = L[lb];
        vis[lb] = true;
      }
      while(R[rb])
      {
        rb = R[rb];
        vis[rb] = true;
      }
      ns.push_back({lb, rb});
    }
  }
  for (int i = 1; i < ns.size(); i++)
  {
    R[ns[i-1].second] = ns[i].first;
    L[ns[i].first] = ns[i-1].second;
  }
  for (int i = 1; i <= n; i++)
  {
    printf("%d %d\n", L[i], R[i]);
  }
}

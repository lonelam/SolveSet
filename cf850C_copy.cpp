#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
map<int,int> H;
int SG(int mask)
{
//  cout << mask <<endl;
  if (H.find(mask) != H.end())
  {
    return H[mask];
  }
  set<int> p;
  for (int i = 1; i <= 30; i++)
  {
    if ((mask >> i) | (mask & ((1 << (i-1)) - 1)) != mask)
    p.insert(SG((mask >> i) | (mask & ((1 << (i-1)) - 1))));
  }
  int res = 0;
  while(p.find(res) != p.end()) res++;
  return H[mask] = res;
}
int a[maxn];
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n;
  H[0] = 0;
  map<int, int> game;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 2; j * j <= a[i]; j++)
    {
      int tmp = 0;
      while(a[i] % j == 0)
      {
        tmp++;
        a[i] /= j;
      }
      if (tmp)
      {
        game[j] |= 1 << (tmp-1);
      }
    }
    if (a[i] != 1)
    {
      game[a[i]] |= 1;
    }
  }
  int xsum = 0;
  for (auto p: game)
  {
    xsum ^= SG(p.second);
  }
  if (!xsum)
  {
    cout << "Arpa" <<endl;
  }
  else
  {
    cout << "Mojtaba" <<endl;
  }
}

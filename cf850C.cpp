#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll a[maxn];
int n;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  map<int,set<int> > game;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a, a + n);
  n = unique(a, a + n) - a;
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
      if (tmp) game[j].insert(tmp);
    }
    if (a[i] != 1)
    {
      game[a[i]].insert(1);
    }
  }
  int wincnt = 0;
  for (auto p: game)
  {
    if (((p.second.size() & 1) ^ (*p.second.begin() == 2))|| (*p.second.begin() > 2))
    {
      wincnt++;
    }
  }
  if (wincnt & 1)
  {
    cout << "Mojtaba" << endl;
  }
  else
  {
    cout << "Arpa" << endl;
  }
}

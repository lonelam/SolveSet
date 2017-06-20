#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int ind[maxn];
int oud[maxn];
int main()
{
  int n, m;
  while(cin >> n >> m)
  {
    memset(ind, 0, sizeof(ind));
    int x, y;
    for (int i = 0; i < m; i++)
    {
      cin >> x >> y;
      oud[x]++;
      ind[y]++;
    }
    int cnt = 0;
    for (int i = 1; i<= n; i++)

    {
      if (oud[i] == ind[y])
      {
        cnt++;
      }
    }
    cout << cnt << endl;
    for (int i = 0; i < m; i++) cout << '0';
    cout << endl;
  }
}

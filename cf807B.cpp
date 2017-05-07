#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500;
bool vis[maxn];
int p, x, y;
void init()
{
  p -= 26;
  memset(vis,0,sizeof(vis));
  for (int i = 0; i < 475; i++)
  {
    int ti = i;
    for (int j = 0; j < 25; j++)
    {
      ti = (ti * 96 + 42) % 475;
      if (ti == p)
      {
        vis[i] = true;
        break;
      }
    }
  }
}

int main()
{
  while(cin >> p >> x >> y)
  {
    init();
    bool z = false;
    for (int i = x; i >= y; i -= 50)
    {
      if (vis[(i / 50) % 475])
      {
        z = true;
        break;
      }
    }
    if (z)
    {
      //cout << "zero"<< endl;
      cout << 0 << endl;
      continue;
    }
    int cnt = 0;
    for (int i = x; ; i+= 50)
    {
      if (vis[i / 50 % 475])
      {
        cnt = (i - x + 50) / 100;
        break;
      }
    }
    cout << cnt << endl;

  }
}

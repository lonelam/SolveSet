#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000;
bool out[maxn];
int ans[maxn] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};
int G;
int C;
int rem;
bool check(ll e)
{
  memset(out, 0, sizeof(out));
  rem = C;
  int cur = 0;
  //cout << G << "   "<< e << endl;
  for (int i = 0; i < G; i++)
  {
    const ll tmp = e % rem;
    //cout << cur << endl;
    for (int j = 0; j < tmp; j++)
    {
      cur = (cur + 1) % C;
      while(out[cur])
      {
        cur = (cur + 1) % C;
      }
    }
    if (cur < G) return false;
    out[cur] = true;
    rem--;
      while(out[cur])
      {
        cur = (cur + 1) % C;
      }

  }
  return true;
}
int main()
{

  while(cin >> G && G)
  {
    cout << ans[G] << endl;
  }
}

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1 << 20;
int ans[maxn][20];
int main()
{
  ans[0][1] = ans[1][1] = 1;
  for (int i = 2; i < 20; i++)
  {
    ld ot = 0;
    for (int s = 0; s < (1 << i); s++)
    {
      for (int j = 0; j + 1 < i; j++)
      {
        if ((s>>j)&1 && !(s>>(j+1)&1))
        {
          int t = (s >> (j+2)<<(j)) | (s % (1<<j));
          ans[s][i] = ans[t][i-2];
          cout <<s  << "  "<< t << endl;
          cin.get();
        }
        else ans[s][i] = i;
      }
      ot += (ld)ans[s][i] / (ld)(1<<i);
    }
    cout << ot << endl;
  }
}

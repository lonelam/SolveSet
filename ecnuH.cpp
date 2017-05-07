#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int grid[maxn * 2][maxn * 2];
int presumrow[maxn][maxn * 2];
int presumcol[maxn][maxn * 2];
int presumdiag[maxn][maxn * 2];
int presumrdiag[maxn][maxn * 2];
int segrowmin[maxn][maxn * 2];
int segcolmin[maxn][maxn * 2];
int segdiagmin[maxn][maxn * 2];
int segrdiagmin[maxn][maxn * 2];
int n, nn;
void build(int * seg, int * val, int L = 0, int R = nn + 1, int o = 1)
{
  if (L + 1 == R)
  {
    seg[o] = val[L];
    return;
  }
  const int mid = L + (R - L) / 2;
  build(seg, val, L, mid, o << 1);
  build(seg, val, mid, R, o << 1 | 1);
  seg[o] = min(seg[o<<1], seg[o << 1 | 1]);
 // cout << L <<"    "<< R << "   "<< o << endl;
}
int query(int * seg, int ql, int qr, int L = 0, int R = nn + 1, int o = 1)
{
  if (R <= ql || qr <= L)
  {
    return inf;
  }

//  cout << L <<"??? "<< R << "   "<< o << endl;
  if (ql <= L && R <= qr)
  {
    return seg[o];
  }

  const int mid = L + (R - L) / 2;
  int ret = inf;
  if (mid < qr) ret = query(seg, ql, qr, mid, R, o << 1 | 1);
  if (ql < mid) ret =min(ret, query(seg, ql, qr, L, mid, o << 1)) ;
  return ret;
}

int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          scanf("%d", grid[i] + j);
          grid[i + n][j] = grid[i][j + n] = grid[i + n][j + n] = grid[i][j];
        }
      }
      int ans = 0;
      nn = 2 *n;
      for (int i = 0; i < n; i++)
      {
        presumrow[i][0] = 0;
        presumcol[i][0] = 0;
        presumdiag[i][0] = 0;
        for (int j = 0; j < nn; j++)
        {
          presumrow[i][j + 1] = presumrow[i][j] + grid[i + n][j];
          presumcol[i][j + 1] = presumcol[i][j] + grid[j][i + n];
          presumdiag[i][j + 1] = presumdiag[i][j] + grid[j][(i + j) % nn];
          presumrdiag[i][j + 1] = presumrdiag[i][j] + grid[j][(i + nn - j) % (nn)];
        }
        build(segrowmin[i], presumrow[i]);
        build(segcolmin[i], presumcol[i]);
        build(segdiagmin[i], presumdiag[i]);
        build(segrdiagmin[i], presumrdiag[i]);
        for (int j = 0; j < n; j++)
        {
          ans = max(ans, presumrow[i][j + n] - query(segrowmin[i], j, j + n));
          ans = max(ans, presumcol[i][j + n] - query(segcolmin[i], j, j + n));
          ans = max(ans, presumdiag[i][j + n] - query(segdiagmin[i], j, j + n));
          ans = max(ans, presumrdiag[i][j + n] - query(segrdiagmin[i], j, j + n));
        //  cout <<"******"<< ans <<"   "<< presumrow[i][j + n + 1] <<"   "<<query(segrowmin[i], j, j + n) << endl;
        }
      }
      printf("%d\n", ans);
    }
  }
}
/*


1
4
8  6  6  1
-3 4  0  5
4  2  1  9
1 -9  9 -2


*/

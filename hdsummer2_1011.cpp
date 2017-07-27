#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 5;
double x[maxn], y[maxn];
int n;
map<pair<double, double>, bool> vis;
int main()
{
  ios::sync_with_stdio(false), cin.tie(0);
  while(cin >> n)
  {
    vis.clear();
    for (int i = 0; i < n; i++)
    {
      cin >> x[i] >> y[i];
      vis[{x[i], y[i]}] = true;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        const double px = (x[j] - x[i]) / 2.0, py = (y[j] - y[i]) / 2.0;
        //cout << px << " "<<py << endl;
        const pair<double, double> angle1 = {x[i] + px - py, y[i] + px + py} , angle2 = {x[i] + px + py, y[i] - px + py};
        if (vis[angle1] && vis[angle2])
        {
        //  cout << x[i] << " "<< y[i]  << ", "<< x[j] << " "<<y[j] <<" ***"<< px <<  " "<< py << endl;
          ans++;
        }
      }
    }
    printf("%d\n", ans / 2);
  }
}
/*

4
0 1
0 -1
1 0
-1 0

*/

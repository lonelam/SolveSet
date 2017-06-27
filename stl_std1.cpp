#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n;
int m;
int main()
{
  //freopen("9.in", "r", stdin);
  //freopen("9.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
    map<pair<int, int>, vector<int> > a;
    cin >> n;
    int id, px, py;
    for (int i = 0; i < n; i++)
    {
      cin >> id >>  px >> py;
      a[{px,py}].push_back(id);
    }
    for (auto & x : a)
    {
      sort(x.second.begin(), x.second.end());
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
      cin >> px >> py >> id ;
      cout << a[{px,py}][id - 1] << endl;
    }
}
/*
5
1 0 0
2 0 0
3 0 0
4 1 1
5 1 1
3
0 0 2
0 0 1
1 1 1
*/

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string disc[maxn];
int main()
{
  int n, q;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> disc[i];
  }
  sort(disc, disc + n);
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    string tmp;
    cin >> tmp;
    int pos = lower_bound(disc, disc + n, tmp) - disc + 1;
    int acc = 0;
    for (auto x:tmp)
    {
      acc += x - 'A' + 1;
    }
    cout << acc * pos << endl;
  }
}

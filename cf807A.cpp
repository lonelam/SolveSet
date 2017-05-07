#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int a[maxn], b[maxn];
int main()
{
  int n;
  cin >> n;
  bool rated = false, unrated = false;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i];
    if (a[i] != b[i])
    {
      rated = true;
    }
  }
  if (!rated)
  {
    for (int i = 1; i < n; i++)
    {
      if (a[i] > a[i - 1])
      {
        unrated = true;
      }
    }
  }
  if (rated)
  {
    cout <<"rated\n";
  }
  else if (unrated)
  {
    cout <<"unrated\n";
  }
  else
  {
    cout << "maybe"<< endl;
  }
}

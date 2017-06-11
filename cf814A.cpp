#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

  int a[maxn];
  int b[maxn];
  int n, k;
int main()
{
  while(cin >> n >> k)
  {
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (!a[i]) cnt++;
    }
    for (int i = 0; i < k; i++)
    {
      cin >> b[i];
    }
    sort(b, b + k);
    if (cnt != k)
    {
      cout << "No";
      continue;
    }
    int p = k - 1;
    for (int i = 0; i < n; i++)
    {
      if (!a[i])
      {
        a[i] = b[p--];
      }
    }
    bool ans = false;
    for (int i = 1; i < n; i++)
    {
      if (a[i] < a[i - 1])
      {
        ans = true;
        break;
      }
    }
    if (ans)
    {
      cout << "Yes\n";
    }
    else
    {
      cout << "No\n";
    }
  }
}

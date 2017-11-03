#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int n, k;
int a[maxn];
int rem;
bool ok = true;
void merge(int L = 0, int R = n, int from = 0, int to = n)
{
  if (rem <= 0 || L + 1 == R)
  {
    for (int i = L, j = from; i < R; i++, j++)
    {
      a[i] = j;
    }
    return;
  }
  const int mid = (L + R) / 2;
  const int M = (from + to + 1) / 2;
  rem -= 2;
  merge(L, mid, M, to);
  merge(mid, R, from, M);
}
int main()
{
  while(cin >> n >> k)
  {
    rem = k;
    rem--;
    merge();
    if (rem)
    {
      cout << -1 << endl;
    }
    else
    {
      for (int i = 0; i < n-1; i++)
      {
        cout << a[i]+1 << " ";
      }
      cout << a[n-1]+1 << endl;
    }
  }
}

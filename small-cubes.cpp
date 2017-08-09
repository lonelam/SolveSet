#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
ll n, m, k;
ll p, q;
ll a[maxn], b[maxn], A[maxn],B[maxn];
int main()
{
  cin >> n >> m >> k;
  cin >> p >> q;
  ll ans = p;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i] >> A[i] >> B[i];
    ans += (A[i] - a[i] + 1) * (B[i] - b[i] + 1) * q;
  }
  for (ll i = 2; i < n; i++)
  {
    if (p - (i*i*i - (i-1)*(i-1)*(i-1)) * q > 0)
    {
      ans += p - (i*i*i - (i-1)*(i-1)*(i-1)) * q ;
    }
  }
  cout << ans << endl;
}

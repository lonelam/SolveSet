#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const ld eps = 1e-9;
ll cnt[maxn];
ll n;
void init()
{
  memset(cnt,0,sizeof(cnt));
  for (int i = 2; i <= n; i++)
  {
    ll a = floor(pow((ld)n, 1.0 /  (ld)i) + eps)-1;
    cout << a<<" ";
    for (int j = i + i; j<= n; j += i)
    {
      cnt[j]+=a;
      cout << j <<" ";
    }
    cout << endl;
  }
  for (int i = 2; i <=n; i++)
  {
    cnt[i] += cnt[i-1];
  }
}
int main()
{
  while(cin >> n)
  {
    init();
    cout << (n-1) * (n-1) - cnt[n] << endl;
  }
}

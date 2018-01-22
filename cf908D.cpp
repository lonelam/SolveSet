#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
const ll moder = 1e9 + 7;
ll k, pa, pb;
ll invpa, invpb, invab;
ll mem[maxn][maxn];
ll dp(int i, int j)
{
  if (i >= j)
  {
    return (pa + pb * i) % moder * invpb % moder;
  }
  if (mem[i][j] != -1) return mem[i][j];
  if (i == 0)
  {
    return mem[i][j] = dp(1, j);
  }
  return mem[i][j] = ((pa * dp(i+1, j) % moder + pb * (dp(i, j-i) + i) % moder) % moder * invab % moder )% moder;
}
ll p_m(ll base, ll index)
{
  ll ret = 1;
  while(index )
  {
    if (index & 1)
      ret = (ret * base) % moder;
    index >>= 1;
    base = (base * base) % moder;
  }
  return ret;
}
int main()
{
  while(cin >> k >> pa >> pb)
  {
    memset(mem, -1, sizeof(mem));
    invpa = p_m(pa, moder -2);
    invpb = p_m(pb, moder -2);
    invab = p_m(pa + pb, moder -2);
    cout << dp(0, k) << endl;
  }
}

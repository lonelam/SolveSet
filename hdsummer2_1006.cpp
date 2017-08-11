#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const ll moder = 1e9 + 7;
struct mat
{
  ll a[3][3];
  int sz;
  mat(int _sz):sz(_sz) { memset(a, 0, sizeof(a));}
  void init()
  {
    for (int i = 0; i < sz; i++)
    {
      a[i][i] = 1;
    }
  }
};
mat operator * (mat & lhs, mat & rhs)
{
  assert(lhs.sz == rhs.sz);
  mat ret(lhs.sz);
  for (int k = 0; k < lhs.sz; k++)
  {
    for (int i = 0; i < lhs.sz; i++)
    {
      for (int j = 0; j < lhs.sz; j++)
      {
        ret.a[i][j] += lhs.a[i][k] * rhs.a[k][j];
        ret.a[i][j] %= moder;
      }
    }
  }
  return ret;
}
mat p_m(mat base, ll index)
{
  mat ans(base.sz);
  ans.init();
  while(index)
  {
    if (index & 1)
    {
      ans = ans * base;
    }
    index >>= 1;
    base = base * base;
  }
  return ans;
}
ll solve(ll N, ll M)
{
  mat B(3);
  B.a[0][0] = B.a[1][0] = B.a[0][2] = 1;
  B.a[0][1] = 2;
  B.a[2][2] = 1;
  mat tmp1 = p_m(B, N - 2);
  mat tmp2 = p_m(B, N - 1);
  ll x1 = tmp1.a[0][1], y1 = tmp1.a[0][0], x2 = tmp2.a[0][1], y2 = tmp2.a[0][0];
  mat C(3);
  C.a[0][0] = tmp2.a[0][0];
  C.a[0][1] = tmp2.a[0][1] + tmp2.a[0][2]- 1;
//  C.a[0][2] = tmp2.a[0][2];
  C.a[1][0] = tmp1.a[0][0];
  C.a[1][1] = tmp1.a[0][1] + tmp1.a[0][2];
//  C.a[1][2] = tmp1.a[0][2];
  C.a[2][1] = 1;
  mat D = p_m(C, M - 2);
  ll G_2_1 = (tmp1.a[0][0] * 2LL + tmp1.a[0][1] * 1LL + tmp1.a[0][2] * 1LL) % moder;
  ll G_2_2 = (tmp2.a[0][0] * 2LL + tmp2.a[0][1] * 1LL + tmp2.a[0][2] * 1LL + moder - 1) % moder;
  ll G_1_1 = 1;
  return (D.a[0][0] * G_2_2 % moder + D.a[0][1] * G_2_1 % moder + D.a[0][2] * G_1_1) % moder;
}
int main()
{
  ll N, M;
  int T;
  while(cin >> T)
  {
    while(T--)
    {
      cin >> N >> M;
      cout << solve(N, M) << endl;
    }
  }

}

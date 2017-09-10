
const ll moder = 998244353;
typedef vector<int> VI;
ll p_m(ll base, ll index)
{
  ll ret = 1;
  while(index)
  {
    if (index & 1) ret = ret * base % moder;
    base = base * base % moder;
    index >>= 1;
  }
  return ret;
}
int n;
namespace linear_seq
{
  const int N = 10000 + 10;
  ll res[N], base[N], _c[N], _md[N];
  vector<int> Md;
  void mul(ll *a, ll *b, int k)
  {
    for (int i = 0; i < k+k; i++) _c[i] = 0;
    for (int i = 0; i < k; i++)
      if (a[i])
        for (int j = 0; j < k; j++)
          _c[i+j] = (_c[i+j] + a[i] * b[j]) % moder;
    for (int i = k + k - 1; i >= k; i--)
      if (_c[i])
        for (int j = 0; j < Md.size(); j++)
          _c[i-k+Md[j]] = (_c[i-k+Md[j]] - _c[i] * _md[Md[j]]) % moder;
    for (int i = 0; i < k; i++) a[i] = _c[i];
  }
  int solve(ll n, VI a, VI b)
  {
    ll ans = 0, pnt = 0;
    int k = a.size();
    for (int i = 0; i < k; i++) _md[k-1-i] = -a[i];
    _md[k] = 1;
    Md.clear();
    for (int i = 0; i < k; i++) if (_md[i] != 0) Md.push_back(i);
    for (int i = 0; i < k; i++) res[i] = base[i] = 0;
    res[0] = 1;
    while((1LL << pnt) <= n) pnt++;
    for (int p = pnt; p >= 0; p--)
    {
      mul(res,res,k);
      if ((n>>p) & 1)
      {
        for (int i = k - 1; i >= 0; i--) res[i+1] = res[i];
        res[0] = 0;
        for (int j = 0; j < Md.size(); j++) res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % moder;
      }
    }
    for (int i = 0; i < k; i++) ans = (ans + res[i] * b[i]) % moder;
    if (ans < 0) ans += moder;
    return ans;
  }
  VI BM(VI s)
  {
    VI C(1,1), B(1,1);
    int L = 0,m = 1, b = 1;
    for (int n = 0; n < s.size(); n++)
    {
      ll d = 0;
      for (int i = 0; i <= L; i++) d = (d + (ll)C[i]*s[n-i])%moder;
      if (d == 0)++m;
      else if (2 * L <= n)
      {
        VI T = C;
        ll c = moder - d * p_m(b, moder - 2) % moder;
        while(C.size() < B.size() + m) C.push_back(0);
        for (int i = 0; i < B.size(); i++) C[i+m] = (C[i+m] + c * B[i]) % moder;
        L = n + 1 - L; B = T; b = d; m = 1;
      }
      else
      {
        ll c = moder - d * p_m(b, moder - 2) % moder;
        while(C.size() < B.size() + m) C.push_back(0);
        for (int i = 0; i < B.size(); i++) C[i+m] = (C[i+m] + c * B[i]) % moder;
        ++m;
      }
    }
    return C;
  }
  int gao(VI a, ll n)
  {
    VI c = BM(a);
    c.erase(c.begin());
    for (int i = 0; i < c.size(); i++) c[i] = (moder - c[i]) % moder;
    return solve(n,c,VI(a.begin(), a.begin() + c.size()));
  }
}
int main() {
        while(~scanf("%d",&n))
        printf("%d\n",linear_seq::gao(VI{1, 4, 12, 33, 88, 232, 609},n));
}

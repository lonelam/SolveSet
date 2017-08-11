#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
const ll moder = 1e9 + 7;

const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
inline void rnext()
{
    if(++ps == pe)
        pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}

template <class T>
inline bool in(T &ans)
{
    ans = 0;
    T f = 1;
    if(ps == pe) return false;//EOF
    do{
        rnext();
        if('-' == *ps) f = -1;
    }while(!isdigit(*ps) && ps != pe);
    if(ps == pe) return false;//EOF
    do
    {
        ans = (ans<<1)+(ans<<3)+*ps-48;
        rnext();
    }while(isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}


const int  MAXOUT=10000;
char bufout[MAXOUT], outtmp[50],*pout = bufout, *pend = bufout+MAXOUT;
inline void write()
{
    fwrite(bufout,sizeof(char),pout-bufout,stdout);
    pout = bufout;
}
inline void out_char(char c){ *(pout++) = c;if(pout == pend) write();}
inline void out_str(char *s)
{
    while(*s)
    {
        *(pout++) = *(s++);
        if(pout == pend) write();
    }
}
template <class T>
inline void out_int(T x) {
    if(!x)
    {
        out_char('0');
        return;
    }
    if(x < 0) x = -x,out_char('-');
    int len = 0;
    while(x)
    {
        outtmp[len++] = x%10+48;
        x /= 10;
    }
    outtmp[len] = 0;
    for(int i = 0, j = len-1; i < j; i++,j--) swap(outtmp[i],outtmp[j]);
    out_str(outtmp);
}
ll ans;
//map<pair<int, int>, int> pos;
map<int, int> pos[maxn];
int inv_fact[maxn];
int fact[maxn];
int n;
ll pow_m(ll base, ll index)
{
  ll ret = 1;
  while(index)
  {
    if (index & 1)
    {
      ret *= base;
      ret %= moder;
    }
    index >>= 1;
    base *= base;
    base %= moder;
  }
  return ret;
}
void getinv()
{
  fact[1] = fact[0] = 1;
  for (ll i = 2; i <= n; i++)
  {
    fact[i] = (ll)fact[i-1] * (ll)i % moder;
  }
  inv_fact[n] = pow_m(fact[n], moder - 2);
  for (int i = n - 1; i >= 0; i--)
  {
    inv_fact[i] = (ll)inv_fact[i + 1] * (ll)(i + 1) % moder;
  }
}
ll comb(int n, int m)
{
  return (ll)fact[n] * (ll)inv_fact[n - m] % moder * (ll)inv_fact[m] % moder;
}
void quickpartition(int L = 1, int R = n)
{
  if (L > R)
  {
    return;
  }
  if (pos[L].find(R) == pos[L].end())
  {
    ans = 0;
    return;
  }
  const int mid = pos[L][R];
  if (mid > R || mid < L)
  {
    ans = 0;
    return;
  }
  ans *= comb(R - L, mid - L);
  ans %= moder;
  quickpartition(L, mid - 1);
  quickpartition(mid + 1, R);
  return;
}
void init()
{
  ans = 1;
  // pos.clear();
  getinv();
  for (int i = 0; i <= n; i++)
  {
    pos[i].clear();
  }
}
int l[maxn], r[maxn];
int main()
{
  // freopen("/home/lais/Downloads/多校联合训练第一场标程及数据/数据/1012.in", "r", stdin);
  // freopen("/home/lais/Downloads/多校联合训练第一场标程及数据/数据/me.out", "w", stdout);
  int kase = 1;
  // while(scanf("%d", &n) != EOF)
  while(in(n))
  {
    init();
    for (int i = 1; i <= n; i++)
    {
      in(l[i]);
      // scanf("%d", l + i);
    }
    for (int i = 1; i <= n; i++)
    {
      in(r[i]);
      // scanf("%d", r + i);
    }
    // if (kase == 977) out_int(n);
    for (int i = 1; i <= n; i++)
    {
      if (pos[l[i]].find(r[i]) != pos[l[i]].end()) ans = 0;
      pos[l[i]][r[i]] = i;
      // if (kase == 977)
      // {
      //   out_int(i);
      //   out_str("  ");
      //   out_int(l[i]);
      //   out_str("  ");
      //   out_int(r[i]);
      //   out_str("\n");
      // }
    }
    quickpartition();
    out_str("Case #");
    out_int(kase++);
    out_str(": ");
    out_int(ans);
    out_str("\n");
    // printf("Case #%d: %lld\n",kase++,  ans);
  }
  write();
}

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const ll moder = 1e9 + 7;

struct mat
{
  ll a[4][4];
  mat()
  {
    memset(a,0,sizeof(a));
  }
  mat operator*(const mat & rhs) const
  {
    mat ret;
    {
      for (int i = 0; i < 4; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          for (int k = 0; k < 4; k++)
          {
            ret.a[i][j] += (a[i][k] * rhs.a[k][j]);
          }
        }
      }
    }
    return ret;
  }
};
mat p_m(mat base, ll index)
{
  mat ret;
  ret.a[0][0] = ret.a[1][1] = ret.a[2][2] = ret.a[3][3] = 1;
  while(index)
  {
    if (index & 1)
    {
      ret = ret * base;
    }
    base = base * base;
    index >>= 1;
  }
  return ret;
}
ll p_m(ll base, ll index)
{
  ll ret = 1;
  while(index)
  {
    if (index & 1)
    {
      ret = ret * base ;
    }
    base = base * base;
    index >>= 1;
  }
  return ret;
}
typedef long long LL;

LL quick_mod(LL a,LL b,LL m)
{
    LL ans=1;
    a%=m;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%m;
            b--;
        }
        b>>=1;
        a=a*a%m;
    }
    return ans;
}

struct T
{
    LL p,d;
};

LL w;

//二次域乘法
T multi_er(T a,T b,LL m)
{
    T ans;
    ans.p=(a.p*b.p%m+a.d*b.d%m*w%m)%m;
    ans.d=(a.p*b.d%m+a.d*b.p%m)%m;
    return ans;
}

//二次域上快速幂
T power(T a,LL b,LL m)
{
    T ans;
    ans.p=1;
    ans.d=0;
    while(b)
    {
        if(b&1)
        {
            ans=multi_er(ans,a,m);
            b--;
        }
        b>>=1;
        a=multi_er(a,a,m);
    }
    return ans;
}

//求勒让德符号
LL Legendre(LL a,LL p)
{
    return quick_mod(a,(p-1)>>1,p);
}

LL mod(LL a,LL m)
{
    a%=m;
    if(a<0) a+=m;
    return a;
}

LL Solve(LL n,LL p)
{
    if(p==2) return 1;
    if (Legendre(n,p)+1==p)
        return -1;
    LL a=-1,t;
    while(true)
    {
        a=rand()%p;
        t=a*a-n;
        w=mod(t,p);
        if(Legendre(w,p)+1==p) break;
    }
    T tmp;
    tmp.p=a;
    tmp.d=1;
    T ans=power(tmp,(p+1)>>1,p);
    return ans.p;
}
int main()
{
  mat G;
  G.a[0][0] = 4;
  G.a[0][1] = 17;
  G.a[0][2] =  - 12;
  G.a[0][3] =  - 1;
  G.a[1][0] = G.a[2][1] = G.a[3][3] = 1;
  ll H0[4] =  {6,3,2,16};
  int t;
  // ll n;
  while(scanf("%d", &t) != EOF)
  {
    // while(t--)
    cout.precision(5);
    cout.setf(ios::fixed);
    for (ll n = 2; n <= t; n++)
    {
      // scanf("%lld", &n);
      mat D = p_m(G, n - 1);
      ll H[4] = {0,0,0,0};
      for (int i = 0; i < 4; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          H[i] = H[i] + D.a[i][j] * H0[j] ;
        }
      }
      // cout << H[0] << endl;
      ll bn = ((3LL * H[0]))* H[1] + (9LL * H[0]) * H[2]  + (9LL * H[1]) * H[1] + (27LL * H[1] )* H[2]
       + ( - 18LL) * H[0] + ( - 81) * H[2] + (- 126LL) * H[1] + 192LL;
      // cout << bn << endl;
      ll an = bn + p_m(4LL, n);
      cout << sqrt((ld)an) << endl;
      // printf("%lld\n", Solve(an, moder));
    }
  }
}

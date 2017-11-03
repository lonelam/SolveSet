#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 10;


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
int n, k;
int v[maxn];
int st[maxn];
bool check(int m)
{
  //set<int> st({-1});
  st[0]=-1;
  int top = 1;
  for (int i = 0; i < n; i++)
  {
    int lb = lower_bound(v, v + n, v[i] - m) - v - 1;
    int rb = i - k;
    if (lb > rb) continue;
    if (lower_bound(st, st + top, lb) != upper_bound(st, st + top, rb))
    {
      st[top++] = (i);
    }
  }
  if (st[top-1] == (n-1)) return true;
  return false;
}
int main()
{
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  in(n);
  in(k);
  //scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
  {
    in(v[i]);
  //  scanf("%d", v + i);
  }
  sort(v, v + n);
  int L = -1, R = 1e9 - 1;
  while(L + 1 < R)
  {
    const int mid = R - (R - L) / 2;
    if (check(mid))
    {
      R = mid;
    }
    else
    {
      L = mid;
    }
  }
  out_int(R);
  write();
//  printf("%d\n", R);
}

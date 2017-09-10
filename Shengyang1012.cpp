#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 1000;
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
int n;
int a[maxn * 2];
int b[maxn * 2];
int ans;
int card;
int main()
{
  // freopen("data.in", "r", stdin);
  while(in(n))
  {
    for (int i = 0; i < n; i++)
    {
      in(a[i]);
      a[i+n] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
      in(b[i]);
      b[i+n] = b[i];
    }
    int L = 0, R = 0;
    ans = 0;
    card = 0;
    int palsum = 0, cardsum = 0;
    while(L < n)
    {
      // printf("%d", L);
      while(palsum <= cardsum && R - L < n)
      {
        cardsum += a[R];
        palsum += b[R];
        if (cardsum > card)
        {
          ans = L;
          card = cardsum;
        }
        R++;
      }
      palsum -= b[L];
      cardsum -= a[L];
      L++;
    }
    // printf("%d\n", card);
    printf("%d\n", ans);
  }
}

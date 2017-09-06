#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
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
inline void out_str(const char *s)
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
const int maxn = 100000 + 100;
vector<int> G[maxn];
bool vis[maxn];
int n, m;
int cnt;
void dfs(int u, int fa)
{
  for (int v: G[u])
  {
    if (v != fa)
    {
      dfs(v, u);
      if (!vis[v] && !vis[u])
      {
        vis[u] = vis[v] = true;
        cnt++;
      }
    }
  }
}
int main()
{
  int T;
  while(in(T))
  {
    while(T--)
    {
      in(n);
      in(m);
      cnt = 0;
      for (int i = 1; i <= n; i++)
      {
        G[i].clear();
      }
      for (int i = 2; i <= n; i++)
      {
        static int u;
        in(u);
        G[u].push_back(i);
        G[i].push_back(u);
      }
      memset(vis, 0, sizeof(vis));
      dfs(1, 1);
      int ans = -1;
      if (cnt * 2 >= m)
      {
        ans = (m+1) / 2;
      }
      else
      {
        ans = cnt + (m - cnt * 2);
      }
      out_int(ans);
      out_str("\n");
    }
  }
  write();
}

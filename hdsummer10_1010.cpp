#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;

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

struct node
{
  int s, e;
}ns[maxn];

vector<int> bseg[maxn * 2];
vector<int> eseg[maxn * 2];

struct machine
{
  int timestart, timeend, id;
  bool operator<(const machine & rhs) const
  {
    return timeend > rhs.timeend;
  }
}ms[maxn];
int cnt;
bool vis[maxn];
int n;
vector<int> disc;
int mac[maxn];
int main()
{
  // freopen("data.in", "r", stdin);
  int T;
  while(in(T))
  {
    while(T--)
    {
      in(n);
      disc.clear();
      for (int i = 0; i < n; i++)
      {
        in(ns[i].s);
        in(ns[i].e);
        disc.push_back(ns[i].s);
        disc.push_back(ns[i].e);
      }
      sort(disc.begin(), disc.end());
      disc.erase(unique(disc.begin(), disc.end()), disc.end());
      for (int i = 0; i < disc.size(); i++)
      {
        bseg[i].clear();
        eseg[i].clear();
      }
      for (int i = 0; i < n; i++)
      {
        ns[i].s = lower_bound(disc.begin(), disc.end(), ns[i].s) - disc.begin();
        bseg[ns[i].s].push_back(i);
        ns[i].e = lower_bound(disc.begin(), disc.end(), ns[i].e) - disc.begin();
        eseg[ns[i].e].push_back(i);
      }
      memset(vis, 0, sizeof(vis));
      cnt = 0;
      memset(mac, -1, sizeof(mac));
      multiset<machine> rem;
      for (int i = 0; i < disc.size(); i++)
      {
        for (int j: eseg[i])
        {
          rem.insert(ms[mac[j]]);
        }
        for (int j: bseg[i])
        {
          if (rem.empty())
          {
            mac[j] = cnt;
            ms[cnt] = {ns[j].s, ns[j].e, cnt};
            cnt++;
          }
          else
          {
            mac[j] = rem.begin()->id;
            ms[mac[j]].timeend = ns[j].e;
            rem.erase(rem.begin());
          }
        }
      }
      ll ans = 0;
      for (int i = 0; i < cnt; i++)
      {
        ans += disc[ms[i].timeend] - disc[ms[i].timestart];
      }
      printf("%d %lld\n", cnt, ans);
    }
  }
}

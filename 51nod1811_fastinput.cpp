
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
  int L, R;
};
bool operator<(const node & lhs,const node & rhs)
{
  return lhs.L < rhs.L;
}
int n;
ll acc, ans;
vector<int> G[maxn];
int tot = 0;
void init()
{
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  ans = (ll)n * (ll)(n+1) * (ll)(n-1) / 2LL;
  tot = 0;
}
void add(int u, int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}
set<node> pool[maxn];
set<node> * dfs(int cur, int parent)
{
  vector<set<node>*> cheese;
  int main_id = 0;
  int main_size = 0;
  for (int v: G[cur])
  {
    if (v != parent)
    {
      cheese.push_back(dfs(v, cur));
      if ((*cheese.rbegin())->size() > main_size)
      {
        main_size = (*cheese.rbegin())->size();
        main_id = cheese.size() - 1;
      }
    }
  }
  pool[tot] = {{cur, cur}};
  cheese.push_back(&pool[tot++]);
  for (int i = 0; i < cheese.size(); i++)
  {
    if (i != main_id)
    {
      for (node x: *cheese[i])
      {
        auto post = cheese[main_id]->upper_bound(x);
        auto pre = post;
        node pretmp, posttmp;
        bool post_tag = false, pre_tag = false;
        if (post != cheese[main_id]->end() && post->L == x.R + 1)
        {
          x.R = post->R;
          posttmp = *post;
          post_tag = true;
        }
        if (pre != cheese[main_id]->begin())
        {
          pre--;
          if (pre->R + 1== x.L)
          {
            x.L = pre->L;
            pretmp = *pre;
            pre_tag = true;
          }
        }
        if (post_tag)
        {
          cheese[main_id]->erase(posttmp);
        }
        if (pre_tag)
        {
          cheese[main_id]->erase(pretmp);
        }
        cheese[main_id]->insert(x);
      }
    }
  }
  if (cur == parent)
  {
    return cheese[main_id];
  }
  int pre = 1;
  for (node x: *cheese[main_id])
  {
    ans -= (ll)(x.L - pre + 1) * (ll)(x.L - pre) / 2LL;
    ans -= (ll)(x.R - x.L + 2) * (ll)(x.R - x.L + 1) / 2LL;
    pre = x.R + 1;
  }
  ans -= (ll) (n - pre + 2) * (ll) (n - pre + 1) / 2LL;
  return cheese[main_id];
}
int main()
{
  int x, y;
  while(in(n))
  {
    init();
    for (int i = 1; i < n; i++)
    {
      in(x);
      in(y);
      //scanf("%d%d", &x, &y);
      add(x, y);
    }
    dfs((n - 1) / 2 + 1, (n - 1) / 2 + 1);
    out_int(ans);
//    write();
//    printf("%lld\n", ans);
  }
  write();
}

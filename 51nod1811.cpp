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
int weight[maxn];
int center[maxn];
vector<int> G[maxn];
int tot = 0;
void find_center(int u, int p)
{
  weight[u] = 1;
  int tmp = -1;
  for (int v: G[u])
  {
    if (v == p) continue;
    find_center(v, u);
    weight[u] += weight[v];
    tmp = max(tmp, weight[v]);
  }
  center[u] = max(tmp, n - weight[u]);
}
int get_center()
{
  find_center(1, 1);
  int ret = 1;
  for (int i = 1; i <= n; i++)
  {
    if (center[i] > center[ret])
    {
      ret = i;
    }
  }
  return ret;
}
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
map<int, int> cntpool[maxn];
int dfs(int cur, int parent)
{
  vector<int> cheese;
  int main_id = 0;
  int main_size = 0;
  for (int v: G[cur])
  {
    if (v != parent)
    {
      cheese.push_back(dfs(v, cur));
      if (pool[*cheese.rbegin()].size() > main_size)
      {
        main_size = pool[*cheese.rbegin()].size();
        main_id = cheese.size() - 1;
      }
    }
  }
  pool[tot] = {{cur, cur}};
  cntpool[tot] = {{1, 1}};
  if (cur - 1) cntpool[tot][cur - 1]++;
  if (n - cur) cntpool[tot][n - cur]++;
  cheese.push_back(tot++);
  set<node> & m_tree = pool[cheese[main_id]];
  map<int, int> & cntm_tree = cntpool[cheese[main_id]];
  for (int i = 0; i < cheese.size(); i++)
  {
    if (i != main_id)
    {
      for (node x: pool[cheese[i]])
      {
        auto post = m_tree.upper_bound(x);
        auto pre = post;
        int lleft = 0, rr = n + 1;
        node pretmp, posttmp;
        bool post_tag = false, pre_tag = false;
        if (post != m_tree.end())
        {
          posttmp = *post;
          rr = posttmp.L;
          if (rr == x.R + 1)
          {
            x.R = posttmp.R;
            post_tag = true;
          }
        }
        if (pre != m_tree.begin())
        {
          pre--;
          pretmp = *pre;
          lleft = pretmp.R;
          if (lleft + 1== x.L)
          {
            x.L = pretmp.L;
            pre_tag = true;
          }
        }
        if (!(--cntm_tree[rr - lleft - 1]))
        {
            cntm_tree.erase(rr - lleft - 1);
        }
        if (post_tag)
        {
          m_tree.erase(posttmp);
          if (!(--cntm_tree[posttmp.R - posttmp.L + 1]))
          {
            cntm_tree.erase(posttmp.R - posttmp.L + 1);
          }
        }
        else
        {
          cntm_tree[rr - x.R - 1]++;
        }

        if (pre_tag)
        {
          m_tree.erase(pretmp);
          if (!(--cntm_tree[pretmp.R - pretmp.L + 1]))
          {
            cntm_tree.erase(pretmp.R - pretmp.L + 1);
          }
        }
        else
        {
          cntm_tree[x.L - lleft - 1]++;
        }

        m_tree.insert(x);
        cntm_tree[x.R - x.L + 1]++;
      }
    }
  }
  if (cur == parent)
  {
    return cheese[main_id];
  }
  for (const auto & p: cntm_tree)
  {
    ans -= (ll)(p.first + 1) * (ll)(p.first) / 2LL * (ll)p.second;
  }
  /*
  int pre = 1;
  for (const node & x: m_tree)
  {
    ans -= (ll)(x.L - pre + 1) * (ll)(x.L - pre) / 2LL;
    ans -= (ll)(x.R - x.L + 2) * (ll)(x.R - x.L + 1) / 2LL;
    pre = x.R + 1;
  }
  ans -= (ll) (n - pre + 2) * (ll) (n - pre + 1) / 2LL;
  */
  return cheese[main_id];
}
int main()
{
  //srand(time(0));
  int x, y;
  // while(scanf("%d", &n) != EOF)
  while(in(n))
  {
    init();
    for (int i = 1; i < n; i++)
    {
      in(x);in(y);
      // scanf("%d%d", &x, &y);
      add(x, y);
    }
    dfs(1,1);

    //int ct = rand() % n + 1;

    //dfs(ct, ct);
    //dfs((n - 1) / 3 + 1, (n - 1) / 3 + 1);
    printf("%lld\n", ans);
  }
}

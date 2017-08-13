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



const int maxn = 100000 + 100;
int fa[maxn * 2], rnk[maxn * 2];
int fnd(int x)
{
  if (fa[x] == x) return x;
  return fa[x] = fnd(fa[x]);
}
void join(int a, int b)
{
  a = fnd(a);
  b = fnd(b);
  if (a == b) return;
  if (rnk[a] == rnk[b])
  {
    rnk[a]++;
    fa[b] =  a;
  }
  else if (rnk[a] > rnk[b])
  {
    fa[b] = a;
  }
  else
  {
    fa[a] = b;
  }
}

void init()
{
  for (int i = 0; i < maxn; i++)
  {
    fa[i] = i;
    rnk[i] = 1;
  }
}

int main()
{
  freopen("data.in", "r", stdin);
  int L;
  vector<int> ans;
  init();
  // scanf("%d", &L);
  in(L);
  vector<int> rev;
  set<pair<int,int> > neq;
  int x, y, e;
  int cnt = 0;
  for (int i = 0; i < L; i++)
  {
    // scanf("%d%d%d", &x, &y, &e);
    in(x);in(y);in(e);
    cnt++;
    if (e)
    {
      if (neq.find({x, y}) != neq.end())
      {
        ans.push_back(cnt);
        cnt = 0;
        for (int cl: rev)
        {
          rnk[cl] = 1;
          fa[cl] = cl;
        }
        rev.clear();
        neq.clear();
        continue;
      }
    }
    else
    {
      if (fnd(x) == fnd(y))
      {
        ans.push_back(cnt);
        cnt = 0;
        for (int cl : rev)
        {
          rnk[cl] = 1;
          fa[cl] = cl;
        }
        neq.clear();
        rev.clear();
        continue;
      }
    }
    rev.push_back(x);
    rev.push_back(y);
    if (e)
    {
      join(x, y);
    }
    else
    {
      neq.insert({x, y});
    }
  }
  printf("%d\n", (int) ans.size());
  for (int x: ans)
  {
    printf("%d\n", x);
  }
}
/*
3
1 1 0
2 3 1
2 3 0
*/

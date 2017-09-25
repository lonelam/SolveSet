#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 305;
int n, m, P;
int a[maxn][maxn];
int b[maxn];
int mn[maxn], lb[maxn], rb[maxn], presum[maxn];
int d[maxn][30];
int md[maxn][30];
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
void inline RMQ_init(int A[], int lenA)
{
    for(int i = 0; i < lenA; i++) d[i][0] = md[i][0] = A[i];
    for(int j = 1; (1<<j) <= lenA; j++)
        for(int i = 0; i + (1<<j) - 1 < lenA; i++)
            d[i][j] = min(d[i][j-1], d[i + (1<<(j-1))][j-1]),
            md[i][j] = max(md[i][j-1], md[i + (1<<(j-1))][j-1]);
}
//[a, b)
int inline RMQmin(int a, int b)
{
  // b--;
  if (a == b) return 0;
    if(a > b) swap(a,b);
    // cout<<"a : "<<a<<" b : "<<b<<endl;
    int  k = log2(b-a);
    return min(d[a][k],d[b-(1<<k)][k]);
}
int inline RMQmax(int a, int b)
{
  // b--;
  if (a == b) return 0;
    if(a > b) swap(a,b);
    // cout<<"a : "<<a<<" b : "<<b<<endl;
    int  k = log2(b-a);
    return max(md[a][k],md[b-(1<<k)][k]);
}
int main()
{
  // freopen("data.in", "r", stdin);
    // while(scanf("%d%d%d",&n, &m, &P)!=EOF)
    while(in(n))
    {
      in(m);
      in(P);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            in(a[i][j]);
                // scanf("%d",&a[i][j]);
        int Max = INT_MIN;
        for(int i=0; i<n; i++)
        {
            //数组b表示i~j行，对应列元素的和
            //将二维动态规划问题转化为一维动态规划问题
            memset(b, 0, sizeof(b));
            memset(mn, inf, sizeof(mn));
            for(int j=i; j<n; j++)
            {
                //下面是针对数组b求最大子段和的动态规划算法
                presum[0] = 0;
                // multiset<int, cmp1> st1;
                // multiset<pair<int,int>,greater<pair<int,int> > > st1;
                for(int k=0; k<m; k++)
                {
                    b[k] += a[j][k];
                    presum[k+1] = presum[k] + b[k];
                    mn[k] = min(mn[k], a[j][k]);
                    // auto l_b = st1.upper_bound({mn[k], k});
                    // if (st1.empty() || l_b == st1.end())
                    // {
                    //   lb[k] = -1;
                    // }
                    // else
                    // {
                    //   lb[k] = (l_b)->second;
                    // }
                    // st1.insert({mn[k], k});
                    // sum += b[k];
                    // if(sum<0) sum = b[k];
                    // if(sum>Max) Max = sum;
                }
                // st1.clear();
                // for (int k = m-1; k>= 0; k--)
                // {
                //   auto r_b = st1.upper_bound({mn[k], k});
                //   if (st1.empty() || r_b == st1.end())
                //   {
                //     rb[k] = m;
                //   }
                //   else
                //   {
                //     rb[k] = (r_b)->second;
                //   }
                //   st1.insert({mn[k], k});
                // }
                // RMQ_init(presum, m + 2);
                int rmqmin = 0;
                static int minans[maxn];
                for (int k = 0; k < m; k++)
                {
                  minans[k] = rmqmin;
                  rmqmin = min(rmqmin, presum[k + 1]);
                  // printf("%d %d %d %d %d %d\n", lb[k], k, rb[k], RMQmax(k + 1, rb[k] + 1), RMQmin(lb[k] + 1, k + 1), RMQmax(k + 1, rb[k] + 1) - RMQmin(lb[k] + 1, k + 1) + (P - mn[k]));
                  // Max = max(Max, RMQmax(k + 1, rb[k] + 1) - RMQmin(lb[k] + 1, k + 1) + (P - mn[k]));
                }
                rmqmin = presum[m];
                for (int k = m-1; k>= 0; k--)
                {
                  rmqmin = max(rmqmin, presum[k+1]);
                  Max = max(Max, rmqmin - minans[k] + (P - mn[k]));
                  if (i == 0 && j == n-1 && rmqmin - minans[k] == presum[m])
                  {
                    for (int o  = 0; o < m; o++)
                    {
                      for (int oo = o + 1; oo <= m; oo++)
                      {
                        if (o == 0 && oo == m) continue;
                        Max = max(Max, presum[oo] - presum[o]);
                      }
                    }
                  }
                  else
                  {
                  Max = max(Max, rmqmin - minans[k]);
                  }
                  // Max = max(Max, rmqmin - minans[k]);
                }
            }
        }
        printf("%d\n",Max);
    }

    return 0;
}

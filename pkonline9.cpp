//单点替换、单点增减、区间求和、区间最值
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 222222;

int MAX[maxn<<2];
int MIN[maxn<<2];
int abm[maxn << 2];
int SUM[maxn<<2];
int max(int a,int b){if(a>b)return a;else return b;}
int min(int a,int b){if(a<b)return a;else return b;}

void PushUP(int rt)
{
  MAX[rt] = max(MAX[rt<<1] , MAX[rt<<1|1]);
  MIN[rt] = min(MIN[rt<<1] , MIN[rt<<1|1]);
  abm[rt] = min(abm[rt << 1], abm[rt << 1 | 1]);
  SUM[rt] = SUM[rt<<1] + SUM[rt<<1|1];
}

void build(int l,int r,int rt) {
  if (l == r)
    {
    scanf("%d",&MAX[rt]);
    MIN[rt] = MAX[rt];
    abm[rt] = abs(MAX[rt]);
    SUM[rt] = MAX[rt];
    //printf("mi = %d\n",MIN[rt]);
  //    printf("ma = %d\n",MAX[rt]);
    return ;
  }
  int m = (l + r) >> 1;
  build(lson);
  build(rson);
  PushUP(rt);
}

void update(int p,int tihuan,int l,int r,int rt)
{
  if (l == r) {
    MAX[rt] = tihuan;
    MIN[rt] = tihuan;
    abm[rt] = abs(tihuan);
    SUM[rt] = tihuan;
    return ;
  }
  int m = (l + r) >> 1;
  if (p <= m) update(p , tihuan ,lson);
  else update(p , tihuan , rson);
  PushUP(rt);
}

int query(int L,int R,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    return MAX[rt];
  }
  int m = (l + r) >> 1;
  int ret = INT_MIN;
  if (L <= m) ret = max(ret , query(L , R , lson));
  if (R > m)  ret =  max(ret , query(L , R , rson));
  return ret;
}

int query1(int L,int R,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    return MIN[rt];
  }
  int m = (l + r) >> 1;
  int ret = INT_MAX;
  if (L <= m) ret = min(ret , query1(L , R , lson));
  if (R > m)  ret =  min(ret , query1(L , R , rson));
  return ret;
}
//minimum of abs
int query2(int L,int R,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    return abm[rt];
  }
  int m = (l + r) >> 1;
  int ret = INT_MAX;
  if (L <= m) ret = min(ret , query2(L , R , lson));
  if (R > m)  ret =  min(ret , query2(L , R , rson));
  return ret;
}

int queryhe(int L,int R,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    return SUM[rt];
  }
  int m = (l + r) >> 1;
  int ret = 0;
  if (L <= m) ret += queryhe(L , R , lson);
  if (R > m)  ret +=  queryhe(L , R , rson);
  return ret;
}

int main()
{
  int n , m;
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d",&n);
    n = 1 << n;
    build(1 , n , 1);
    scanf("%d", &m);
    while (m --) {
      int op;
      int a , b;
      scanf("%d%d%d",&op,&a,&b);
      if (op == 1) //区间求最大
      {
      a++;
      b++;
         /* for(int i = 1;i<=10;i++)
          printf("%d ",MAX[i]);
        puts("");*/
        int mx = query(a, b, 1, n, 1);
        int mn = query1(a,b,1,n,1);
        int mabs = query2(a,b,1,n,1);
        ll ans = min(mabs*(ll)mabs,(ll) mn * (ll)mx);
        printf("%lld\n", ans);
      }
      else if (op == 2)

        update(a+1 , b , 1 , n , 1);
    }
  }
  return 0;
}

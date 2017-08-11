#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 100;
int T;
ll B[maxn];
struct node
{
  int val;
  ll cnt;
  int pre;
  int nex;
}pool[maxn * 2];
int tot ;
int A[60];
int n, m;
int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      tot = 0;
      scanf("%d%d", &n, &m);
      int Chead = 0, Ctail = -1;
      for (int i = 0; i <= m; i++)
      {
        scanf("%lld", B + i);
        if (B[i])
        {
          if (Ctail != -1) pool[Ctail].nex = tot;
          pool[tot] = {i, B[i], Ctail, -1};
          Ctail = tot++;
        }
      }
      pool[Chead].cnt--;
      if (pool[Chead].cnt == 0)
      {
        Chead = pool[Chead].nex;
        pool[Chead].pre = -1;
      }
      pool[tot] = {0, 1, -1,-1};
      int Dhead = tot++;
      int Dtail = Dhead;
      for (int i = 0; i < n; i++)
      {
        A[i] = pool[Chead].val;
        vector<pair<int,ll> > tmp;
        for (int p = Dhead; p != -1; p = pool[p].nex)
        {
          tmp.push_back({pool[p].val + A[i], pool[p].cnt});
        }
        for (int pD = Dhead, pC = Chead, j = 0; j < tmp.size(); j++)
        {
          while(pD != -1 && pool[pD].val < tmp[j].first)
          {
            pD = pool[pD].nex;
          }
          if (pD == -1)
          {
            pool[Dtail].nex = tot;
            pool[tot] = {tmp[j].first, tmp[j].second, Dtail, -1};
            Dtail = tot++;
            pD = Dtail;
          }
          else if (pool[pD].val != tmp[j].first)
          {
            pool[pool[pD].pre].nex = tot;
            pool[tot] = {tmp[j].first, tmp[j].second, pool[pD].pre, pD};
            pool[pD].pre = tot;
            pD = tot++;
          }
          else
          {
            pool[pD].cnt += tmp[j].second;
          }
          while(pC != -1 && pool[pC].val < tmp[j].first)
          {
            pC = pool[pC].nex;
          }
          pool[pC].cnt -= tmp[j].second;
          if (pool[pC].cnt == 0)
          {
            if (pool[pC].nex != -1) pool[pool[pC].nex].pre = pool[pC].pre;
            if (pool[pC].pre != -1) pool[pool[pC].pre].nex = pool[pC].nex;
            if (pC == Chead) Chead = pool[pC].nex;
            if (pC == Ctail) Ctail = pool[pC].pre;
            pC = pool[pC].nex;
          }
        }
      }
      for (int i = 0; i < n; i++)
      {
        printf("%d%c", A[i], (i == n - 1)? '\n': ' ');
      }
    }
  }
}

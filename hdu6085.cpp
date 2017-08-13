#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using std::max;
using std::min;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int size = 1000;
unsigned int A[32][11000], B[11000], ans[11000];
//对单独某32位进行操作(异或)
void set(unsigned * A, int k2)
{
  A[k2 >> 5] ^= (1 << (k2 & 31));
}
//获取单独一位
int get(unsigned * A, int k2)
{
  return (A[k2 >> 5] >> (k2 & 31) & 1);
}
void addin(int l, int r)
{
  //调整r直到区间长度为整32
  while((r - l) & 31)
  {
    r--;
    //调整r的同时在ans上把r-l这一段
    if (get(A[0], r)) set(ans, r - l);
  }
  int where = 0;
  //移动这个整32的区间使得l被32整除
  while(l & 31) l++, r++, where++;
  l >>= 5; r >>= 5;
  //
  for (int i = l; i < r; i++) ans[i-l] ^= A[where][i];
}
int n, m, N, M, q, pd[51000];
void solve()
{
  scanf("%d%d%d", &N, &M, &q);
  memset(pd, 0x00, sizeof(pd));
  memset(A, 0, sizeof(A));
  memset(B, 0, sizeof B);
  n = m = 0;
  memset(ans,0,sizeof(ans));
  for (int i = 1; i <= N; i++)
  {
    int k1;
    scanf("%d", &k1);
    pd[k1] = 1;
    for (int j = 0; j < 32; j++)
    {
      set(A[j], k1 + j);
    }
    n = max(n, k1);
  }
  memset(pd, 0, sizeof pd);
  for (int i = 1; i <= M; i++)
  {
    int k1;
    scanf("%d", &k1);
    set(B, k1);
    m = max(m, k1);
    pd[k1] = 1;
  }
  for (int i = 1; i <= m; i++)
  {
    if (get(B, i))
    {
      for (int j = 0; j <= n; j += i)
      {
        addin(j, min(n + 1, j + i));
      }
    }
  }
    for (; q; q--)
    {
      int k1;
      scanf("%d", &k1);
      printf("%d\n", (int)get(ans,k1));
    }
}
int main()
{
  int t;
  scanf("%d", &t);
  for (;t; t--) solve();
  return 0;
}

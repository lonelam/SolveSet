#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const int maxk = 17;
char A[maxn];
struct entry
{
  int nr[2];
  int p;
}L[maxn];
int P[maxk][maxn];
int N, i;
int stp, cnt;
int cmp(struct entry a, struct entry b)
{
  return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1]): (a.nr[0] < b.nr[1]);
}
int main()
{
  gets(A);
  for (N = strlen(A), i = 0; i < N; i++)
  {
    P[0][i] = A[i] - 'a';
  }
  for (stp = 1, cnt = 1; cnt < N; stp++, cnt <<= 1)
  {
    for (int i = 0; i < N; i++)
    {
      L[i].nr[0] = P[stp - 1][i];
      L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
      L[i].p = i;
    }
    sort(L, L + N, cmp);
    for (int i = 0; i < N; i++)
    {
      P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i-1].nr[0] && L[i].nr[1] == L[i-1].nr[1] ? P[stp][L[i-1].p]: i;
    }
    return 0;
  }
}

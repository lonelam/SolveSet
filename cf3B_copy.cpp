#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef pair<int,int> pii;
int nA, nB, n,m;
pii A[maxn], B[maxn];
int main()
{
  scanf("%d%d", &n, &m);
  nA = nB = 0;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 1) A[++nA] = {b, i + 1};
    else B[++nB] = {b, i + 1};
  }
  sort(A + 1, A + nA + 1);
  sort(B + 1, B + nB + 1);
  reverse(A + 1, A + nA + 1);
  reverse(B + 1, B + nB + 1);
  int R= 0, sA = 0, sB = 0;
  A[0] = {0,0};
  for (int i = 1; i <= nA; i++)
  {
    A[i].first += A[i-1].first;
  }
  B[0] = {0,0};
  for (int i = 1; i <= nB; i++)
  {
    B[i].first += B[i-1].first;
  }
  for (int i = 0; i <= nB && i + i <= m;i++)
  {
    int t = B[i].first + A[min(m-i-i, nA)].first;
    if (t > R) R = t, sA = min(m - i - i, nA), sB = i;
  }
  printf("%d\n", R);
  for (int i = 1; i <= sA; i++)
  {
    printf("%d\n", A[i].second);
  }
  for (int i = 1; i <= sB; i++)
  {
    printf("%d ", B[i].second);
  }
}

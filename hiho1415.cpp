#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
const int chsize = 256;
int sa[maxn], cntA[maxn];
char ch[maxn];
int rnk[maxn], cntB[maxn], tsa[maxn], height[maxn];
int A[maxn], B[maxn];
int n;
void solve()
{
  for (int i = 0; i < chsize; i++) cntA[i] = 0;
  for (int i = 1; i <= n; i++) cntA[ch[i]]++;
  for (int i = 1; i < chsize; i++) cntA[i] += cntA[i - 1];
  for (int i = n; i; i--) sa[cntA[ch[i]]--] = i;
  rnk[sa[1]] = 1;
  for (int i = 2; i <= n; i++)
  {
    rnk[sa[i]] = rnk[sa[i-1]];
    if (ch[sa[i]] != ch[sa[i-1]]) rnk[sa[i]]++;
  }
  for (int l = 1; rnk[sa[n]] < n; l <<= 1)
  {
    for (int i = 0; i <= n; i++) cntA[i] = 0;
    for (int i = 0; i <= n; i++) cntB[i] = 0;
    for (int i = 1; i <= n; i++)
    {
      cntA[A[i] = rnk[i]]++;
      cntB[B[i] = (i + l <= n)? rnk[i+l]: 0]++;
    }
    for (int i = 1; i <= n; i++) cntB[i] += cntB[i-1];
    for (int i = n; i; i--) tsa[cntB[B[i]]--] = i;
    for (int i = 1; i <= n; i++) cntA[i] += cntA[i-1];
    for (int i = n; i; i--) sa[cntA[A[tsa[i]]]--] = tsa[i];
    rnk[sa[1]] = 1;
    for (int i = 2; i <= n; i++)
    {
      rnk[sa[i]] = rnk[sa[i-1]];
      if(A[sa[i]] != A[sa[i-1]] || B[sa[i]] != B[sa[i-1]]) rnk[sa[i]]++;
    }
  }
  for (int i = 1, j = 0; i <= n; i++)
  {
    if (j) j--;
    while(ch[i+j] == ch[sa[rnk[i]-1] + j]) j++;
    height[rnk[i]] = j;
  }
}
char pieceA[maxn];
char pieceB[maxn];
int main()
{
  scanf("%s%s",pieceA,pieceB);
  int nA = strlen(pieceA);
  int nB = strlen(pieceB);
  pieceA[nA] = '#';
  strcpy(pieceA + nA + 1, pieceB);
  strcpy(ch + 1, pieceA);
  n = strlen(ch + 1);
  solve();
  int ans = 0;
  for (int i = 2; i <= n; i++)
  {
    if ((sa[i] - nA - 1) * (sa[i-1] - nA - 1) < 0)
    {
      ans = max(ans, height[i]);
    }
  }
  printf("%d\n", ans);
}

#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
const int chsize = 300;
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
int main()
{
  int T;
  int k;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &k);
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    solve();
    // for (int i = 1; i <= n; i++) cout << height[i] << " ";
    // cout << endl;
    // multiset<int> hset;
    map<int,int> hset;
    height[1] = height[n + 1] = 0;
      int ans = 0;
      int leave;
    if (k <= n)
    {
        for (int i = 2; i <= k; i++)
        {
          hset[height[i]]++;
          // hset.insert(height[i]);
        }
        leave = k!=1?min(hset.begin()->first - height[k + 1], hset.begin()->first):((n-sa[k]+1) -height[k+1]);
        if (leave > 0 && k <= n)
        {
          ans += leave;
        }
      }
    for (int i = k + 1; i <= n; i++)
    {
      if ((--hset[height[i-k + 1]])==0)
      {
        hset.erase(hset.find(height[i-k+1]));
      }
      // hset.erase(hset.find(height[i - k + 1]));
      hset[height[i]]++;
      if (k != 1)
      leave = min(hset.begin()->first - height[i - k + 1], hset.begin()->first - height[i + 1]);
      else
      leave = (n - sa[i]+1) - max(height[i-k+1],height[i+1]);
      if (leave > 0)
      {
        ans += leave;
      }
    }
    printf("%d\n", ans);
  }
}

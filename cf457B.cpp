#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;

const int maxn = 100000 + 10;
ll n, k;
int main()
{
  while(cin >> n >> k)
  {
    if (__builtin_popcountll(n) > k)
    {
      printf("No\n");
      continue;
    }
    else
    {
      printf("Yes\n");
    }
    multiset<int, greater<int> > Q;
    ll mask = 0;
    while(n)
    {
      if (n & 1)
      {
        Q.insert(mask);
      }
      n >>= 1;
      mask++;
    }
    while(Q.size() < k)
    {
      int s = *Q.begin();
      Q.erase(Q.begin());
      Q.insert(s-1);
      Q.insert(s - 1);
    }
    bool fst = true;
    vector<int> ans(Q.begin(), Q.end());
    for (int i = 0; i < ans.size(); i++)
    {
      printf("%d%c", ans[i], (i==ans.size() - 1)? '\n': ' ');
    }
  }
}

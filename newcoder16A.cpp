#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n;
int M[maxn], S[maxn];
struct top
{
  int m, s;
  bool operator< (const top & rhs) const
  {
    if (m != rhs.m) return m > rhs.m;
    return s > rhs.s;
  }
} ts[maxn];
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", M + i, S +i);
    ts[i] = {M[i], S[i]};

  }
  sort(ts, ts + n);
  set<int> st;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (st.lower_bound(ts[i].s) != st.end())
    {
      cnt++;
    }
    st.insert(ts[i].s);
  }
  printf("%d\n", cnt);
}

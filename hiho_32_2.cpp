#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 320000;
int n, k;
bool inK[maxn];
bool inS[maxn];
int cnt[maxn];
struct ticket
{
  int t, c;
  bool operator<(const ticket & rhs) const
  {
    return t < rhs.t;
  }
}ts[maxn];

int tmp;
int main()
{
  scanf("%d%d", &n, &k);
  int pre = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &ts[i].t, &ts[i].c);
  }
  set<pair<int,int> > K;
  sort(ts, ts + n);
  for (int i = 0; i < k; i++)
  {
    scanf("%d", &tmp);
    inS[tmp] = true;
  }
  int SinK = 0, minK = 0;
  int ans = 0;
  if (k == 314159)
  {
    minK = -1;
    SinK = 314159;
    ans = ts[0].t;
    for (int i = 1; i <= 314159; i++)
    {
      inK[i] = true;
      K.insert({0, i});
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (inK[ts[i].c])
    {
      inK[ts[i].c] = false;
      K.erase(K.find({cnt[ts[i].c], ts[i].c}));
      if (inS[ts[i].c])
      {
        SinK--;
      }
    }
    cnt[ts[i].c]++;
    if (cnt[ts[i].c] > minK)
    {
      if (K.size() == k)
      {
        minK++;
        while(!K.empty() && K.begin()->first <= minK)
        {
          inK[K.begin()->second] = false;
          if (inS[K.begin()->second]) SinK--;
          K.erase(K.begin());
        }
      }
      else
      {
        inK[ts[i].c] = true;
        if (inS[ts[i].c]) SinK++;
        K.insert({cnt[ts[i].c], ts[i].c});
      }
    }
    if (i!=n-1 && ts[i+1].t != ts[i].t)
    {
    //  cout << SinK << " "<< ts[i].t << endl;
      if (SinK == k)
      {
        ans += ts[i+1].t - ts[i].t;
      }
    }
  }
  printf("%d\n", ans);
}

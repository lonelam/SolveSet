#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  int n, v;
  scanf("%d%d", &n, &v);
  multiset<pii> kay;
  priority_queue<pii> cata;
  multiset<int> ans;
  int t, p;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &t, &p);
    if (t == 1)
    {
      kay.insert({p, i +1 });
      ans.insert(i + 1);
      sum += p;
    }
    else if (t == 2)
    {
      cata.push({p, i + 1});
    }
  }
  while(kay.size() > v)
  {
    sum -= kay.begin()->first;
    ans.erase(kay.begin()->second);
    kay.erase(kay.begin());
  }
  int cnt = kay.size();
  int sz = kay.size();
  while(!cata.empty())
  {
    pii cp = cata.top();
    cata.pop();
    if (sz + 2 <= v)
    {
      sz += 2;
      cnt += 1;
      sum += cp.first;
      ans.insert(cp.second);
    }
    else if (sz + 1 <= v && kay.size() >= 1)
    {
      int kp = kay.begin()->first;
      if (cp.first > kp)
      {
        sz += 1;
        sum += cp.first - kp;
        ans.erase(kay.begin()->second);
        ans.insert(cp.second);
        kay.erase(kay.begin());
      }
      else
      {
        break;
      }
    }
    else if (kay.size() >= 2)
    {
      int kp = kay.begin()->first;
      int k1 = kay.begin()->second;
      kay.erase(kay.begin());
      kp += kay.begin()->first;
      int k2 = kay.begin()->second;
      kay.erase(kay.begin());
      if (cp.first > kp)
      {
        ans.erase(k1);
        ans.erase(k2);
        ans.insert(cp.second);
        sum += cp.first - kp;
        cnt -= 1;
      }
      else
      {
        break;
      }
    }
    else
    {
      break;
    }
  }
  printf("%d\n", sum);
  for (int i : ans)
  {
    printf("%d ", i);
  }
}

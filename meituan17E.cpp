#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

ll ans[10];
ll head[10];
int digit[20];
void go(ll ub)
{
  ll dmask = 1, dgrade = -1;
  memset(head, 0, sizeof(head));
  while(dmask <= ub)
  {
    dgrade ++;
    digit[dgrade] = (ub / dmask) % 10;
    dmask *= 10;
  }
  dmask /= 10;
  reverse(digit, digit + dgrade + 1);
  head[digit[0]] += (ub - dmask * digit[0] + 1);
  for (int i = 1; i < digit[0]; i++)
  {
    head[i] += dmask;
  }
  dmask /= 10;
  while(dmask)
  {
    for (int i = 1; i <= 9; i++)
    {
      head[i] += dmask;
    }
    dmask /= 10;
  }
}
void calc(ll ub)
{
  ll from = ub, to = ub;
  ll f = 1;
  memset(ans,0,sizeof(ans));
  for (ll g = 2; g * g <= ub; g++)
  {
    to = from;
    from = ub / g;
    go(to);
    for (int i = 1; i <= 9; i++)
    {
      ans[i] += f * head[i];
    }
    go(from);
    for (int i = 1; i <= 9; i++)
    {
      ans[i] -= f * head[i];
    }
    f++;
  }
  for (int i = 1; i <= from; i++)
  {
    int tmp = i;
    while(tmp / 10) tmp /= 10;
    ans[tmp] += ub / i;
  }
}
ll ret[10];
int main()
{
  ll L, R;
  while(cin >> L >> R)
  {
    memset(ret, 0, sizeof(ret));
    calc(R);
    for (int i = 1; i <= 9; i++) ret[i] += ans[i];
    calc(L - 1);
    for (int i = 1; i <= 9; i++) ret[i] -= ans[i];
    for (int i = 1; i <= 9; i++) cout << ret[i] << endl;
  }
}

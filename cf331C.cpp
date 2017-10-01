#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
#define mp(x,y) make_pair((x),(y))
//state to ans
typedef pair<ll, int> pp;
map<pp,pp> mp;
// mx descended

// returned the extra number substracted(second) and the exact time used to substract v under 0
pp gao(ll v, int mx)
{
  if (v == 0) return mp(0, 0);
  if (v < 10)
  {
    pp ans = mp(1, 0);
    if (v < mx) ans.second = (mx - v);
    return ans;
  }
  pp state = mp(v, mx);
  // already solved
  if (mp.find(state) != mp.end()) return mp[state];
  ll step = 1;
  // one step to decrease one digit at head of number
  while(step <= v / 10) step *= 10;
  pp ans = mp(0,0);
  // one step each loop
  while(true)
  {
    //head digit here
    int dig = v / step;
    int newmx = mx;
    // maximum
    if (dig > newmx) newmx = dig;
    // use the updated newmx to substract the lower level number
    pp cur = gao(v % step, newmx);
    //update the answer(substraction time)
    ans.first += cur.first;
    // substract v under zero
    v -= v % step;
    if (cur.second > 0) v -= cur.second;
    else
    {
      v -= newmx;
      // substract extra time to let (v % step) be 999-like tail
      if (newmx > 0) ans.first++;
    }
    if (dig == 0) break;
  }
  // v is under zero
  // and second is the extra number;
  ans.second = -v;
  //memory search
  // about 1800 states totally
  mp[state] = ans;
  return ans;
}
int main()
{
  ll n;
  cin >> n;
  mp.clear();
  pp result = gao(n, 0);
  cout << result.first << endl;
  return 0;
}

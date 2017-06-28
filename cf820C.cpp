#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int table[maxn];
int main()
{
  ll a,b,l,r;

  while(cin >> a >>b>> l >> r)
  {
    for (int i = 0; i < a; i++)
    {
      table[i] = i;
    }
    for (int i = a; i < a+b; i++)
    {
      table[i] = a-1;
    }
    set<int> st;
    for (int i = 0; i < 26; i++)
    {
      st.insert(i);
    }
    for (int i = b; i < a+b; i++)
    {
      if (st.find(table[i])!=st.end()) st.erase(table[i]);
    }
    for (int i = a+b; i < a*2+b; i++)
    {
      table[i] = *st.begin();
      st.erase(st.begin());
    }
    st.clear();
    for (int i = 0; i < 26; i++)
    {
      st.insert(i);
    }
    for (int i = a*2+b; i < a*2 +b*2; i++)
    {
      table[i] = table[a*2+b-1];
    }
    for (int i = b*2+a*1; i < 2*a+b*2; i++)
    {
      if (st.find(table[i])!=st.end()) st.erase(table[i]);
    }
    for (int i = a*2+b*2; i < a*3+b*2; i++)
    {
      table[i] = *st.begin();
      st.erase(st.begin());
    }
    for (int i = a*3+b*2; i < a*3 +b*3; i++)
    {
      table[i] = table[a*3+b*2-1];
    }
    l--;
    ll ans;
    ll Lseg = l / (a+b);
    ll Rseg = (r-1) / (a+b);
    if (Lseg == Rseg)
    {
      int from = l%(a+b);
      int to = (r-1)%(a+b) + 1;
      set<int> cnt;
      for (int i = from; i < to; i++)
      {
        cnt.insert(table[i]);
      }
      ans = cnt.size();

    }
    else if (Lseg + 1 == Rseg)
    {
      int from = l % (a+b);
      int to = a+b+(r-1)%(a+b)+1;
      set<int> cnt;
      for (int i = from; i < to; i++)
      {
        cnt.insert(table[i]);
      }
      ans = cnt.size();
    }
    else if (Lseg + 2 == Rseg)
    {
      int from = l % (a+b);
      int to = 2*a+2*b+(r-1)%(a+b)+1;
      set<int> cnt;
      for (int i = from; i < to; i++)
      {
        cnt.insert(table[i]);
      }
      ans = cnt.size();
    }
    else
    {
      set<int> cnt;
      for (int i = 0; i < 3*b+3*a; i++)
      {
        cnt.insert(table[i]);
      }
      ans = cnt.size();
    }
    cout << ans << endl;
  }

}

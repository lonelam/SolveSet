#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000000;
bool nprime[maxn];
int ptot;
int primes[maxn];
void init()
{
  nprime[1] = true;
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
    {
      primes[ptot++] = i;
    }
    for (int j = 0; j < ptot && i * primes[j] < maxn; j++)
    {
      nprime[i * primes[j]] = true;
      if (i % primes[j]==0)
      {
        break;
      }
    }
  }
}
pair<int,int> ans[maxn];
map<pair<int,int>, int> preans;
int main()
{
  init();
  for (int bi = 0; primes[bi] <=2000; bi++)
  {
    int b = primes[bi];
    for (int a = -2000; a <= 2000; a++)
    {
      int n = 0;
      while(n*n+a*n+b >0 && !nprime[n*n+a*n+b])n++;
      int tar = max(abs(a), b);
      preans[{a,b}] = n;
      if (preans[ans[tar]] < n)
      {
        ans[tar] = {a,b};
        //eans[max(abs(a), b)] = {a,b};
      }
    }
  }
  for (int i = 1; i <= 2000; i++)
  {
    if (preans[ans[i]] < preans[ans[i-1]])
    {
      ans[i] = ans[i-1];
    }
  }
  int n;
  while(cin >> n)
  {
    cout << ans[n].first <<" "<< ans[n].second << endl;
  }
}

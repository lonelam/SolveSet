#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 100;
const int BUF = 40000000;
int b[maxn], a[maxn];
int n, m;
char Buf[BUF], *buf = Buf;
inline void read(int&a){for(a=0;*buf<48;buf++);while(*buf>47)a=a*10+*buf++-48;}
inline void read(ll&a){for(a=0;*buf<48;buf++);while(*buf>47)a=a*10+*buf++-48;}
ll limit, maxdiff;
bool check(int l, int r)
{
  int i = l, j = r - 1;
  maxdiff = 0;
  memcpy(b + l, a + l, sizeof(int) * (r- l));
  sort(b + l, b + r);
  int lm = m;
  while(i < j && lm--)
  {
    maxdiff += (ll)(b[j] - b[i]) * (b[j] - b[i]);
    i++;
    j--;
  }
  return maxdiff <= limit;
}
int main()
{
  int T;
  scanf("%d", &T);
//  fread(Buf,1,BUF,stdin);read(T);

  while(T--)
  {
 //   read(n),read(m);
  //  read(limit);
   // for(int i=0;i<n;i++)read(a[i]);
    scanf("%d%d%lld", &n, &m, &limit);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int l = 0, r = 1;
    int ans = 0;
    while(l != n)
    {
      const int br = l + sqrt(n - l);
      int ql = l + 1, qr = br;
      while(ql + 1 < qr)
      {
        const int mid = (ql + qr) / 2;
        if (check(l, mid))
        {
          ql = mid;
        }
        else
        {
          qr = mid;
        }
      }
      if (ql + 1 < br)
      {
        ans++;
        l = ql;
        continue;
      }
      ql = l + 1, qr = n + 1;
      while(ql + 1 < qr)
      {
        const int mid = (ql + qr) / 2;
        if (check(l, mid))
        {
          ql = mid;
        }
        else
        {
          qr = mid;
        }
      }
      ans++;
      l = ql;
    }
    printf("%d\n", ans);
  }
}

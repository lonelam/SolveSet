#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const int maxk = 20;
map<string, int> id;
map<int, string> table;
int tot;
int n, m;
char tmp[maxn];
int get_id()
{
  if (id.find(tmp) != id.end())
  {
    return id[tmp];
  }
  else
  {
    return id[tmp]=tot++;
  }
}
int main()
{
  while(scanf("%d", &n) != EOF)
  {
    tot = 0;
    for (int i = 0; i < n;i ++)
    {
      scanf("%s", tmp);
      int u = get_id();
      scanf("%s", tmp);
      int v = get_id();
      
    }
  }
}

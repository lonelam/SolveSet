#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
bool check(int x, int y)
{
  if (x < 0 || x > 23 || y < 0 || y > 59) return false;
  return x / 10 == y % 10 && x % 10 == y / 10;
}
int main()
{
  int x, y;
while(  scanf("%d:%d", &x, &y)){
  int ans = 0;
  while(!check(x, y))
  {
    ans++;
    y++;
    if (y == 60) y = 0, x++;
    if (x == 24) x= 0;
  }
  printf("%d\n", ans);
}
}

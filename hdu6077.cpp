
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
char grid[8][25];
pair<int,int> pos[] = {{0, 1}, {1, 0}, {1, 3}, {3, 1}, {4, 0}, {4, 3}, {6, 1}};
map<int,int> pro = {{119,0}, {18,1}, {93,2}, {91,3}, {58,4}, {107,5}, {111,6}, {82,7}, {127,8}, {123, 9}};
int code(int cx, int cy)
{
  int ret = 0;
  for (int i = 0; i < 7; i++)
  {
    if (grid[pos[i].first + cx][pos[i].second + cy] == 'X')
    {
      ret |= 1 << (6-i);
    }
  }
  return ret;
}
char ans[10];
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    for (int i = 0; i < 7; i++)
    {
      scanf("%s", grid[i]);
    }
    // cout << code(0, 12)<<endl;
    ans[0] = pro[code(0,0)] + '0';
    ans[1] = pro[code(0, 5)]+ '0';
    ans[2] = ':';
    ans[3] = pro[code(0, 12)]+ '0';
    ans[4] = pro[code(0, 17)]+ '0';
    ans[5] = '\0';
    printf("%s\n", ans);
  }
}
/*
2
.XX...XX.............
X..X....X......X.X..X
X..X....X.X....X.X..X
......XX..........XX.
X..X.X....X....X....X
X..X.X.........X....X
.XX...XX.............

.XX...XX.....XX...XX.
X..X....X...X..X.X..X
X..X....X.X.X..X.X..X
......XX.....XX...XX.
X..X.X....X.X..X.X..X
X..X.X......X..X.X..X
.XX...XX.....XX...XX.
*/

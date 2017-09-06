#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct date
{
  int year, month, day;
};

int weekday(date a)
{
  int tm = a.month >= 3? (a.month - 2):(a.month + 10);
  int ty = a.month >= 3? a.year : (a.year - 1);
  return (ty + ty / 4 - ty / 100 + ty / 400 + (int)(2.6 * tm - 0.2) + a.day) % 7;
}
inline int leap(int year)
{
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
int T;
int main()
{
  scanf("%d", &T);
  while(T--)
  {
    date raw, A;
    scanf("%d-%d-%d", &A.year, &A.month, &A.day);
    raw = A;
    int tar = weekday(A);
    while(true)
    {
      A.year++;
      if (weekday(A) == tar)
      {
        if (!leap(A.year) && A.month == 2 && A.day == 29) continue;
        printf("%d\n", A.year);
        break;
      }
    }
  }
}

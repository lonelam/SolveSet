#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000;
char number[maxn];
char raw[maxn];
const ll moder = 1e9 + 7;
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%s", raw);
    int n = strlen(raw);
    int p = 0;
    int begin = 0;
    int end = 0;
    int cnt = 0;
    bool up = false;
    for (int i = 0; i < n; i++)
    {
      if (!up && raw[i] == '(')
      {
        begin = i + 1;
        up = true;
      }
      else if (up && raw[i] == ')')
      {
        up = false;
        end = i;
      }
      else if (raw[i] == '#')
      {
        int index = raw[i + 2] - '0';
        for (int i = 0; i < index; i++)
        {
          for (int j = begin; j < end; j++)
          {
            number[p++] = raw[j];
          }
        }
        i = i + 3;
      }
      else if (!up)
      {
        number[p++] = raw[i];
      }
    }
    number[p] = '\0';
    ll mask = 1;
    ll ans = 0;
    for (int i = p - 1; i >= 0; i--)
    {
      ans = (ans + mask * (number[i] - '0')) % moder;
      mask = (mask * 10) % moder;
    }
    printf("%d\n", (int)ans);
  }
}

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
bool vis[maxn];
queue<int> a;
stack<int> s;
int b = 1;
int arr[maxn];

int main()
{
  int n, k;
  while(~scanf("%d%d", &n, &k))
  {
    int tmp;
    for (int i = 0; i < k; i++)
    {
      scanf("%d", arr + i);
      vis[arr[i]] = true;
      a.push(arr[i]);
    }
    while(b <= n)
    {
      if (!s.empty() && s.top() == b)
      {
        s.pop();
        b++;
      }
      else if (!a.empty())
      {
        s.push(a.front());
        a.pop();
      }
      else
      {
        if (s.empty())
        {
          for (int j = k; j < n; j++)
          {
            arr[j] = (n + k) - j;
          }
          k = n;
          b = n+1;
        }
        else
        {
          for (int j = s.top() - 1; j >= b; j--)
          {
            if (!vis[j])
            {
              vis[j] = true;
              arr[k++] = j;
            }
            else
            {
              printf("-1\n");
              exit(0);
            }
          }
          // arr[k++] = s.top();
          b = s.top();
          // s.pop();
        }
      }
      // for (int i = 0; i < k; i++)
      // {
      //   printf("%d%c", arr[i], i==(k-1)?'\n':' ');
      // }
    }
    if (!s.empty() || !a.empty() || k != n)
    {
      // for (int i = 0; i < k; i++)
      // {
      //   printf("%d%c", arr[i], i==(k-1)?'\n':' ');
      // }
        printf("-1\n");
        exit(0);
    }
    else
    {
      for (int i = 0; i < k; i++)
      {
        printf("%d%c", arr[i], i==(k-1)?'\n':' ');
      }
    }
  }
}

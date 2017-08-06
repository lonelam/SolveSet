#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const int maxk = 800;
int k;
int A[maxk][maxk];
void merge(int j)
{
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
  sort(A[j], A[j] + k);
  for (int i = 0; i < k; i++)
  {
    Q.push({A[0][i] + A[j][0], 0});
  }
  for (int i = 0; i < k; i++)
  {
    pair<int,int> tmp = Q.top();Q.pop();
    A[0][i] = tmp.first;
    Q.push({tmp.first - A[j][tmp.second] + A[j][tmp.second + 1], tmp.second + 1});
  }
}
int main()
{
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  while(scanf("%d", &k) != EOF)
  {
    for (int i = 0; i < k; i++)
    {
      for (int j = 0; j < k; j++)
      {
        scanf("%d", A[i] + j);
      }
    }
    sort(A[0], A[0] + k);
    for (int i = 1; i < k; i++)
    {
      merge(i);
    }
    for (int i = 0; i < k; i++)
    {
      printf("%d%c", A[0][i], (i==k-1)?'\n':' ');
    }

  }
}

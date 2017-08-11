#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxk = 800;
const int inf = 0x3f3f3f3f;
int k;
int arr[maxk][maxk];
struct Item
{
  int s, b;
  bool operator< (const Item & rhs) const
  {
    return s > rhs.s;
  }
};
void merge(int * A, int * B, int * C, int n)
{
  priority_queue<Item> Q;
  for (int i = 0; i < n; i++)
  {
    Q.push({A[i] + B[0], 0});
  }
  for (int i = 0; i < n; i++)
  {
    Item item = Q.top();
    Q.pop();
    C[i] = item.s;
    int b = item.b;
    if (b + 1 < n) Q.push({item.s - B[b] + B[b + 1], b + 1});
  }
}
int main()
{
  while(scanf("%d", &k) != EOF)
  {
    for (int i = 0; i < k; i++)
    {
      for (int j = 0; j < k; j++)
      {
        scanf("%d", arr[i] + j);
      }
      sort(arr[i], arr[i] + k);
    }
    for (int i = 1; i < k; i++)
    {
      merge(arr[0], arr[i], arr[0], k);
    }
    printf("%d", arr[0][0]);
    for (int i = 1; i < k; i++){
      printf(" %d", arr[0][i]);
    }
    printf("\n");
  }
}

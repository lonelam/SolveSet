#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
map<int,int> dict;
int getOrder(int c)
{
  if (dict.find(c) == dict.end()) dict[c] = dict.size();
  return dict[c];
}
int a[maxn], b[maxn];
vector<int> G[maxn];
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", b + i);
    a[i] = getOrder(b[i]);
    G[a[i]].push_back(i);
  }
  int m = dict.size();
}

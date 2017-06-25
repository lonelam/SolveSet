#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
char table[] = "0123456789ABCDEF";
string trans(int x, int base)
{
  string ans;
  while(x)
  {
    ans.push_back(table[x % base]);
    x /= base;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
char tar[maxn];
int nex[maxn];
void prekmp(char x[], int m, int kmpnex[])
{
  int i, j;
  j = kmpnex[0] = -1;
  i = 0;
  while(i < m)
  {
    while(-1!=j && x[i] != x[j]) j = kmpnex[j];
    if (x[++i] == x[++j]) kmpnex[i] = kmpnex[j];
    else kmpnex[i] = j;
  }
}
bool kmp(char x[], int m, const char y[], int n)
{
  int i, j;
  int ans = 0;
  prekmp(x, m, nex);
  i = j = 0;
  while(i < n)
  {
    while(-1 != j && y[i] != x[j]) j = nex[j];
    i++;j++;
    if (j >= m)
    {
      ans++;
      j = nex[j];
    }
  }
  return ans;
}
int main()
{
  int n;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> tar;
  string stmp;
  bool nfound = true;
  for (int k = 2; k <= 16; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      stmp += trans(i, k);
    }
  //  cout << stmp << endl;
    if (kmp(tar, strlen(tar), stmp.c_str(),stmp.size()))
    {
      cout << "yes\n";
      nfound = false;
      break;
    }
    stmp.clear();
  }
  if (nfound)
  {
    cout << "no\n";
  }
}

#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 100;
ll digit[maxn];
ll C[maxn][maxn];
ll dfs(ll cur, ll kdigit, ll base);
void init_Compo() {
  for (int i = 0; i < 36; i++)
  {
    C[i][0] = 1;
  }
  for (int i = 1; i < 36; i++) {
    for (int j = 1; j <= i; j++)
    {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
}
ll count(ll tar, ll kdigit, ll base) {
  digit[0] = 0;
  ll cur = 0;
  if (tar <= 0)
  {
    return 0LL;
  }
  while (tar) {
    digit[cur] = tar % base;
  ///  cout << digit[cur] << " ";
    tar /= base;
    cur++;
  }
  ///cout << endl;
//  cout << dfs(cur - 1, kdigit, base) << endl;
  return dfs(cur - 1, kdigit, base);
  return 0LL;
}
ll dfs(ll cur, ll kdigit, ll base) {
  if (cur == -1)
  {
    return kdigit == 0 ? 1LL : 0LL;
  }
  if (kdigit > cur + 1)
  {
    return 0LL;
  }
  if (digit[cur] > 1) {
    return C[cur + 1][kdigit];
  }
  if (digit[cur] == 1)
  {
    return C[cur][kdigit] + dfs(cur - 1, kdigit - 1, base);
  }
  if (digit[cur] == 0)
  {
    return dfs(cur - 1, kdigit, base);
  }
  return 0;
//  cout << "errrr\n";
//  throw runtime_error("ttt");
}
int main() {
  init_Compo();
  ll X, Y, K, B;
  while (cin >> X >> Y >> K >> B) {
    cout << count(Y, K, B) - count(X - 1, K, B) << endl;
  }
}

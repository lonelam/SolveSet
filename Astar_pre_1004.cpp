#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
const int maxb = 1000 + 5;
struct select
{
  int score;
  int number_sum;
  vector<int> st;
} dp[maxb];
bool operator<(const select & lhs, const select & rhs)
{
  if (lhs.score != rhs.score) return lhs.score < rhs.score;
  if (lhs.number_sum != rhs.number_sum) return lhs.number_sum > rhs.number_sum;
  for (int i = 0; i < min(lhs.st.size(), rhs.st.size()); i++)
  {
    if (lhs.st[i] != rhs.st[i])
    {
      return lhs.st[i] > rhs.st[i];
    }
  }
  return false;
}
int main()
{
  int B, N;
  int kase = 1;
  int T;
  scanf("%d", &T);
  while(T--)
  {scanf("%d%d", &B, &N);
    dp[0] = {0, 0, {}};
    for (int i = 1; i <= B; i++)
    {
      dp[i] = {-1, inf, {}};
    }
    for (int i = 0; i < N; i++)
    {
      static int score_i, cost_i;
      scanf("%d%d", &score_i, &cost_i);
      for (int j = B; j >= cost_i; j--)
      {
        select tmp = {dp[j - cost_i].score, dp[j-cost_i].number_sum, dp[j - cost_i].st};
        tmp.st.push_back(i + 1);
        tmp.score += score_i;
        tmp.number_sum += i + 1;
        dp[j] = max(dp[j], tmp);
      }
    }
    select ans = {-1,inf,{}};
    int a2 = 0;
    for (int i = 0; i <= B; i++)
    {
      if (ans < dp[i])
      {
        ans = dp[i];
        a2 = i;
      }
    }
    printf("Case #%d:\n", kase++);
    printf("%d %d\n", ans.score, a2);
    for (int i = 0; i < ans.st.size(); i++)
    {
      printf("%d%c", ans.st[i], (i==ans.st.size()-1)?'\n':' ');
    }
  }
}

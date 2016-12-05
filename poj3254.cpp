#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 12;
const int maxs = 1 << maxn;
int dp[maxs][maxn][2];
bool g[maxn][maxn];

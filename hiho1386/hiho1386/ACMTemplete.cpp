#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int Nlimit = 1e9;
int budget;
int sumdp[1001][2][6][6][4];
int cnt[1001][2][6][6][4];

int M;
struct player
{
	int val, cost, type;
	bool operator<(const player & rhs) const
	{
		return val > rhs.val;
	}
}ps[500 + 10];
int v, cst;
char tstr[1000];
int main()
{
	
	int T;
	while(scanf("%d", &T)!=EOF)
	{
		while (T--)
		{
			scanf("%d", &M);
			for (int i = 0; i < M; i++)
			{
				scanf("%s%d%d", tstr, &v, &cst);
				if (tstr[0] == 'G')
				{
					ps[i].type = 1;
				}
				else if (tstr[0] == 'D')
				{
					ps[i].type = 2;
				}
				else if (tstr[0] == 'M')
				{
					ps[i].type = 3;
				}
				else if (tstr[0] == 'F')
				{
					ps[i].type = 4;
				}
				ps[i].val = v;
				ps[i].cost = cst;
			}
			scanf("%d", &budget);
			sort(ps, ps + M);
			memset(sumdp, 0, sizeof(sumdp));
			memset(cnt, 0, sizeof(cnt));
			/*for (int c = 0; c <= budget; c++)
			{
				cnt[c][0][0][0][0] = 1;
			}
			*/
			cnt[0][0][0][0][0] = 1;
			for (int i = 0; i < M; i++)
			{
				for (int j = 1; j >= 0; --j)
				{
					for (int k = 5; k >= 0; k--)
					{
						for (int s = 5; s >= 0; s--)
						{
							for (int r = 3; r>= 0; r--)
							{
								if (j + k + s + r > 10) continue;
								int vv = ps[i].val;
								if (j + k + s + r == 0)
								{
									vv *= 2;
								}
								int tj = j, tk = k, tr = r, ts = s;
								int tp = ps[i].type;
								if (tp == 1) tj++;
								else if (tp == 2) tk++;
								else if (tp == 3) ts++;
								else if (tp == 4) tr++;
								if (tj > 1 || tk > 5 || ts > 5 || tr > 3) continue;
								for (int c = budget - ps[i].cost; c >= 0; c--)
								{
									int tc = c + ps[i].cost;
									if (cnt[c][j][k][s][r])
									{
										if (sumdp[tc][tj][tk][ts][tr] < sumdp[c][j][k][s][r] + vv)
										{
											sumdp[tc][tj][tk][ts][tr] = sumdp[c][j][k][s][r] + vv;
											cnt[tc][tj][tk][ts][tr] = cnt[c][j][k][s][r];
										}
										else if (sumdp[tc][tj][tk][ts][tr] == sumdp[c][j][k][s][r] + vv)
										{
											cnt[tc][tj][tk][ts][tr] += cnt[c][j][k][s][r];
											cnt[tc][tj][tk][ts][tr] = min(cnt[tc][tj][tk][ts][tr], Nlimit);
										}
									}
									/*if (ps[i].type == 1 && j)
									{
										if (cnt[c - ps[i].cost][j - 1][k][s][r] && sumdp[c][j][k][s][r] == sumdp[c - ps[i].cost][j - 1][k][s][r] + ps[i].val)
										{
											cnt[c][j][k][s][r] += cnt[c - ps[i].cost][j - 1][k][s][r];
											if (cnt[c][j][k][s][r] > Nlimit)
											{
												cnt[c][j][k][s][r] = Nlimit;
											}
										}
										else if (cnt[c - ps[i].cost][j - 1][k][s][r] && sumdp[c][j][k][s][r] < sumdp[c - ps[i].cost][j - 1][k][s][r] + ps[i].val)
										{
											cnt[c][j][k][s][r] = cnt[c - ps[i].cost][j - 1][k][s][r];
											sumdp[c][j][k][s][r] = sumdp[c - ps[i].cost][j - 1][k][s][r] + ps[i].val;
										}
									}
									else if (ps[i].type == 2 && k)
									{
										if (cnt[c - ps[i].cost][j][k - 1][s][r] && sumdp[c][j][k][s][r] == sumdp[c - ps[i].cost][j][k - 1][s][r] + ps[i].val)
										{
											cnt[c][j][k][s][r] += cnt[c - ps[i].cost][j][k - 1][s][r];
											if (cnt[c][j][k][s][r] > Nlimit)
											{
												cnt[c][j][k][s][r] = Nlimit;
											}
										}
										else if (cnt[c - ps[i].cost][j][k - 1][s][r] && sumdp[c][j][k][s][r] < sumdp[c - ps[i].cost][j][k - 1][s][r] + ps[i].val)
										{
											cnt[c][j][k][s][r] = cnt[c - ps[i].cost][j][k - 1][s][r];
											sumdp[c][j][k][s][r] = sumdp[c - ps[i].cost][j][k - 1][s][r] + ps[i].val;
										}
									}
									else if (ps[i].type == 3 && s)
									{
										if (cnt[c - ps[i].cost][j][k][s - 1][r] && sumdp[c][j][k][s][r] == sumdp[c - ps[i].cost][j][k][s - 1][r] + ps[i].val)
										{
											cnt[c][j][k][s][r] += cnt[c - ps[i].cost][j][k][s - 1][r];
											if (cnt[c][j][k][s][r] > Nlimit)
											{
												cnt[c][j][k][s][r] = Nlimit;
											}
										}
										else if (cnt[c - ps[i].cost][j][k][s - 1][r] && sumdp[c][j][k][s][r] < sumdp[c - ps[i].cost][j][k][s - 1][r] + ps[i].val)
										{
											cnt[c][j][k][s][r] = cnt[c - ps[i].cost][j][k][s - 1][r];
											sumdp[c][j][k][s][r] = sumdp[c - ps[i].cost][j][k][s - 1][r] + ps[i].val;
										}
									}
									else if (ps[i].type == 4 && r)
									{
										if (cnt[c - ps[i].cost][j][k][s][r - 1] && sumdp[c][j][k][s][r] == sumdp[c - ps[i].cost][j][k][s][r - 1] + ps[i].val)
										{
											cnt[c][j][k][s][r] += cnt[c - ps[i].cost][j][k][s][r - 1];
											if (cnt[c][j][k][s][r] > Nlimit)
											{
												cnt[c][j][k][s][r] = Nlimit;
											}
										}
										else if (cnt[c - ps[i].cost][j][k][s][r - 1] && sumdp[c][j][k][s][r] < sumdp[c - ps[i].cost][j][k][s][r - 1] + ps[i].val)
										{
											cnt[c][j][k][s][r] = cnt[c - ps[i].cost][j][k][s][r - 1];
											sumdp[c][j][k][s][r] = sumdp[c - ps[i].cost][j][k][s][r - 1] + ps[i].val;
										}
									}
									int tc = c - ps[i].cost;
									if (cnt[tc][tj][tk][ts][tr] && sumdp[c][j][k][s][r] == sumdp[tc][tj][tk][ts][tr] + ps[i].val)
									{
										cnt[c][j][k][s][r] += cnt[tc][tj][tk][ts][tr];
										if (cnt[c][j][k][s][r] > Nlimit)
										{
											cnt[c][j][k][s][r] = Nlimit;
										}
									}
									else if (cnt[tc][tj][tk][ts][tr] && sumdp[c][j][k][s][r] < sumdp[tc][tj][tk][ts][tr] + ps[i].val)
									{
										cnt[c][j][k][s][r] = cnt[tc][tj][tk][ts][tr];
										sumdp[c][j][k][s][r] = sumdp[tc][tj][tk][ts][tr] + ps[i].val;
									}
									*/
								}
							}
						}
					}
				}
			}
			int anssum = 0, anscost = inf, ansn = 0;
			for (int c = 0; c <= budget; c++)
			for (int k = 3; k <= 5; k++)
			{
				for (int s = 2; s <= 5; s++)
				{
					for (int r = 1; r <= 3; r++)
					{
						if (1 + k + s + r == 11 && cnt[c][1][k][s][r])
						{
							if (anssum < sumdp[c][1][k][s][r])
							{
								anscost = c;
								anssum = sumdp[c][1][k][s][r];
								ansn = cnt[c][1][k][s][r];
							}
							else if (anssum == sumdp[c][1][k][s][r])
							{
								if (c < anscost)
								{
									anscost = c;
									ansn = cnt[c][1][k][s][r];
								}
								else if (c == anscost)
								{
									ansn += cnt[c][1][k][s][r];
									ansn = min(Nlimit, ansn);
								}
							}
						}
					}
				}
			}
			printf("%d %d %d\n", anssum, anscost, ansn);
		}
	}
}
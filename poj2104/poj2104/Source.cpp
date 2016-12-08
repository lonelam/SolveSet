#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100005, maxm = 5005;
const int B = 1000;
int N, M;
int A[maxn];
int I[maxm], J[maxm], K[maxm];
int nums[maxn];
vector<int> bucket[maxn / B];
void solve()
{
	for (int i = 0; i < N; i++)
	{
		bucket[i / B].push_back(A[i]);
		nums[i] = A[i];
	}
	sort(nums, nums + N);
	//bucket - insider sort
	for (int i = 0; i < N / B; i++) sort(bucket[i].begin(), bucket[i].end());
	for(int i = 0; i < M; i++)
	{
		int l = I[i], r = J[i] + 1, k = K[i];
		int lb = 0, ub = N ;
		while (ub - lb > 1)
		{
			int md = (lb + ub) / 2;
			int x = nums[md];
			int tl = l, tr = r, c = 0;
			//naive count
			while (tl < tr && tl % B != 0) if (A[tl++] <= x)
			{
				c++;
			}
			while (tl < tr && tr % B != 0) if (A[--tr] <= x)
			{
				c++;
			}
			while (tl < tr)
			{
				int b = tl / B;
				c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
				tl += B;
			}
			if (c >= k)
			{
				ub = md;
			}
			else
			{
				lb = md;
			}
		}
		printf("%d\n", nums[lb]);
	}
}
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", A + i);
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d%d", I + i, J + i, K + i);
	}
	solve();
}

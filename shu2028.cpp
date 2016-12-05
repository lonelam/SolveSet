#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 2000;
typedef long long ll;
ll M[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll T;
	ll B, N;
	while(scanf("%lld", &T)!= EOF)
	{
		while(T--)
		{
			scanf("%lld%lld", &B, &N);
	//		cin >> B >> N;
			ll m = 1e6;
			for (int i =0 ; i < B; i++)
			{
				scanf("%lld", M + i);
				//cin >> M[i];
				//m = min(M[i], m);
			}
			ll l = 0, r = m * N;
			while(l < r)
			{
				int mid = l + (r - l) / 2;
				int sum = 0;
				for (int i = 0; i < B; i++)
				{
					sum += (mid / M[i]) + 1;
				}
				if (sum < N)
				{
					l = mid + 1;
				}
				else
				{
					r = mid;
				}
			}
			l--;
			//cout << "debug l : " << l << endl;
			int cnt = 0;
			for (int i = 0; i < B; i++)
			{
				cnt += l / M[i] + 1;
			}
			cnt = N - cnt;
			//cout << " debug  " << cnt <<endl;

		    l++;

			//cout <<"debug  " << l << endl;
			int ans;
			for (int i = 0; i < B; i++)
			{
				if (l % M[i] == 0 && (--cnt) == 0)
				{
					ans = i;
					break;
				}
			}
		//	cout << ans + 1 << endl;
			printf("%d\n", ans + 1);
		}
	}
}

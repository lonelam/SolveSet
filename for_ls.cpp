#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int, int> PII;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;

int prime_cnt = 0;
int vis[N];
ull prime[N];
ull ans[N];
void f()
{
	CLR(vis, 0);
	for (ull i = 2; i < N; i++)
	{
		if (!vis[i])
		{
			prime[prime_cnt++] = i;
			for (int j = 2; j * i < N ; j++)
				vis[i * j] = 1;
		}
	}
}

int main()
{
	ull l, r;
	f();
  cout << prime_cnt << endl;
  cout << prime[prime_cnt - 1] << endl;
	while (cin >> l >> r)
	{
		CLR(vis, 0);
		for (int i = 0 ; i < prime_cnt; i++)
		{
			ull j = l / prime[i];
			if (l % prime[i])
				j ++;
			if (j * prime[i] > r)
				break;
			if (j == 1)
				j++;
			for (; j * prime[i] <= r; j++)
			{
				vis[j * prime[i] - l] = 1;
			}
		}
		int Min_dis = INF, Max_dis = 0;
		pair<ll, ll> Min_num, Max_num;
		int ans_cnt = 0;
		for (ull i = l ; i <= r ; i ++)
		{
			if (i == 1)
				continue;
			if (!vis[i - l])
				ans[ans_cnt++] = i;
		}
		for (int i = 1; i < ans_cnt; i++)
		{
			if (ans[i - 1] < l)
				continue;
			if (ans[i] > r)
				break;
			int dis = ans[i] - ans[i - 1];
			if (dis > Max_dis)
				Max_num = mp(ans[i - 1], ans[i]), Max_dis = dis;
			if (dis < Min_dis)
				Min_num = mp(ans[i - 1], ans[i]), Min_dis = dis;
		}
		if (Max_dis != 0)
			cout << Min_num.first << "," << Min_num.second << " are closest, " << Max_num.first << "," <<  Max_num.second << " are most distant." << endl;
		else
			printf("There are no adjacent primes.\n");
	}
}

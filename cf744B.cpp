#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 50;
int ans[maxn];

vector<int> layq[20];
int buf[maxn];
int n;
const int inf = 0x3f3f3f3f;
void div(int l, int r, int d)
{
	const int mid = (l + r + 1) / 2;
	int llen = mid - l;
	int rlen = r - mid;
	if (llen > 0)
	{
	//	cout << llen << endl;
		for (int i = l; i < mid; i++)
		{
			layq[d].push_back(i + 1);
		//	cout << i+ 1 <<((i != mid - 1)?" ":"\n");
		}
		if (llen > 1)
		div(l, mid, d + 2);
	}

	if (rlen > 0)
	{
	//	cout << rlen << endl;
		for (int i = mid; i < r; i++)
		{
			layq[d + 1].push_back(i + 1);
		//	cout << i+ 1 <<((i != r - 1)?" ":"\n");
		}
		if (rlen > 1)
		div(mid, r, d + 2);
	}
}
int main()
{

	cin >> n;
	memset(ans, inf, sizeof(ans));
	div(0, n, 0);
	for (int i = 0; i < 20; i++)
	{
		if (layq[i].empty())
		break;
		cout << layq[i].size() << endl;
		for (int j = 0; j < layq[i].size(); j++)
		{
			cout << layq[i][j] << (j != (layq[i].size() - 1) ? " " : "\n");
		}
		for (int j = 0; j < n; j++)
		{
			cin >> buf[j];
			auto lb = lower_bound(layq[i].begin(), layq[i].end(), j + 1);
			if (lb == layq[i].end() || *lb != j + 1)
			{
				ans[j] = min(ans[j], buf[j]);
			}
		}
	}
	cout << "-1"<<endl;
	fflush(stdout);
	
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] <<((i != n - 1)?" ":"\n");
	}

}
/*
0       5 6 7
X ? ? 2 2 2 
? X ? 2 2 2 
? ? X 2 2 2 
1 1 1 X ? ? 
1 1 1 ? X ? 
1 1 1 ? ? X 

*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 50;
int ans[maxn];
int layerq[maxn][maxn]; 
int buf[maxn];
int n;
const int inf = 0x3f3f3f3f;
void div(int l, int r, int u, int d)
{
	const int mid = (l + r + 1) / 2;
	int llen = mid - l;
	int rlen = r - mid;
	if (llen > 0)
	{
		cout << llen << endl;
		for (int i = l; i < mid; i++)
		{
			cout << i+ 1 <<((i != mid - 1)?" ":"\n");
		}
		for (int i = 0; i < n; i++)
		{
			cin >> buf[i];
		}
		for (int i = mid; i < r; i++)
		{
			ans[i] = min(ans[i], buf[i]);
		}
		if (llen > 1)
		div(l, mid, l, mid);
	}

	if (rlen > 0)
	{
		cout << rlen << endl;
		for (int i = mid; i < r; i++)
		{
			cout << i+ 1 <<((i != r - 1)?" ":"\n");
		}
		for (int i = 0; i < n; i++)
		{
			cin >> buf[i];
		}
		for (int i = l; i < mid; i++)
		{
			ans[i] = min(ans[i], buf[i]);
		}
		if (rlen > 1)
		div(mid, r, mid, r);
	}
}
int main()
{

	cin >> n;
	memset(ans, inf, sizeof(ans));
	div(0, n, 0, n);
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

#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100100;
int l[maxn], r[maxn];
int main()
{
	int n;
	while(cin >> n)
	{
		int lp = 0, rp = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> l[i] >> r[i];
			lp +=l[i] - r[i];
		}
		rp = -lp;
		int ans = 0;
		int mb = max(rp, lp);
		for (int i = 0; i < n; i++)
		{
			if ( lp + (r[i] - l[i]) * 2 > mb || rp + (l[i] - r[i]) * 2 > mb)
			{
				mb = max(lp + (r[i] - l[i]) * 2, rp + (l[i] - r[i]) * 2) ;
			    ans = i;
			}
		}
	    cout << ans + 1 << endl;
	}
}

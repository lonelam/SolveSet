#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 200000 + 100;
ll sum[maxn];
ll a[maxn];
int sz;
void init()
{
	memset(sum, 0, sizeof(sum));
}
void add(int xx, ll adder)
{
	while (xx <= sz)
	{
		sum[xx] += adder;
		//  cout << sum[xx] << endl;
		xx += xx & (-xx);
	}
}
ll query(int xx)
{
	ll ans = 0;
	while (xx)
	{
		ans += sum[xx];
		xx -= xx & (-xx);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	sz = n + 1;
	ll eex = 0;
	for (int i = 1; i <= n; i++)
	{
		eex += (ll)(i - 1) * i * (n - i + 1)/ 2;
	}
	ld expected = (ld)eex / 2;
	init();
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	ll tot = 0;
	//reverse(a + 1, a + n +1);
	for (int i = n; i >= 1; i--)
	{
		tot += query(a[i]);
		add(a[i], 1);
	}
	// cout << tot <<endl;
	init();
	ll seg = 0;
	for (int i = n; i >= 1; i--)
	{
		seg += query(a[i]) * i;
		add(a[i], n - i + 1);
	}
	ld ans = (expected - seg) / n / (n + 1) * 2;
	ans += (ld)tot;
	cout << fixed << setprecision(30) << ans << endl;
}


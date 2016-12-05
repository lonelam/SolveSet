#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int M, N;
const int maxm = 105;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
int X1[maxm], Y1[maxm];

int X2[maxn], Z2[maxn];

double width(int * xs, int * ys, int n, double x)
{
	double lb = inf, ub = -inf;
	for (int i = 0; i < n; i++)
	{
		double x1 = xs[i], y1 = ys[i], x2 = xs[(i + 1) % n], y2 = ys[(i + 1) % n];
		if ((x1 - x) * (x2 - x) <= 0 && x1 != x2)
		{
			double y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
			lb = min(lb, y);
			ub = max(ub, y);
		}
	}
	return max(0.0, ub - lb);
}

void solve()
{
	int min1 = *min_element(X1, X1 + M), max1 = *max_element(X1, X1 + M);
	int min2 = *min_element(X2, X2 + N), max2 = *max_element(X2, X2 + N);
	vector<int> xs;
	for (int i = 0; i < M; i++)
	{
		xs.push_back(X1[i]);
	}
	for (int i = 0; i < N; i++)
	{
		xs.push_back(X2[i]);
	}
	sort(xs.begin(), xs.end());

	double res = 0;
	for (int i = 0; i + 1 < xs.size(); i++)
	{
		double a = xs[i], b = xs[i + 1], c = (a + b) / 2;
		if (min1 <= c && c <= max1 && min2 <= c && c <= max2)
		{
			double fa = width(X1, Y1, M, a) * width(X2, Z2, N, a);
			double fb = width(X1, Y1, M, b) * width(X2, Z2, N, b);
			double fc = width(X1, Y1, M, c) * width(X2, Z2, N, c);
			res += (b - a) / 6 * (fa + 4 * fc + fb);
		}
	}
	
	cout << res << endl;
}

int main()
{
	cout.setf(ios::fixed);
	while (cin >> M >> N && M && N)
	{
		for (int i = 0; i < M; i++)
		{
			cin >> X1[i] >> Y1[i];
		}
		for (int i = 0; i < N; i++)
		{
			cin >> X2[i] >> Z2[i];
		}
		solve();
	}
}
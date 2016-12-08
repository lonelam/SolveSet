#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
using namespace std;


int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int W, H, N;
const int maxn = 1000;
int X1[maxn], X2[maxn], Y1[maxn], Y2[maxn];
bool fld[maxn * 6][maxn * 6];
int compress(int  * x1, int *x2, int w)
{
	vector<int>  xs;
	for (int i = 0; i < N; i++)
	{
		for (int d = -1; d <= 1; d++)
		{
			int tx1 = x1[i] + d, tx2 = x2[i] + d;
			//only those lines occupied will be recorded.
			if (1 <= tx1 &&  tx1 <= W)
			{
				xs.push_back(tx1);
			}
			if (1 <= tx2 && tx2 <= W)
			{
				xs.push_back(tx2);
			}
		}
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end(), xs.end()));
	for (int i = 0; i < N; i++)
	{
		x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
		x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
	}
	return xs.size();
}

void solve()
{
	W = compress(X1, X2, W);
	H = compress(Y1, Y2, H);
	memset(fld, 0, sizeof(fld));
	for (int i = 0; i < N; i++)
	{
		for (int y = Y1[i]; y < Y2[i]; y++)
		{
			for (int x = X1[i]; x < X2[i]; x++)
			{
				fld[y][x] = true;
			}
		}
	}
	int ans = 0;
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			if (fld[y][x])
				continue;
			ans++;
			queue<pair<int, int> > que;
			que.push(make_pair(x, y));
			while (!que.empty())
			{
				pair<int,int> ss = que.front();
				int sx = ss.first, sy = ss.second;
				que.pop();
				for (int i = 0; i < 4; i++)
				{
					int tx = sx + dx[i], ty = sy + dy[i];
					if (tx < 0 || W <= tx || ty < 0 || H <= ty)
					{
						continue;
					}
					if (fld[ty][tx])
						continue;
					que.push(make_pair(tx, ty));
					fld[ty][tx] = true;
				}
			}
		}
	}
}
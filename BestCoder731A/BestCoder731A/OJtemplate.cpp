#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
const int _K = 50268147, _B = 6082187, _P = 100000007;
int _X;
inline int get_rand(int _l, int _r) {
	_X = ((long long)_K*_X + _B) % _P;
	return _X % (_r - _l + 1) + _l;
}
int n, m, k, seed;
int x[1000006], y[1000006];
bool visx[1000006], visy[1000006];;
void Init() {
	scanf("%d%d%d%d", &n, &m, &k, &seed);
	_X = seed;
	for (int i = 1; i <= k; ++i)
		x[i] = get_rand(1, n),
		y[i] = get_rand(1, m);
}
int main()
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			Init();
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			for (int i = 1; i <= k; i++)
			{
				if (!visx[x[i]])
				{
					visx[x[i]] = true;
					n--;
				}
				if (!visy[y[i]])
				{
					visy[y[i]] = true;
					m--;
				}
			}
			printf("%d %d\n", n , m);
		}
	}
	return 0;
}
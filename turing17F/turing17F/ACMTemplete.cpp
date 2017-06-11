#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int SIZE = 100;
int MOD = 1000000007;
struct Mat
{
	long long int v[SIZE][SIZE];   // value of matrix
	Mat()
	{
		memset(v, 0, sizeof(v));
	};
	void init(int a)
	{
		for (int i = 0; i<SIZE; i++)
			v[i][i] = a;
	}
};

Mat operator * (Mat & a, Mat & b) {
	Mat c;
	for (int i = 0; i<SIZE; i++)
		for (int j = 0; j<SIZE; j++)
			for (int k = 0; k<SIZE; k++)
				c.v[i][j] = (c.v[i][j] + (a.v[i][k] * b.v[k][j])) % MOD;
	return c;
}

Mat operator ^ (Mat a, long long k) {
	Mat c;
	c.init(1);
	while (k)
	{
		if (k & 1)
			c = a * c;
		a = a*a;
		k >>= 1;
	}
	return c;
}

int f[110];

int main()
{
	int n;
	long long k;
	while (scanf("%d%lld", &n, &k) != EOF)
	{
		Mat a;
		for (int i = 0; i<n; i++)
			scanf("%d", &f[n - 1 - i]);
		for (int i = 0; i<n; i++)
			scanf("%lld", &a.v[i][0]);
		for (int i = 0; i<n - 1; i++)
			a.v[i][i + 1] = 1;
		a = a ^ (k - n);
		long long ans = 0;
		for (int i = 0; i<n; i++)
			ans = (ans + (a.v[i][0] * f[i]) % MOD + MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int n;
	while (~scanf("%d", &n))
	{
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if (x & 1) ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}



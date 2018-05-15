
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cmath>

const int maxn = 100000 + 10;
int n, m, t;
typedef long long ll;
ll p, q, b;
using namespace std;
int main() {
	while (~scanf("%d", &n)) {
		for (int k = 0; k < n; k++) {

			scanf("%I64d%I64d%I64d", &p, &q, &b);

			p %= q;
			if (p == 0LL) {
				puts("Finite");
				continue;
			}
			ll g = __gcd(p, q);
			p /= g;
			q /= g;
			while ((g = __gcd(q, b)) != 1LL && g != 0) {
				while(q % g == 0) q /= g;
			}
			if (q == 1) {
				puts("Finite");
			}
			else {
				puts("Infinite");
			}
		}
	}
}

#define _CRT_SECURE_NO_WARNINGS
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
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	while (~scanf("%d", &n)) {
		for (int k = 0; k < n; k++) {

			scanf("%I64d%I64d%I64d", &p, &q, &b);
			
			p -= p / q * q;
			if (p == 0LL) {
				puts("Finite");
				continue;
			}
			ll g = gcd(p, q);
			p /= g;
			q /= g;
			while ((g = gcd(q, b)) != 1LL) {
				q /= g;
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
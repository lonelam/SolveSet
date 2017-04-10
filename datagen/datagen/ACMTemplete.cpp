#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <random>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
typedef long long ll;
typedef long double ld;
int A[maxn];
int main()
{
	string path = "C:\\Users\\51433\\Desktop\\";
	int tfile = 6;
	for (int koi = 0; koi < tfile; koi++)
	{
		freopen((path + char(koi + '0') + ".in").c_str(), "w", stdout);
		//int T = 100, N = 1000;
		random_device rd;
		uniform_int_distribution<long long> dis(2, 2e9), disx(1, 10000),dism(0, 10000);
		ll n = dis(rd);
		//int m = dism(rd);
		cout << n << endl;
		
	}
	

}
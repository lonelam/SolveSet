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
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;

int a[1005];
int temp[1005];
int n;
int ans;
int b[1005];
bool ok()
{
	for (int i = 1; i<n; ++i)if (a[i]<a[i - 1])return false;
	return true;
}

bool same() {
	for (int i = 0; i<n; ++i)if (a[i] != b[i])return false;
	return true;
}

void reverse(int i, int j) {

	int c = 0;
	for (int k = i; k <= j; ++k) {
		b[c++] = a[k];
	}
	c--;
	for (int k = i; k <= j; ++k)a[k] = b[c--];
}
void debug()
{
	for (int i = 0; i<n; ++i)cout << a[i] << ' ';

	cout << endl;
}
void operat() {
	int i;
	for (i = n - 1; i >= 0; --i) {
		if (temp[i] != a[i])break;
	}
	int s = temp[i];
	int pos2;
	for (int j = 0; j<i; ++j)if (a[j] == s)pos2 = j;
	for (int j = 0; j<n; ++j)b[j] = a[j];
	reverse(0, pos2);
	if (!same())ans++;
	for (int j = 0; j<n; ++j)b[j] = a[j];
	reverse(0, i);
	if (!same())ans++;

}



int main()
{
	//freopen("turnPie.in","r",stdin);

	while (cin >> n) {
		//cout<<n<<endl;
		for (int i = 0; i<n; ++i) {
			cin >> a[i];
			temp[i] = a[i];
		}
		sort(temp, temp + n);
		ans = 0;
		while (!ok()) {
			operat();

		}
		cout << ans << endl;
	}
	return 0;
}
/**************************************************************
Problem: 2103
User: 14122931
Language: C++
Result: Accepted
Time:0 ms
Memory:1576 kb
****************************************************************/
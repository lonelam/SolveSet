#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <random>
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
typedef pair<int, int> pii;
struct node
{
	int value;
	int next;
	int id;
};

int main()
{
	random_device rd;
	int n;
	int start, x;
	scanf("%d%d%d", &n, &start, &x);
		set<int> st;
		map<int, node> table;
		uniform_int_distribution<int> ui(1, n);
		for (int i = 0; i < 999 && st.size() < n; i++)
		{
			int q = ui(rd);
			while (st.find(q) != st.end())
			{
				q = ui(rd);
			}
			printf("? %d\n", q);
			fflush(stdout);
			int tval, tnex;
			node tnode;
			tnode.id = q;
			scanf("%d%d", &tnode.value, &tnode.next);
			st.insert(q);
			table[tnode.value] = tnode;
		}
		auto start_point = table.upper_bound(x);
		node p;
		if (start_point == table.begin())
		{
			printf("? %d\n", start);
			fflush(stdout);
			p.id = start;
			scanf("%d%d", &p.value, &p.next);
		}
		else
		{
			start_point--;
			p = start_point->second;
		}
		while (p.value < x)
		{
			if (p.next == -1)
			{
				printf("! %d\n", -1);
				fflush(stdout);
				return 0;
			}
			node tp;
			tp.id = p.next;
			printf("? %d\n", tp.id);
			fflush(stdout);
			scanf("%d%d", &tp.value, &tp.next);
			p = tp;
		}
		printf("! %d\n", p.value);
		fflush(stdout);
}
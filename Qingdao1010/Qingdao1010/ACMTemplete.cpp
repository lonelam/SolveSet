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
int T;
int L[maxn], R[maxn];
int A[maxn];
bool del[maxn];
int n;
set<int>*cur, *nex;
int main()
{
	scanf("%d", &T);
	cur = new set<int>();
	nex = new set<int>();
	while (T--)
	{
		scanf("%d", &n);
		memset(del, 0, sizeof(del));
		cur->clear();
		nex->clear();
		int cnt = n;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", A + i);
		}
		
		for (int i = 0; i < n; i++)
		{
			L[i] = i ? (i - 1) : -1;
			R[i] = (i == n - 1) ? (-1) : i+1;
			cur->insert(i);
		}
		while (!cur->empty())
		{
			vector<int> to_do;
			for (int t : *cur)
			{
				if (del[t]) continue;
				if ((L[t] != -1 && A[L[t]] > A[t]) || (R[t] != -1 && A[t] > A[R[t]]))
				{
					to_do.push_back(t);
					//L[R[t]] = L[t];
					//R[L[t]] = R[t];
					if (L[t] != -1 && !del[L[t]]) nex->insert(L[t]);
					if (R[t] != -1 && !del[R[t]]) nex->insert(R[t]);
					del[t] = true;
					cnt--;
				}
			}
			for (int t : to_do)
			{
				if (L[t] != -1) R[L[t]] = R[t];
				if (R[t] != -1) L[R[t]] = L[t];
			}
			swap(cur, nex);
			nex->clear();
		}
		int head = -1;
		for (int i = 0; i < n; i++)
		{
			if (!del[i])
			{
				head = i;
				break;
			}
		}
		printf("%d\n", cnt);
		//if (!cnt) printf("\n");
		while (head != -1)
		{
			printf("%d ", A[head]);
			head = R[head];
			
		}
		printf("\n");
	}
}
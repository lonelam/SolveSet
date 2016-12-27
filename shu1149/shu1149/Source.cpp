#include <iostream>
#include <functional>
#include <queue>
using namespace std;

struct node
{
	int r;
	node * left, *right;
};
const int maxn = 1000;
node ns[maxn];
typedef pair<int, int> pii;
int main()
{
	int N;
	while (cin >> N)
	{
		priority_queue<pii, vector<pii>, greater<pii> > Q;
		for (int i = 0; i < N; i++)
		{
			cin >> ns[i].r;
			Q.push({ ns[i].r, i });
			ns[i].left = ns + (i + N - 1) % N;
			ns[i].right = ns + (i + 1) % N;
		}
		int sum = 0;
		while (Q.size() > 1)
		{
			int po = Q.top().second;
			sum += ns[po].left->r * ns[po].right->r * Q.top().first;
			ns[po].right->left = ns[po].left;
			ns[po].left->right = ns[po].right;
			Q.pop();
		}
		cout << sum << endl;
	}
}
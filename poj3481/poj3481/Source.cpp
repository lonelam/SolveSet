#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int main()
{
	ios::sync_with_stdio(false);
	multiset<pii> Q;

	int cmd;
	while (cin >> cmd && cmd)
	{
		if (cmd == 2)
		{
			if (Q.empty())
			{
				cout << 0 << endl;
			}
			else
			{
				cout << Q.rbegin()->second << endl;
				Q.erase(*Q.rbegin());
			}
		}
		else if (cmd == 3)
		{
			if (Q.empty())
			{
				cout << 0 << endl;
			}
			else
			{
				cout << Q.begin()->second << endl;
				Q.erase(Q.begin());
			}
		}
		else if (cmd == 1)
		{
			int P, K;
			cin >> K >> P;
			Q.insert(make_pair(P, K));
		}
	}
}
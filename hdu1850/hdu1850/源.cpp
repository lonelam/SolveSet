#include<iostream>
#include<set>
using namespace std;
const int maxn = 1000000;
int n[102];
int main()
{
	int m;
	while (cin >> m &&m)
	{
		int ht,nim = 0,high = 0,cnt = 0;
		for(int i = 0;i<m;i++)
		{
			cin >> n[i];
			nim ^= n[i];
		}
		if (nim == 0)
		{
			cout << 0 << endl;

		}
		else
		{
			
			for (int i = 0; i < m; i++)
			{
				nim = 0;
				for (int j = 0; j < m; j++)
				{
					if (i != j)
					{
						nim ^= n[j];
					}
				}
				if (n[i] > nim)
				{
					cnt++;
				}
			}
			cout << cnt << endl;
		}
	}
}
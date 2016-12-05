#include<iostream>
int main()
{
	using std::cin;
	using std::cout;
	int t, s, x;
	while (cin >> t >> s >> x)
	{
		if ((x>=t+s||x == t)&&((x - t) % s == 0 || (x - t - 1) % s == 0))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}
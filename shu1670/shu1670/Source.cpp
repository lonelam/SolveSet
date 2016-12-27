#include <iostream>
using namespace std;
double R, v1, v2;
const double pi = 3.1415926;
int main()
{
	while (cin >> R >> v1 >> v2)
	{
		if (v1 * pi > v2)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
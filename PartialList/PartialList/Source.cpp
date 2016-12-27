#include "LinkedList.h"
const int maxn = 100000;
int init_arr[maxn];
int main()
{
	int n, m;
	cout << "Enter size of a and b:\n";
	while (cin >> n >> m)
	{
		cout << "I have an apple: ";
		for (int i = 0; i < n; i++)
		{
			cin >> init_arr[i];
		}
		LinkedList<int> alpha(init_arr, n);
		alpha.display();
		cout << "I have a pen: ";
		for (int i = 0; i < m; i++)
		{
			cin >> init_arr[i];
		}
		LinkedList<int> beta(init_arr, m);
		beta.display();
		cout << "pineapple!  \n";
		LinkedList<int> gamma(merge(alpha, beta));
		gamma.display();
	}
}

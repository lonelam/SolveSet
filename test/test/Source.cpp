#include<iostream>
int main()
{
	int a[5][5];
	using std::cout;
	a[0][1] = 2333;
	cout << *(*a + 1) << " " << **(a + 1);
	system("pause");
}

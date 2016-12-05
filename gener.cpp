
#include<iostream>
#include<functional>
#include<ctime>
#include<random>
#include<cstdlib>
using namespace std;

int main ()
{
	srand((unsigned)time(NULL));
	int T = 1000;
	cout << T <<endl;
	for (int i = 0; i < T; i ++)
	{
		int denom = rand() % 875 + 2 ;
		int upper = rand() % (denom - 2) + 2;
		int k = rand() % 6;

		cout << upper <<" "<< denom <<" "<< k ;
		if (k)
		{
			for (int j = 0; j < k; j++)
				cout <<" " << (rand() % 875 + 2) ;
		}
		cout <<endl;
	}
}

#include<iostream>
#include<algorithm>
const int MAX_X = 100000;
const int MAX_K = 10001;
int X, K, A[MAX_K];
bool win[MAX_X + 1];
void solve()
{
	win[0] = false;
	for (int j = 1; j <= X; j++)
	{
		win[j] = false;
		for (int i = 0; i < K; i++)
		{
			win[j] |= A[i] <= j && !win[j - A[i]];
		}

	}
	if (win[X]) puts("Alice");
	else puts("Bob");
}


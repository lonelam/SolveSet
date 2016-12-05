int N, A[MAX_N];
void solve()
{
	int x = 0;
	for (int i = 0; i < N; i++)
	{
		x ^= A[i];
	}
	if (x != 0)
	{
		puts("Alice");
	}
	else
	{
		puts("Bob");
	}
}
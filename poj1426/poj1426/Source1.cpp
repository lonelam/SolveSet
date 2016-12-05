#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
int n;
long long q[9999999];
using namespace std;
void BFS()
{
	int front, rear;
	front = rear = 0;
	q[rear++] = 1;
	long long top;
	while (rear>front)
	{
		top = q[front++];
		if (top%n == 0)
			break;
		top *= 10;
		q[rear++] = top;
		q[rear++] = top + 1;
	}
	printf("%lld\n", top);
}

int main()
{
	while (scanf("%d", &n) && n)
	{
		BFS();
	}
	return 0;
}

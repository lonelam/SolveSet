
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
using namespace std;
int a, b;
int main()
{
	while (scanf("%d%d",&a,&b)!=EOF && (a || b))
	{
		bool f = true;
		for (;;)
		{
			if (a > b)
			{
				swap(a, b);
			}
				if (b%a == 0)
				{
					break;
				}
				if (b - a > a)
				{
					break;
				}
				b -= a;
				f = !f;
		}

		if (f) puts("Stan wins");
		else puts("Ollie wins");
	}
}


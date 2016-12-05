#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	int a1, a2, a3, a4;
	while (scanf("%d%d%d%d", &a1, &a2, &a3, &a4)!=EOF)
	{
		if (min(a1, a2) < max(a3, a4))
		{
			printf("-1\n");
		}
		else if (a3 == a4 && a1 == a2 && a2 == a3)
		{
			printf("-1\n");
		}
		else if (a3 == a4 && a3 == 0)
		{
			
			for (int i = 0; i < a1; i++)
			{
				printf("6");
			}
			if (a1 && a2) printf("0");
			for (int i = 0; i < a2; i++)
			{
				printf("8");
			}
			printf("\n");
		}
		else if (a3 == a4 && a3 != 0)
		{
			if (a1 >= a2)
			{
				int odd6 = a1 - a3;
				int odd8 = a2 - a3;
				for (int i = 1; i < odd6; i++)
				{
					printf("6");
				}
				for (int i = 0; i < a3; i++)
				{
					printf("68");
				}
				for (int i = 0; i < odd8; i++)
				{
					printf("8");
				}
				printf("6\n");
			}
			else
			{
				int odd6 = a1 - a3;
				int odd8 = a2 - a3;
				for (int i = 0; i < a3; i++)
				{
					printf("86");
					if (i == 0)
					{
						for (int j = 0; j < odd6; j++)
						{
							printf("6");
						}
					}
				}
				
				for (int i = 0; i < odd8; i++)
				{
					printf("8");
				}
				printf("\n");
			}
		}
		else if (a3 > a4)
		{
			int odd6 = a1 - a3;
			int odd8 = a2 - a3;
			int odd0 = max(0, a3 - a4 - 1);
			for (int i = 0; i < odd6; i++)
			{
				printf("6");
			}
			for (int i = 0; i < a3; i++)
			{
				printf("68");
				if (odd0 > 0)
				{
					odd0--;
					printf("0");
				}
			}
			for (int i = 0; i < odd8; i++)
			{
				printf("8");
			}
			printf("\n");
		}
		else if (a4 > a3)
		{
			int odd6 = a1 - a4;
			int odd8 = a2 - a4;
			int odd0 = max(0, a4 - a3 - 1);
			for (int i = 0; i < a4; i++)
			{
				if (i == 0)
				{
					if (a4 == 1)
					{
						for (int j = 0; j < odd8; j++)
						{
							printf("8");
						}
					}
					printf("8");
					for (int j = -1; j < odd6; j++)
					{
						printf("6");
					}
					continue;
				}
				if (odd0 > 0)
				{
					odd0--;
					printf("0");
				}
				if (i == a4 - 1)
				{
					for (int j = -1; j < odd8; j++)
					{
						printf("8");
					}
					printf("6");
					continue;
				}
				printf("86");
			}
			printf("\n");
			
		}
	}
}
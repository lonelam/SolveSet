#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;
char s[10];
int main()
{
	int h, m;
	char a;
	int form;
	while (scanf("%d%d%c%d", &form, &h, & a, &m) != EOF)
	{
		if (h < 0)
		{
			h = -h;
		}
		if (m < 0)
		{
			m = -m;
		}
		if (form == 12)
		{
			if (h > 12 && h % 10 == 0)
			{
				h = 10;
			}
			printf("%02d:%02d\n", h == 0 ? 1 : (h <= 12 ? h : h % 10), m < 60 ? m : m % 10);
		}
		else if(form == 24)
		{
			printf("%02d:%02d\n", h < 24 ? h : h % 20, m<60?m : m % 10);
		}
	}
}
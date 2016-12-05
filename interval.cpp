int addv[maxn];
int y1, y2;
void add(int o, int L, int R)
{
	int lc = o * 2, rc = o * 2 +1;
	if (y1 <= L && R <= y2)
	{
		addv[o] ++;
	}
	else
	{
		int M = (L + R) / 2;
		if (M >= y1) add(o * 2, L, M);
		if (M <= y2) add(o * 2 + 1, M + 1, y2);
	}
}

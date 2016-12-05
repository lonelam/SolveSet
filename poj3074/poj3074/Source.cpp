/* ***********************************************
Author        :kuangbin
横纵坐标都从1开始
外部调用dance(0)
ansd为ans数组的size
ans数组存了答案

************************************************ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MaxM = 4 * 9 * 9 + 5;
const int MaxN = 9 * 81 + 5;
const int maxnode = MaxM * MaxN;
char s[100];
//精确覆盖
struct DLX
{
	int n, m, size;
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode], Row[maxnode], Col[maxnode];
	int H[MaxN], S[MaxM];
	int ansd, ans[MaxN];
	void init(int _n, int _m)
	{
		n = _n;
		m = _m;
		for (int i = 0; i <= m; i++)
		{
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++)
			H[i] = -1;
	}
	void Link(int r, int c)
	{
		++S[Col[++size] = c];
		Row[size] = r;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if (H[r] < 0)H[r] = L[size] = R[size] = size;
		else
		{
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}
	void remove(int c)
	{
		L[R[c]] = L[c]; R[L[c]] = R[c];
		for (int i = D[c]; i != c; i = D[i])
			for (int j = R[i]; j != i; j = R[j])
			{
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				--S[Col[j]];
			}
	}
	void resume(int c)
	{
		for (int i = U[c]; i != c; i = U[i])
			for (int j = L[i]; j != i; j = L[j])
				++S[Col[U[D[j]] = D[U[j]] = j]];
		L[R[c]] = R[L[c]] = c;
	}
	//d为递归深度
	bool Dance(int d)
	{
		if (R[0] == 0)
		{
		
			ansd = d;
			return true;
		}
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
			if (S[i] < S[c])
				c = i;
		remove(c);
		for (int i = D[c]; i != c; i = D[i])
		{
			ans[d] = Row[i];
			for (int j = R[i]; j != i; j = R[j])remove(Col[j]);
			if (Dance(d + 1))return true;
			for (int j = L[i]; j != i; j = L[j])resume(Col[j]);
		}
		resume(c);
		return false;
	}
};

DLX gg;

char s2[100];
int main()
{
	while (scanf("%s", s) != EOF)
	{
		for (int i = 0; i < 81; i++)
		{
			s2[i] = '.';
		}
		s2[81] = '\0';
		if (strcmp(s, "end") == 0)
		{
			return 0;
		}
		gg.init(9*9*9, 9 *9*4);
		

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				for (int k = 1; k <= 9; k++)
				{
					if (s[i * 9 + j] != '.' && s[i * 9 + j] != '0' + k)
					{
						continue;
					}
					int choice = i * 81 + j * 9 + k;
					gg.Link(choice, i * 9 + k);
					gg.Link(choice, j * 9 + k + 81);
					gg.Link(choice, (i / 3 * 3 + j / 3)*9 + k + 162);
					gg.Link(choice, i * 9 + j + 244);
				}
				/*if (s[i * 9 + j] == '.')
				{
					continue;
				}
				int k = s[i * 9 + j] - '1';
				gg.remove(i * 9 + j + 244);
				gg.remove(i * 9 + k + 1);
				gg.remove(j * 9 + k + 82);
				gg.remove((i / 3 * 3 + j / 3)*9 + k + 163);*/
			}
		}
		gg.Dance(0);
		int d = gg.ansd;
		for (int i = 0; i < d; i++)
		{
			int x = (gg.ans[i] - 1) / 81;
			int y = (gg.ans[i] - 1) % 81 / 9;
			int k = (gg.ans[i] - 1) % 9;
			int pos = (gg.ans[i] - 1) / 9;
			
			s2[pos] = k + '1';
		}
		printf("%s\n", s2);
	}
}



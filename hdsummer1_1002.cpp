#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 20;
const int Q = 1e9 + 7;
int n, L;
const int chsize = 26;
int num[chsize][maxn], power[maxn] , sum[maxn];
bool ban[chsize];
char str[maxn];
int a[chsize];

bool cmp(int A, int B)
{
    for (int i = L - 1; i >= 0; i--)
    {
        if (num[A][i] != num[B][i])
        {
            return num[A][i] < num[B][i];
        }
    }
    return 0;
}
void work()
{
    memset(num, 0, sizeof(num));
    memset(ban, 0, sizeof(ban));
    memset(sum, 0, sizeof(sum));
    L = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        int len = strlen(str);
        if (len > 1)
        {
            ban[str[0] - 'a'] = 1;
        }
        reverse(str, str + len);
        for (int j = 0; j < len; ++j)
        {
            ++num[str[j] - 'a'][j];
            sum[str[j] - 'a'] += power[j];
            if (sum[str[j] - 'a'] >= Q)
            {
                sum[str[j]] - 'a'] -= Q;
            }
        }
        L = max(L, len);
    }
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < L; j++)
        {
            num[i][j+1] += num[i][j] / 26;
            num[i][j] %= 26;
        }
        while(num[i][L])
        {
            num[i][L+1] += num[i][L] / 26;
            num[i][L++] %= 26;
        }
        a[i] = i;
    }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int ch[maxn][2];
int seq1[maxn];
int seq2[maxn];
int pos1[maxn];
int pos2[maxn];
int par[maxn];
void gener(int L1, int R1, int L2, int R2, int p)
{
    if (L1 == R1)
    {
        return;
    }
    if (L2 == R2)
    {
        cout <<"debug"<< endl;
        return;
    }
    if (seq1[L1] == seq2[L2])
    {
        ch[p][0] = seq1[L1];
        par[seq1[L1]] = par[seq2[L2]] = p;
        gener(L1 + 1, R1, L2 + 1, R2, seq1[L1]);
    }
    else
    {
        ch[p][0] = seq1[L1];
        ch[p][1] = seq2[L2];
        par[seq1[L1]] = par[seq2[L2]] = p;
        gener(L1 + 1, pos1[seq2[L2]], pos2[seq1[L1]] + 1, R2, seq1[L1]);
        gener(pos1[seq2[L2]] + 1, R1, L2 + 1, pos2[seq1[L1]], seq2[L2]);
    }
}
int main()
{
    int T;
    int n;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", seq1 + i);
                pos1[seq1[i]] = i;
            }
            for (int i = 0; i < n; i++)
            {

                scanf("%d", seq2 + i);
                pos2[seq2[i]] = i;
            }
            gener(0, n, 0, n, 0);
            for (int i = 1; i < n; i++)
            {
                printf("%d ", par[i]);
            }
            printf("%d\n", par[n]);
        }
    }
}

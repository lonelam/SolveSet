#include <cstdio>

using namespace std;

int f[40][40];
int to_binary(int n, int B)     //B进制转二进制
{
    int ret = 0, d[40], i, j, m = 0;
    while(n > 0)
    {
        d[m++] = n % B;
        n /= B;
    }
    for(i = m-1; i >= 0; i--)
        if(d[i] > 1)
        {
            for(j = i; j >= 0; j--)
                ret |= (1<<j);
            break;
        }
        else
        {
            ret |= (d[i]<<i);
        }
    return ret;
}
int cal(int n, int K)       //不超过n的分成K个幂的数的个数
{
    int i, cnt = 0, ret = 0;
    for(i = 31; i > 0; i--)
    {
        if(n&(1<<i))
        {
            cnt++;
            if(cnt > K) break;
            n ^= (1<<i);
        }
        if(n >= (1<<(i-1)))
        {
            ret += f[i-1][K-cnt];
        }
    }
    if(cnt+n == K) ret++;
    return ret;
}
int main()
{
    int X, Y, K, B, i, j;        //f[i][j]表示高度为i的树中有j个1的路
    f[0][0] = 1, f[0][1] = 0;       //初始化
    for(i = 1; i <= 31; i++)
    {
        f[i][0] = 1;
        for(j = 1; j <= i; j++)
            f[i][j] = f[i-1][j] + f[i-1][j-1];
    }
    while(~scanf("%d%d%d%d", &X, &Y, &K, &B))
    {
        printf("%d\n", cal(to_binary(Y, B), K)-cal(to_binary(X-1, B), K));
    }
    return 0;
}

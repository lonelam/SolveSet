
/* ***********************************************
Author        :kuangbin
Created Time  :2013/8/21 19:32:35
File Name     :F:\2013ACM练习\专题学习\数学\莫比乌斯反演\HDU1695GCD.cpp
************************************************ */

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
const int MAXN = 1000000;
bool check[MAXN+10];
int prime[MAXN+10];
int mu[MAXN+10];
void Moblus()
{
    memset(check,false,sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= MAXN; i++)
    {
        if( !check[i] )
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; j++)
        {
            if(i * prime[j] > MAXN) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int a,b,c,d,k;
    Moblus();
    scanf("%d",&T);
    int iCase = 0;
    while(T--)
    {
        iCase++;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k == 0)
        {
            printf("Case %d: 0\n",iCase);
            continue;
        }
        b /= k;
        d /= k;
        if(b > d)swap(b,d);
        long long ans1 = 0;
        for(int i = 1; i <= b;i++)
            {
                cout << mu[i]*(b/i)*(d/i) <<endl;
                ans1 += (long long)mu[i]*(b/i)*(d/i);
            }
        long long ans2 = 0;
        for(int i = 1;i <= b;i++)
            ans2 += (long long)mu[i]*(b/i)*(b/i);
        ans1 -= ans2/2;
        printf("Case %d: %I64d\n",iCase,ans1);
    }
    return 0;
}

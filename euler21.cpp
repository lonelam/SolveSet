#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int d[maxn];
bool is_ami[maxn];
int ans[maxn];
void init()
{
    //nprime[1] = true;

    for (int i = 1; i < maxn; i++)
    {
        for (int j = 2; j * i < maxn; j++)
        {
            d[i * j] += i;
        }
    }
    for (int i = 1; i < maxn; i++)
    {
        //cout <<i << "  "<< d[i] << endl;
        if (d[i] < maxn && d[d[i]] == i && d[i] != i)
        {
            is_ami[i] = true;
        }
    }
    for (int i = 1; i < maxn; i++)
    {
        ans[i+1]=ans[i];
        if (is_ami[i])
        {
            //cout << i <<" "<<d[i]<< endl;
            ans[i+1]+=i;
        }
    }
}
int main()
{
    init();
    int T;
    scanf("%d", &T);
    int n;
    while(T--)
    {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
}

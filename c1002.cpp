#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        double s = 0;
        double pre = s;
        int start = 1;
        for(int i = 1; i <= n; i++)
        {
            s += 1.0 / (i * i);
            if((pre + 0.00005) / 0.0001 != (s + 0.00005)/0.0001)
            {
                printf("{%d, %.5lf} ,%lf \n",start,pre + 0.000005, s);
                start = i;
                pre = s;
            }

        }
    }
}

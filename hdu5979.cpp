#include<cstdio>
#include<cmath>

using namespace std;

const double PI = 3.1415926;

int main()
{
    int n, d;
    while(scanf("%d%d", &n, &d)!=EOF)
    {
        double S = 0;
        int theta;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &theta);
            S += d * d * sin((double)theta * PI / 180) / 2;
        }
        printf("%.3f\n", S);
    }
}

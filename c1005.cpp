#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int d, a, b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        if(a&1)
        {
            printf("Balanced\n");
        }
        else
        {
            printf("Bad\n");
        }
    }
}

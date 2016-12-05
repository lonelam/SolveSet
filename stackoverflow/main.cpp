#include<bits/stdc++.h>

using namespace std;

int test(int x)
{
    if(x == 0)
    {
        return 1;
    }
    int a[100];
    return 1 + test(x - 1);
}
int main()
{
    cout<<test(100000);
}

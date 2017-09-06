#include <bits/stdc++.h>
using namespace std;

int a[10000];
int main()
{
    for (int i = 0; i < 20; i++)
    {
        a[i] = 0;
    }
    a[0] =1;
    for (int j = 0; j < 20; j++)
    {
        cout <<a[0]%2 << " ";
        for (int i = 1; i < 20; i++)
        {
            a[i] += a[i-1];
            cout << a[i]%2 << " ";
        }
        cout << endl;
    }
}
